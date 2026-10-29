"""Catalog view of the EE image for the host link (shared by hostify.py,
gen_link_glue.py and host_link_check.py).

Everything here is derived from the repo catalogs, never from the retail
image:
  config/symbol_addrs.txt, config/data_symbol_addrs.txt  name -> EE address
  config/matches.csv        credited functions (name, address, source, status)
  config/data_matches.csv   credited data units (name, address, size, source)
  config/functions.csv      code spans
  config/data_labels.csv    code-interior labels used as data
"""
import bisect
import csv
import functools
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
TEXT_START, TEXT_END = 0x00100000, 0x00424200
DATA_END, BSS_END = 0x004C2580, 0x00634380
BSS_START = DATA_END
SCRATCHPAD = 0x70000000
ADDR_SUFFIX = re.compile(r"_([0-9A-Fa-f]{8})$")


def num(s):
    s = s.strip()
    return int(s, 16) if s.lower().startswith("0x") else int(s)


@functools.lru_cache(None)
def symbol_addrs():
    """name -> address (symbol_addrs.txt first, then data_symbol_addrs.txt)."""
    out = {}
    for f in ("config/symbol_addrs.txt", "config/data_symbol_addrs.txt"):
        for line in open(ROOT / f):
            m = re.match(r"\s*([A-Za-z_]\w*)\s*=\s*(0x[0-9a-fA-F]+)", line)
            if m:
                out.setdefault(m.group(1), int(m.group(2), 16))
    return out


def address_of(name):
    a = symbol_addrs().get(name)
    if a is None:
        m = ADDR_SUFFIX.search(name)
        a = int(m.group(1), 16) if m else None
    return a


@functools.lru_cache(None)
def matches():
    with open(ROOT / "config/matches.csv", newline="") as f:
        return {r["name"]: r for r in csv.DictReader(f)}


@functools.lru_cache(None)
def credited_at():
    """address -> name of the credited (`complete`, C source) function."""
    out = {}
    for n, r in matches().items():
        if r["status"] == "complete" and r["source"].endswith(".c"):
            out[num(r["address"])] = n
    return out


@functools.lru_cache(None)
def functions():
    with open(ROOT / "config/functions.csv", newline="") as f:
        return sorted((num(r["address"]), num(r["size"]), r["name"], r["classification"])
                      for r in csv.DictReader(f))


def function_containing(addr):
    fs = functions()
    i = bisect.bisect_right([f[0] for f in fs], addr) - 1
    if i >= 0 and fs[i][0] <= addr < fs[i][0] + fs[i][1]:
        return fs[i]
    return None


@functools.lru_cache(None)
def data_units():
    """[(address, size, name, source, progress)] sorted by address."""
    with open(ROOT / "config/data_matches.csv", newline="") as f:
        return sorted((num(r["address"]), num(r["size"]), r["name"], r["source"],
                       r.get("progress", "")) for r in csv.DictReader(f))


@functools.lru_cache(None)
def _unit_starts():
    return [u[0] for u in data_units()]


def unit_containing(addr):
    du = data_units()
    i = bisect.bisect_right(_unit_starts(), addr) - 1
    if i >= 0 and du[i][0] <= addr < du[i][0] + du[i][1]:
        return du[i]
    return None


@functools.lru_cache(None)
def unit_aliases():
    """unit name -> [(alias, offset, size)] for every catalog name that falls
    inside the unit (other than the unit itself).  The size runs to the next
    named address or the unit end."""
    by_unit = {}
    for n, a in symbol_addrs().items():
        if not (TEXT_END <= a < DATA_END):
            continue
        u = unit_containing(a)
        if u is None or n == u[2]:
            continue
        by_unit.setdefault(u, []).append((a, n))
    out = {}
    for u, lst in by_unit.items():
        lst.sort()
        cuts = sorted({a for a, _ in lst} | {u[0] + u[1]})
        res = []
        for a, n in lst:
            nxt = cuts[bisect.bisect_right(cuts, a)]
            res.append((n, a - u[0], nxt - a))
        out[u[2]] = res
    return out


@functools.lru_cache(None)
def units_by_source():
    out = {}
    for u in data_units():
        out.setdefault(u[3], []).append(u)
    return out


@functools.lru_cache(None)
def text_alt_names():
    """credited function name -> [other names at the same address]."""
    cat = credited_at()
    out = {}
    for n, a in symbol_addrs().items():
        f = cat.get(a)
        if f and n != f:
            out.setdefault(f, []).append(n)
    return {k: sorted(v) for k, v in out.items()}


@functools.lru_cache(None)
def alt_to_credited():
    return {alt: f for f, alts in text_alt_names().items() for alt in alts}


def classify_address(name, addr):
    """Coarse class of an EE address (no object knowledge)."""
    if addr is None:
        return "host"
    if addr == 0:
        return "null"
    if addr < TEXT_END:
        return "text"
    if addr < DATA_END:
        return "data"
    if addr <= BSS_END:
        return "bss"
    if SCRATCHPAD <= addr < SCRATCHPAD + 0x4000:
        return "scratchpad"
    return "outside"


HOST_LIBS = [
    # Emscripten (primary): libc, malloc, compiler-rt
    "{emsdk}/upstream/emscripten/cache/sysroot/lib/wasm32-emscripten/libc.a",
    "{emsdk}/upstream/emscripten/cache/sysroot/lib/wasm32-emscripten/libdlmalloc.a",
    "{emsdk}/upstream/emscripten/cache/sysroot/lib/wasm32-emscripten/libclang_rt.builtins.a",
    # i386 desktop: glibc, libm, libgcc
    "/usr/lib32/libc.so.6", "/usr/lib32/libm.so.6",
    "/usr/lib/gcc/x86_64-linux-gnu/13/32/libgcc.a",
]


@functools.lru_cache(None)
def host_runtime_names():
    """Names the host C library / compiler runtime defines.  A game reference
    to one of these (memcpy, sqrtf, __udivdi3, ...) is left to the host
    toolchain and never aliased onto game code or data."""
    import os
    import shutil
    import subprocess
    emsdk = os.environ.get("EMSDK", "/home/user/emsdk")
    nm = shutil.which("llvm-nm") or os.path.join(emsdk, "upstream/bin/llvm-nm")
    out = set()
    for lib in HOST_LIBS:
        p = lib.format(emsdk=emsdk)
        if not os.path.exists(p):
            continue
        flags = ["-D"] if ".so" in p else []
        r = subprocess.run([nm, "-g", "--defined-only", *flags, p],
                           capture_output=True, text=True)
        for line in r.stdout.splitlines():
            f = line.split()
            if len(f) >= 2 and f[-2] not in ("U", "w", "v"):
                out.add(f[-1].split("@")[0])
    return frozenset(n for n in out if not ADDR_SUFFIX.search(n))
