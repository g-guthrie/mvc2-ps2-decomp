#!/usr/bin/env python3
"""Rooted SH-4 control-flow mapper. Candidates still need ledger review."""
from __future__ import annotations

import argparse
import json
import pathlib
from collections import defaultdict

from core import ROOT, load, number, sha, verify_rom
from vendor.sh4dis import sh4


def sext(value, bits):
    sign = 1 << (bits - 1)
    return (value & (sign - 1)) - (value & sign)


def decode(pc, word):
    op = word >> 12
    n = (word >> 8) & 0xF
    info = {
        "kind": "other",
        "delay": False,
        "seq": True,
        "targets": [],
        "call": None,
        "jmp_reg": None,
        "jsr_reg": None,
        "lit": None,
        "lit_reg": None,
    }
    if word == 0x000B:
        info.update(kind="rts", delay=True, seq=False)
        return info
    if word == 0x002B:
        info.update(kind="rte", delay=True, seq=False)
        return info
    if (word & 0xF0FF) == 0x400B:
        info.update(kind="jsr", delay=True, jsr_reg=n)
        return info
    if (word & 0xF0FF) == 0x402B:
        info.update(kind="jmp", delay=True, seq=False, jmp_reg=n)
        return info
    if (word & 0xF0FF) == 0x0003:
        info.update(kind="bsrf", delay=True)
        return info
    if (word & 0xF0FF) == 0x0023:
        info.update(kind="braf", delay=True, seq=False)
        return info
    if op == 0xA:
        target = pc + 4 + sext(word & 0xFFF, 12) * 2
        info.update(kind="bra", delay=True, seq=False, targets=[target])
        return info
    if op == 0xB:
        target = pc + 4 + sext(word & 0xFFF, 12) * 2
        info.update(kind="bsr", delay=True, call=target)
        return info
    if (word & 0xFF00) == 0x8900:
        info.update(kind="bt", targets=[pc + 4 + sext(word & 0xFF, 8) * 2])
        return info
    if (word & 0xFF00) == 0x8B00:
        info.update(kind="bf", targets=[pc + 4 + sext(word & 0xFF, 8) * 2])
        return info
    if (word & 0xFF00) == 0x8D00:
        info.update(kind="bts", delay=True, targets=[pc + 4 + sext(word & 0xFF, 8) * 2])
        return info
    if (word & 0xFF00) == 0x8F00:
        info.update(kind="bfs", delay=True, targets=[pc + 4 + sext(word & 0xFF, 8) * 2])
        return info
    if op == 0x9:
        info["lit"] = (pc + 4 + (word & 0xFF) * 2, 2)
        return info
    if op == 0xD:
        info["lit"] = (((pc + 4) & ~3) + (word & 0xFF) * 4, 4)
        info["lit_reg"] = n
        return info
    if (word & 0xFF00) == 0xC700:
        info["lit"] = (((pc + 4) & ~3) + (word & 0xFF) * 4, 4)
        return info
    return info


def contig(addresses):
    ordered = sorted(addresses)
    if not ordered:
        return []
    runs = []
    start = end = ordered[0]
    for addr in ordered[1:]:
        if addr == end + 2:
            end = addr
        else:
            runs.append((start, end + 2))
            start = end = addr
    runs.append((start, end + 2))
    return runs


class Image:
    def __init__(self, blob, base):
        self.blob = blob
        self.base = base
        self.end = base + len(blob)

    def word(self, pc):
        if pc < self.base or pc + 2 > self.end or pc % 2:
            return None
        off = pc - self.base
        return int.from_bytes(self.blob[off:off + 2], "little")

    def u32(self, addr):
        if addr < self.base or addr + 4 > self.end:
            return None
        off = addr - self.base
        return int.from_bytes(self.blob[off:off + 4], "little")

    def contains(self, addr, size=2):
        return self.base <= addr and addr + size <= self.end


