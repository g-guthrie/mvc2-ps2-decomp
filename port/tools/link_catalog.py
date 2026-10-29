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
def host_impl():
    """port/host/host_impl.csv: functions the port implements on the host
    (name -> row with symbol, group, file, what).  The one list of host
    replacements: hostify R17 makes the credited definitions of these weak,
    gen_link_glue.py lists them in mvc2_fakes[] and writes their canonical
    prototypes to glue/mvc2_host_protos.h."""
    p = ROOT / "port/host/host_impl.csv"
    if not p.exists():
        return {}
    with open(p, newline="") as f:
        rows = [r for r in csv.DictReader(l for l in f if l.strip() and not l.startswith("#"))]
    return {r["symbol"]: r for r in rows}


WASM_TYPE = {"void": "void", "float": "f32", "double": "f64", "long long": "i64",
             "unsigned long long": "i64"}


def _load_widen():
    """port/tools/r12_widen.csv (gen_regpass.py): functions whose credited C
    declares fewer parameters than the EE passes through them (the body
    calls a callee with a missing argument that is this function's own
    incoming register, e.g. a float in $f12 forwarded to a matrix builder).
    name -> full parameter type list."""
    p = ROOT / "port/tools/r12_widen.csv"
    out = {}
    if p.exists():
        with open(p, newline="") as f:
            for r in csv.DictReader(l for l in f if l.strip() and not l.startswith("#")):
                out[r["function"]] = [x.strip() for x in r["params"].split(";") if x.strip()]
    return out


WIDEN = _load_widen()
WASM_PARAM = {"float": "f32", "double": "f64", "long long": "i64", "unsigned long long": "i64"}


def apply_host_sig_overrides(canon):
    """host_impl.csv column `ret`: the return type the host gives a function
    whose credited C says void but whose callers use $v0 (a MIPS tail call
    returns the callee's value).  Applied on top of host_sigs.json by hostify
    (R12) and gen_link_glue.py, so callers keep the value."""
    for n, r in host_impl().items():
        ret = (r.get("ret") or "").strip()
        if not ret or n not in canon:
            continue
        c = dict(canon[n])
        c["ret"] = ret
        w = c.get("wasm", "()->void")
        c["wasm"] = w[:w.rindex("->") + 2] + WASM_TYPE.get(ret, "i32")
        c["from"] = c.get("from", "") + "+host_impl.csv"
        canon[n] = c
    for n, ps in WIDEN.items():
        if n not in canon or len(ps) <= len(canon[n]["params"]):
            continue
        c = dict(canon[n])
        c["params"] = list(ps)
        w = c.get("wasm", "()->void")
        c["wasm"] = "(" + ",".join(WASM_PARAM.get(x, "i32") for x in ps) + ")" + w[w.rindex("->"):]
        c["from"] = c.get("from", "") + "+r12_widen.csv"
        c["widened"] = len(canon[n]["params"])
        canon[n] = c
    return canon


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
def code_sources():
    with open(ROOT / "config/matches.csv", newline="") as f:
        return frozenset(r["source"] for r in csv.DictReader(f))


@functools.lru_cache(None)
def layout_units():
    """Data units that are laid out on the host in EE address order: the C
    sources of config/data_matches.csv (not the 3 code TUs that also own a
    switch table).  [(address, size, name, source)] sorted by address."""
    cs = code_sources()
    return [u[:4] for u in data_units() if u[3].endswith(".c") and u[3] not in cs]


@functools.lru_cache(None)
def data_holes():
    """EE data image layout (Port J): the host links every layout unit in EE
    address order, each followed by a zero "hole" that runs to the next
    layout unit (alignment padding, data with no C, non-C units such as the
    VU microcode, code-TU switch tables), so the EE data image is one
    contiguous block and a table read past the end of its unit sees what
    the EE saw next.  -> {key: (hole_address, hole_size, [(name, offset, size)])}
    with key = unit name, or None for the hole before the first unit."""
    lu = layout_units()
    starts = [TEXT_END] + [u[0] + u[1] for u in lu]
    ends = [u[0] for u in lu] + [DATA_END]
    keys = [None] + [u[2] for u in lu]
    defined = {u[2] for u in lu}
    names = sorted((a, n) for n, a in symbol_addrs().items() if TEXT_END <= a < DATA_END)
    addrs = [a for a, _ in names]
    out = {}
    for k, lo, hi in zip(keys, starts, ends):
        if hi < lo:
            hi = lo
        i, j = bisect.bisect_left(addrs, lo), bisect.bisect_left(addrs, hi)
        inside = [(n, a) for a, n in names[i:j] if n not in defined]
        lst = []
        for q, (n, a) in enumerate(inside):
            nxt = inside[q + 1][1] if q + 1 < len(inside) and inside[q + 1][1] > a else hi
            lst.append((n, a - lo, max(nxt - a, 1)))
        out[k] = (lo, hi - lo, lst)
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