def literal_reg_target(image, pc, reg, lookback=64):
    """Last PC-relative MOV.L into reg in the preceding lookback halfwords."""
    addr = pc - 2
    steps = 0
    while steps < lookback and image.contains(addr):
        word = image.word(addr)
        if word is None:
            break
        info = decode(addr, word)
        # Indexed load into the same register replaces any earlier literal.
        if (word & 0xF00F) == 0x000E and ((word >> 8) & 0xF) == reg:
            return None
        if info.get("lit_reg") == reg and info["lit"] and info["lit"][1] == 4:
            return image.u32(info["lit"][0])
        # jsr/jmp of a different callee-saved register does not kill r8-r14.
        if info["kind"] in {"jsr", "jmp"}:
            used = info.get("jsr_reg") if info["kind"] == "jsr" else info.get("jmp_reg")
            if used == reg:
                break
            if reg < 8:
                break
            addr -= 2
            steps += 1
            continue
        if info["kind"] in {"rts", "rte", "bra", "bsr", "bt", "bf", "bts", "bfs", "braf", "bsrf"}:
            break
        addr -= 2
        steps += 1
    return None


def grow_pointer_table(image, base, cap=64):
    """Consecutive in-image even pointers starting at base. Stops at the first invalid word."""
    if base is None or base % 4 or not image.contains(base, 4):
        return [], []
    entries = []
    addr = base
    while len(entries) < cap and image.contains(addr, 4):
        value = image.u32(addr)
        if not value or value % 2 or not image.contains(value):
            break
        entries.append(value)
        addr += 4
    if len(entries) < 2:
        return [], []
    return entries, [(base, len(entries) * 4)]


def recover_indexed_tables(image, pcs):
    """Jump/call tables: MOV.L @(R0,Rm),Rn then JMP/JSR @Rn, Rm from a PC-relative MOV.L/MOVA."""
    visited = set(pcs)
    tables = []
    seeds = []
    seen_base = set()
    for pc in sorted(visited):
        word = image.word(pc)
        if word is None or (word & 0xF00F) != 0x000E:
            continue
        dest = (word >> 8) & 0xF
        table_reg = (word >> 4) & 0xF
        uses = False
        ahead = pc + 2
        for _ in range(4):
            if ahead not in visited:
                break
            nxt = image.word(ahead)
            if nxt is None:
                break
            inf = decode(ahead, nxt)
            if inf["kind"] in {"jmp", "jsr"} and (inf.get("jmp_reg") == dest or inf.get("jsr_reg") == dest):
                uses = True
                break
            ahead += 2
        if not uses:
            continue
        base = None
        back = pc - 2
        for _ in range(12):
            if back not in visited:
                break
            prev = image.word(back)
            if prev is None:
                break
            inf = decode(back, prev)
            if inf.get("lit_reg") == table_reg and inf["lit"] and inf["lit"][1] == 4:
                base = image.u32(inf["lit"][0])
                break
            if (prev & 0xFF00) == 0xC700 and table_reg == 0 and inf["lit"]:
                base = inf["lit"][0]
                break
            if inf["kind"] in {"rts", "rte", "jmp", "bra", "bsr", "jsr", "bt", "bf", "bts", "bfs"}:
                break
            back -= 2
        if base in seen_base:
            continue
        ptrs, runs = grow_pointer_table(image, base)
        if not runs:
            continue
        seen_base.add(base)
        tables.extend(runs)
        seeds.extend(ptrs)
    return tables, seeds


def recover_callback_cells(image, pcs):
    """ROM cells loaded with MOV.L @Rm then JSR/JMP @Rn; Rm from a PC-relative MOV.L."""
    visited = set(pcs)
    runs = []
    seeds = []
    seen = set()
    for pc in sorted(visited):
        word = image.word(pc)
        if word is None or (word & 0xF00F) != 0x6002:
            continue
        dest = (word >> 8) & 0xF
        ptr_reg = (word >> 4) & 0xF
        uses = False
        ahead = pc + 2
        for _ in range(4):
            if ahead not in visited:
                break
            nxt = image.word(ahead)
            if nxt is None:
                break
            inf = decode(ahead, nxt)
            if inf["kind"] in {"jmp", "jsr"} and (inf.get("jmp_reg") == dest or inf.get("jsr_reg") == dest):
                uses = True
                break
            ahead += 2
        if not uses:
            continue
        back = pc - 2
        base = None
        for _ in range(12):
            if back not in visited:
                break
            prev = image.word(back)
            if prev is None:
                break
            inf = decode(back, prev)
            if inf.get("lit_reg") == ptr_reg and inf["lit"] and inf["lit"][1] == 4:
                base = image.u32(inf["lit"][0])
                break
            if inf["kind"] in {"rts", "rte", "jmp", "bra", "bsr", "jsr", "bt", "bf", "bts", "bfs"}:
                break
            back -= 2
        if not base or base in seen or not image.contains(base, 4):
            continue
        seen.add(base)
        runs.append((base, 4))
        value = image.u32(base)
        if value and value % 2 == 0 and image.contains(value):
            seeds.append(value)
    return runs, seeds


def walk_function(image, entry, max_insns=2048):
    if not image.contains(entry) or entry % 2:
        return None
    visited = set()
    delay = set()
    terminal_delay = set()
    literals = []
    calls = []
    indirect = []
    issues = []
    braf_tables = []
    work = [entry]
    while work:
        pc = work.pop()
        if pc in visited:
            continue
        if not image.contains(pc) or pc % 2:
            issues.append(("oob", pc))
            continue
        word = image.word(pc)
        if word is None:
            issues.append(("noword", pc))
            continue
        # A word that does not encode an instruction cannot be executed, so the
        # walk has left real code. Rejection only; decoding never proves code.
        if sh4.disasm(word, pc) == "error":
            issues.append(("undecodable", pc))
            continue
        visited.add(pc)
        if len(visited) > max_insns:
            issues.append(("too_big", entry))
            break
        info = decode(pc, word)
        if pc in terminal_delay:
            info["seq"] = False
        if info["lit"]:
            literals.append((pc, info["lit"][0], info["lit"][1], info.get("lit_reg")))
        if info["delay"]:
            delay.add(pc + 2)
            if image.contains(pc + 2):
                work.append(pc + 2)
            if info["kind"] in {"rts", "rte", "jmp", "bra", "braf"}:
                terminal_delay.add(pc + 2)
        if info["kind"] in ("bt", "bf", "bts", "bfs"):
            for target in info["targets"]:
                if image.contains(target):
                    work.append(target)
                else:
                    issues.append(("branch_oob", pc, target))
        elif info["kind"] == "bra":
            target = info["targets"][0]
            if not image.contains(target):
                issues.append(("bra_oob", pc, target))
            elif target >= entry:
                work.append(target)
            else:
                calls.append(("bra_tail", pc, target))
        elif info["kind"] == "braf":
            # and #imm; shll2 r0; braf r0 — 4-byte case slots at PC+4
            back = pc - 2
            imm = None
            saw_shll2 = False
            for _ in range(6):
                if back not in visited and back not in delay:
                    prevw = image.word(back)
                else:
                    prevw = image.word(back)
                if prevw is None:
                    break
                if prevw == 0x4008:
                    saw_shll2 = True
                if (prevw & 0xFF00) == 0xC900:
                    imm = prevw & 0xFF
                    break
                back -= 2
            if saw_shll2 and imm is not None:
                slot = pc + 4
                for i in range(imm + 1):
                    tgt = slot + 4 * i
                    if image.contains(tgt) and tgt >= entry:
                        work.append(tgt)
            # mova tbl; mov.w @(r0,r1),r0; braf r0 — 16-bit offset table
            back = pc - 2
            mova = None
            saw_movw = False
            bound = None
            for _ in range(12):
                prevw = image.word(back)
                if prevw is None:
                    break
                pinf = decode(back, prevw)
                if (prevw & 0xF00F) == 0x000D and ((prevw >> 8) & 0xF) == 0:
                    saw_movw = True
                if (prevw & 0xFF00) == 0xC700 and pinf["lit"] and mova is None:
                    mova = pinf["lit"][0]
                if (prevw & 0xF00F) == 0x3002:  # cmp/hs
                    rm = (prevw >> 4) & 0xF
                    # look further for mov #imm, rm
                    b2 = back - 2
                    for _2 in range(4):
                        w2 = image.word(b2)
                        if w2 is not None and (w2 >> 12) == 0xE and ((w2 >> 8) & 0xF) == rm:
                            bound = w2 & 0xFF
                            break
                        b2 -= 2
                back -= 2
            if mova is not None and saw_movw and bound:
                addr = mova
                for i in range(bound):
                    if not image.contains(addr, 2):
                        break
                    off = image.word(addr)
                    if off >= 0x8000:
                        off -= 0x10000
                    dest = pc + 4 + off
                    if image.contains(dest) and dest % 2 == 0:
                        if dest >= entry:
                            work.append(dest)
                        calls.append(("braf", pc, dest))
                    addr += 2
                if addr > mova:
                    braf_tables.append((mova, addr - mova))
        elif info["kind"] == "bsr" and info["call"] is not None:
            calls.append(("bsr", pc, info["call"]))
        elif info["kind"] == "jsr":
            target = literal_reg_target(image, pc, info["jsr_reg"])
            if target is not None:
                calls.append(("jsr", pc, target))
            else:
                indirect.append(("jsr", pc, info["jsr_reg"]))
        elif info["kind"] == "jmp":
            target = literal_reg_target(image, pc, info["jmp_reg"])
            if target is not None:
                calls.append(("jmp", pc, target))
            else:
                indirect.append(("jmp", pc, info["jmp_reg"]))
        if info["seq"] and image.contains(pc + 2):
            work.append(pc + 2)
    code_pcs = visited | {p for p in delay if image.contains(p)}
    # Do not continue a code run into a referenced literal.
    lit_bytes = {}
    for src, addr, width, _reg in literals:
        if addr in code_pcs:
            continue
        if not image.contains(addr, width):
            issues.append(("lit_oob", src, addr))
            continue
        for off in range(width):
            lit_bytes[addr + off] = src
    code_runs = []
    for start, stop in contig(sorted(code_pcs)):
        # trim trailing bytes that are only literals and never executed
        code_runs.append((start, stop - start))
    # split literal bytes into supported contiguous runs, dropping holes
    data_runs = []
    if lit_bytes:
        ordered = sorted(lit_bytes)
        run_s = run_e = ordered[0]
        for addr in ordered[1:]:
            if addr == run_e + 1:
                run_e = addr
            else:
                data_runs.append((run_s, run_e + 1 - run_s))
                run_s = run_e = addr
        data_runs.append((run_s, run_e + 1 - run_s))
    tables, table_seeds = recover_indexed_tables(image, code_pcs)
    cells, cell_seeds = recover_callback_cells(image, code_pcs)
    tables = tables + cells + braf_tables
    table_seeds = table_seeds + cell_seeds
    table_bytes = set()
    for start, size in tables:
        data_runs.append((start, size))
        table_bytes.update(range(start, start + size))
    if table_bytes:
        code_pcs = {p for p in code_pcs if p not in table_bytes}
        code_runs = [(s, e - s) for s, e in contig(sorted(code_pcs))]
    for target in table_seeds:
        calls.append(("table", entry, target))
    return {
        "entry": entry,
        "code": code_runs,
        "data": data_runs,
        "calls": calls,
        "indirect": indirect,
        "issues": issues,
        "nins": len(visited),
        "tables": tables,
        "table_seeds": table_seeds,
    }


def looks_like_pointer_table(image, start, size):
    """True when a run reads as a table of in-image pointers rather than code.

    Table entries share the image page in their high halfword. Ordinary
    bsr/bra pairs do too, because the common `stc sr,r12` delay slot encodes
    as 0x0c02, so a run only counts as a table when its low halfwords are not
    branches or when the same pointer repeats.
    """
    if size < 16 or start % 4:
        return False
    words = []
    for pos in range(start, start + size - 3, 4):
        value = image.word(pos)
        high = image.word(pos + 2)
        if value is None or high is None:
            return False
        words.append((high << 16) | value)
    if len(words) < 4:
        return False
    pages = {}
    for value in words:
        pages[value >> 16] = pages.get(value >> 16, 0) + 1
    page, count = max(pages.items(), key=lambda kv: kv[1])
    lo = image.base >> 16
    hi = (image.base + len(image.blob)) >> 16
    if count < 4 or count < 0.8 * len(words) or not lo <= page <= hi:
        return False
    branches = sum(1 for value in words if (value & 0xF000) in (0xA000, 0xB000))
    repeated = max(words.count(value) for value in set(words))
    return branches < 0.8 * len(words) or repeated >= 4


def covered_kind(ranges, addr):
    for lo, hi, kind in ranges:
        if lo <= addr < hi:
            return kind
    return None


def merge_into(existing, start, size, kind):
    end = start + size
    for lo, hi, k in existing:
        if start < hi and lo < end and k != kind:
            return False
    return True


def map_from_roots(image, roots, existing=()):
    reviewed = [(lo, hi, k) for lo, hi, k in existing]
    pending = []
    seen = set()
    for root in roots:
        if root not in seen:
            pending.append(root)
            seen.add(root)
    functions = []
    while pending:
        entry = pending.pop(0)
        already = covered_kind(reviewed, entry) == "code"
        fn = walk_function(image, entry)
        if fn is None:
            continue
        if fn["issues"] and not already:
            continue
        if not already:
            conflict = False
            for start, size in fn["code"]:
                if not merge_into(reviewed, start, size, "code"):
                    conflict = True
                if covered_kind(reviewed, start) == "data":
                    conflict = True
                if looks_like_pointer_table(image, start, size):
                    conflict = True
            for start, size in fn["data"]:
                if not merge_into(reviewed, start, size, "data"):
                    conflict = True
                if covered_kind(reviewed, start) == "code":
                    conflict = True
            if not conflict and not fn["issues"]:
                functions.append(fn)
                for start, size in fn["code"]:
                    reviewed.append((start, start + size, "code"))
                for start, size in fn["data"]:
                    reviewed.append((start, start + size, "data"))
        else:
            extra_code = []
            extra_data = []
            for start, size in fn["code"]:
                for s, z in uncovered_slices(start, size, reviewed, "code"):
                    if merge_into(reviewed, s, z, "code"):
                        extra_code.append((s, z))
                        reviewed.append((s, s + z, "code"))
            for start, size in list(fn.get("data") or []) + list(fn.get("tables") or []):
                for s, z in uncovered_slices(start, size, reviewed, "data"):
                    if merge_into(reviewed, s, z, "data"):
                        extra_data.append((s, z))
                        reviewed.append((s, s + z, "data"))
            if extra_code or extra_data:
                functions.append({
                    "entry": entry,
                    "code": extra_code,
                    "data": extra_data,
                    "calls": fn.get("calls") or [],
                    "indirect": [],
                    "issues": [],
                    "nins": fn.get("nins") or 0,
                    "tables": extra_data,
                    "table_seeds": fn.get("table_seeds") or [],
                })
        if fn is not None:
            for _kind, _pc, target in fn["calls"]:
                if isinstance(target, int) and image.contains(target) and target not in seen:
                    seen.add(target)
                    pending.append(target)
    return functions


def load_image():
    target = load(ROOT / "config/target.json")
    main = target["main"]
    base = number(main["address"])
    blob = verify_rom(target)[number(main["rom_offset"]):number(main["rom_offset"]) + number(main["size"])]
    return Image(blob, base), target


def existing_ranges(image):
    rows = []
    for part in load(ROOT / "config/mapping.json")["ranges"]:
        lo = number(part["address"])
        rows.append((lo, lo + part["size"], part["kind"]))
    return rows


def uncovered_slices(start, size, existing, kind):
    pieces = [(start, start + size)]
    for lo, hi, k in existing:
        nxt = []
        for a, b in pieces:
            if b <= lo or a >= hi:
                nxt.append((a, b))
                continue
            if a < lo:
                nxt.append((a, lo))
            if hi < b:
                nxt.append((hi, b))
        pieces = nxt
    out = []
    for a, b in pieces:
        if b <= a:
            continue
        if kind == "code" and (a % 2 or (b - a) % 2):
            continue
        out.append((a, b - a))
    return out


def proposals_from_functions(image, functions, existing):
    seen = set()
    out = []
    claimed = list(existing)
    # A byte a walk resolved as a PC-relative literal is data, whoever else's
    # walk ran over it, so every data run is claimed before any code run.
    for fn in functions:
        for start, size in fn["data"]:
            for s, z in uncovered_slices(start, size, claimed, "data"):
                key = (s, z, "data")
                if key in seen:
                    continue
                seen.add(key)
                claimed.append((s, s + z, "data"))
                sl = image.blob[s - image.base:s - image.base + z]
                out.append({
                    "address": f"0x{s:08x}",
                    "size": z,
                    "kind": "data",
                    "sha256": sha(sl),
                    "evidence": (
                        f"PC-relative consumer or indexed pointer table in CFG of 0x{fn['entry']:08x}; "
                        f"unreferenced adjacent bytes omitted."
                    ),
                })
    for fn in functions:
        for start, size in fn["code"]:
            for s, z in uncovered_slices(start, size, claimed, "code"):
                key = (s, z, "code")
                if key in seen:
                    continue
                seen.add(key)
                claimed.append((s, s + z, "code"))
                sl = image.blob[s - image.base:s - image.base + z]
                out.append({
                    "address": f"0x{s:08x}",
                    "size": z,
                    "kind": "code",
                    "sha256": sha(sl),
                    "evidence": (
                        f"CFG walk from 0x{fn['entry']:08x}; delay slots included; "
                        f"direct BSR/JSR/JMP targets recorded; PC-relative pools split."
                    ),
                })
        for start, size in fn["data"]:
            for s, z in uncovered_slices(start, size, claimed, "data"):
                key = (s, z, "data")
                if key in seen:
                    continue
                seen.add(key)
                claimed.append((s, s + z, "data"))
                sl = image.blob[s - image.base:s - image.base + z]
                out.append({
                    "address": f"0x{s:08x}",
                    "size": z,
                    "kind": "data",
                    "sha256": sha(sl),
                    "evidence": (
                        f"PC-relative consumer or indexed pointer table in CFG of 0x{fn['entry']:08x}; "
                        f"unreferenced adjacent bytes omitted."
                    ),
                })
    out.sort(key=lambda r: int(r["address"], 16))
    return out


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--json", action="store_true")
    parser.add_argument("--roots", help="JSON file of extra candidate entry addresses to try")
    args = parser.parse_args()
    image, target = load_image()
    existing = existing_ranges(image)
    roots = [number(target["main"]["entrypoint"])]
    for lo, _hi, kind in existing:
        if kind == "code":
            roots.append(lo)
    if args.roots:
        for extra in json.loads(pathlib.Path(args.roots).read_text()):
            address = number(extra)
            if image.contains(address) and address % 2 == 0:
                roots.append(address)
    functions = map_from_roots(image, roots, existing)
    new_fn = [fn for fn in functions if fn.get("code") or fn.get("tables") or fn.get("data")]
    props = proposals_from_functions(image, functions, existing)
    code = sum(p["size"] for p in props if p["kind"] == "code")
    data = sum(p["size"] for p in props if p["kind"] == "data")
    summary = {
        "new_functions": len(new_fn),
        "new_ranges": len(props),
        "proposed_code_bytes": code,
        "proposed_data_bytes": data,
        "ranges": props,
    }
    if args.json:
        print(json.dumps(summary, indent=2))
    else:
        print(f"new functions {summary['new_functions']} ranges {summary['new_ranges']} "
              f"code {code} data {data}")


if __name__ == "__main__":
    main()
