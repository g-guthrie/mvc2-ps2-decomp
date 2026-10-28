#!/usr/bin/env python3
"""PS2 VU (micro mode) assembler / disassembler, plus VIF1/DMA packet framing.

Pure Python, no external dependencies.

A VU micro instruction is a 64-bit pair stored little-endian as two words:
the low word is the LOWER instruction, the high word the UPPER instruction.
Upper word bits 31..27 are the I/E/M/D/T flags; when I is set the lower word
is a raw 32-bit float immediate that is written to the I register (``loi``).

Source syntax (.vsm), one statement per line, ``;`` starts a comment::

    .dmatag end, 235, irq          ; DMA source-chain tag (2 words, see below)
    .vif nop                       ; VIF codes: nop stcycl offset base itop
    .vif mpg 0x100, 206            ;   stmod mskpath3 mark flushe flush flusha
    .vif unpack v4_32, 0x3ee, 2    ;   mscal mscalf mscnt stmask strow stcol
    .vif direct 4                  ;   mpg direct directhl unpack raw
    .word 0x00008000, 0x312a4000   ; raw payload words (UNPACK / DIRECT data)
    .resume_mpg 0x0e0              ; set VU pc without emitting an MPG code
    .equ L1f0, 0x1f0               ; label defined in another file / program
    L01a:                          ; label at the current VU pc
    mulx.xyzw vf1, vf2, vf3x    lq.xyz vf4, 2(vi1)
    nop[e]                      loi 0x1.8p+0

Upper and lower halves are separated by two or more spaces (or a tab).
Labels are scoped per DMA packet: every ``.dmatag`` starts a new scope.
Branch operands name labels; the encoded offset is ``target - (pc + 1)``.

CLI::

    vu_asm.py asm FILE.vsm -o OUT.bin       assemble to raw bytes
    vu_asm.py dis-raw IN.bin [--base N]     disassemble bare microcode
    vu_asm.py dis-units [--src-dir D] [--out-dir D]
                                            rebuild src/vu/*.vsm from the retail ROM
    vu_asm.py check [--src-dir D] [--vsm-dir D]
                                            round-trip every unit
"""

from __future__ import annotations

import argparse
import re
import struct
import sys
from pathlib import Path

# ---------------------------------------------------------------- fields ----

FIELDS = {
    # name: (lo bit, width)
    "dest": (21, 4),
    "ft": (16, 5),
    "fs": (11, 5),
    "fd": (6, 5),
    "imm11": (0, 11),
    "imm5": (6, 5),
    "imm24": (0, 24),
    "fsf": (21, 2),
    "ftf": (23, 2),
}
# composite immediates
#   imm15 = dest(24..21) << 11 | bits 10..0
#   imm12 = bit21 << 11 | bits 10..0


def _mask(name):
    if name == "imm15":
        return (0xF << 21) | 0x7FF
    if name == "imm12":
        return (1 << 21) | 0x7FF
    lo, w = FIELDS[name]
    return ((1 << w) - 1) << lo


def _get(word, name):
    if name == "imm15":
        return (((word >> 21) & 0xF) << 11) | (word & 0x7FF)
    if name == "imm12":
        return (((word >> 21) & 1) << 11) | (word & 0x7FF)
    lo, w = FIELDS[name]
    return (word >> lo) & ((1 << w) - 1)


def _put(name, value):
    if name == "imm15":
        if not 0 <= value < (1 << 15):
            raise ValueError(f"imm15 out of range: {value}")
        return ((value >> 11) << 21) | (value & 0x7FF)
    if name == "imm12":
        if not 0 <= value < (1 << 12):
            raise ValueError(f"imm12 out of range: {value}")
        return ((value >> 11) << 21) | (value & 0x7FF)
    lo, w = FIELDS[name]
    if not 0 <= value < (1 << w):
        raise ValueError(f"{name} out of range: {value}")
    return value << lo


# Placeholder -> (field, kind).  kind drives text formatting / parsing.
PLACEHOLDERS = {
    "vfd": ("fd", "vf"), "vfs": ("fs", "vf"), "vft": ("ft", "vf"),
    "vid": ("fd", "vi"), "vis": ("fs", "vi"), "vit": ("ft", "vi"),
    "fsf": ("fsf", "comp"), "ftf": ("ftf", "comp"),
    "simm11": ("imm11", "simm11"), "simm5": ("imm5", "simm5"),
    "imm15": ("imm15", "uimm"), "imm12": ("imm12", "uimm"),
    "imm24": ("imm24", "uimm"), "label": ("imm11", "label"),
}
COMP = "xyzw"


class Spec:
    def __init__(self, name, fixed_mask, fixed_val, template, has_dest):
        self.name = name
        self.fixed_mask = fixed_mask
        self.fixed_val = fixed_val
        self.template = template
        self.has_dest = has_dest
        self.placeholders = re.findall(r"\{(\w+)\}", template)
        used = fixed_mask
        if has_dest:
            used |= _mask("dest")
        for ph in self.placeholders:
            used |= _mask(PLACEHOLDERS[ph][0])
        self.used = used
        # build parse regex
        rx = ""
        for part in re.split(r"(\{\w+\})", template):
            m = re.fullmatch(r"\{(\w+)\}", part)
            if not m:
                rx += re.sub(r"\\ ", r"\\s*", re.escape(part)).replace(",", r"\s*,\s*")
                continue
            kind = PLACEHOLDERS[m.group(1)][1]
            rx += {
                "vf": r"vf(\d+)", "vi": r"vi(\d+)", "comp": r"([xyzw])",
                "simm11": r"([-+]?(?:0x[0-9a-fA-F]+|\d+))",
                "simm5": r"([-+]?(?:0x[0-9a-fA-F]+|\d+))",
                "uimm": r"((?:0x[0-9a-fA-F]+|\d+))",
                "label": r"([A-Za-z_.$][\w.$]*|0x[0-9a-fA-F]+|\d+)",
            }[kind]
        self.operand_rx = re.compile(r"^" + rx + r"$", re.I)


def _upper_specs():
    specs = []
    bcs = "xyzw"
    nfmt = "{vfd}, {vfs}, {vft}"
    for base, nm in ((0x00, "add"), (0x04, "sub"), (0x08, "madd"), (0x0C, "msub"),
                     (0x10, "max"), (0x14, "mini"), (0x18, "mul")):
        for i, b in enumerate(bcs):
            specs.append(Spec(nm + b, 0x3F, base + i, "{vfd}, {vfs}, {vft}" + b, True))
    for op, nm, src in ((0x1C, "mulq", "Q"), (0x1D, "maxi", "I"), (0x1E, "muli", "I"),
                        (0x1F, "minii", "I"), (0x20, "addq", "Q"), (0x21, "maddq", "Q"),
                        (0x22, "addi", "I"), (0x23, "maddi", "I"), (0x24, "subq", "Q"),
                        (0x25, "msubq", "Q"), (0x26, "subi", "I"), (0x27, "msubi", "I")):
        specs.append(Spec(nm, 0x3F, op, "{vfd}, {vfs}, " + src, True))
    for op, nm in ((0x28, "add"), (0x29, "madd"), (0x2A, "mul"), (0x2B, "max"),
                   (0x2C, "sub"), (0x2D, "msub"), (0x2E, "opmsub"), (0x2F, "mini")):
        specs.append(Spec(nm, 0x3F, op, nfmt, True))
    # special (opcode in bits 10..6 + 1..0, bits 5..2 = 1111)
    def sp(code):
        return ((code >> 2) << 6) | 0x3C | (code & 3)
    smask = 0x7FF
    for base, nm in ((0x00, "adda"), (0x04, "suba"), (0x08, "madda"), (0x0C, "msuba"),
                     (0x18, "mula")):
        for i, b in enumerate(bcs):
            specs.append(Spec(nm + b, smask, sp(base + i), "ACC, {vfs}, {vft}" + b, True))
    for i, nm in enumerate(("itof0", "itof4", "itof12", "itof15",
                            "ftoi0", "ftoi4", "ftoi12", "ftoi15")):
        specs.append(Spec(nm, smask, sp(0x10 + i), "{vft}, {vfs}", True))
    specs.append(Spec("abs", smask, sp(0x1D), "{vft}, {vfs}", True))
    specs.append(Spec("clipw", smask, sp(0x1F), "{vfs}, {vft}w", True))
    for op, nm, src in ((0x1C, "mulaq", "Q"), (0x1E, "mulai", "I"), (0x20, "addaq", "Q"),
                        (0x21, "maddaq", "Q"), (0x22, "addai", "I"), (0x23, "maddai", "I"),
                        (0x24, "subaq", "Q"), (0x25, "msubaq", "Q"), (0x26, "subai", "I"),
                        (0x27, "msubai", "I")):
        specs.append(Spec(nm, smask, sp(op), "ACC, {vfs}, " + src, True))
    for op, nm in ((0x28, "adda"), (0x29, "madda"), (0x2A, "mula"), (0x2C, "suba"),
                   (0x2D, "msuba"), (0x2E, "opmula")):
        specs.append(Spec(nm, smask, sp(op), "ACC, {vfs}, {vft}", True))
    specs.append(Spec("nop", smask, sp(0x2F), "", False))
    return specs


def _lower_specs():
    specs = []
    op7 = 0x7F << 25

    def p(code):
        return code << 25

    L = specs.append
    L(Spec("lq", op7, p(0x00), "{vft}, {simm11}({vis})", True))
    L(Spec("sq", op7, p(0x01), "{vfs}, {simm11}({vit})", True))
    L(Spec("ilw", op7, p(0x04), "{vit}, {simm11}({vis})", True))
    L(Spec("isw", op7, p(0x05), "{vit}, {simm11}({vis})", True))
    L(Spec("iaddiu", op7, p(0x08), "{vit}, {vis}, {imm15}", False))
    L(Spec("isubiu", op7, p(0x09), "{vit}, {vis}, {imm15}", False))
    m25 = op7 | (1 << 24)
    L(Spec("fceq", m25, p(0x10), "vi1, {imm24}", False))
    L(Spec("fcset", m25, p(0x11), "{imm24}", False))
    L(Spec("fcand", m25, p(0x12), "vi1, {imm24}", False))
    L(Spec("fcor", m25, p(0x13), "vi1, {imm24}", False))
    L(Spec("fseq", op7, p(0x14), "{vit}, {imm12}", False))
    L(Spec("fsset", op7, p(0x15), "{imm12}", False))
    L(Spec("fsand", op7, p(0x16), "{vit}, {imm12}", False))
    L(Spec("fsor", op7, p(0x17), "{vit}, {imm12}", False))
    L(Spec("fmeq", op7, p(0x18), "{vit}, {vis}", False))
    L(Spec("fmand", op7, p(0x1A), "{vit}, {vis}", False))
    L(Spec("fmor", op7, p(0x1B), "{vit}, {vis}", False))
    L(Spec("fcget", op7, p(0x1C), "{vit}", False))
    L(Spec("b", op7, p(0x20), "{label}", False))
    L(Spec("bal", op7, p(0x21), "{vit}, {label}", False))
    L(Spec("jr", op7, p(0x24), "{vis}", False))
    L(Spec("jalr", op7, p(0x25), "{vit}, {vis}", False))
    L(Spec("ibeq", op7, p(0x28), "{vit}, {vis}, {label}", False))
    L(Spec("ibne", op7, p(0x29), "{vit}, {vis}, {label}", False))
    L(Spec("ibltz", op7, p(0x2C), "{vis}, {label}", False))
    L(Spec("ibgtz", op7, p(0x2D), "{vis}, {label}", False))
    L(Spec("iblez", op7, p(0x2E), "{vis}, {label}", False))
    L(Spec("ibgez", op7, p(0x2F), "{vis}, {label}", False))
    m6 = op7 | 0x3F
    L(Spec("iadd", m6, p(0x40) | 0x30, "{vid}, {vis}, {vit}", False))
    L(Spec("isub", m6, p(0x40) | 0x31, "{vid}, {vis}, {vit}", False))
    L(Spec("iaddi", m6, p(0x40) | 0x32, "{vit}, {vis}, {simm5}", False))
    L(Spec("iand", m6, p(0x40) | 0x34, "{vid}, {vis}, {vit}", False))
    L(Spec("ior", m6, p(0x40) | 0x35, "{vid}, {vis}, {vit}", False))
    m11 = op7 | 0x7FF

    def s(code):
        return p(0x40) | ((code >> 2) << 6) | 0x3C | (code & 3)

    L(Spec("nop", m11 | _mask("dest") | _mask("ft") | _mask("fs"), s(0x30), "", False))
    L(Spec("move", m11, s(0x30), "{vft}, {vfs}", True))
    L(Spec("mr32", m11, s(0x31), "{vft}, {vfs}", True))
    L(Spec("lqi", m11, s(0x34), "{vft}, ({vis}++)", True))
    L(Spec("sqi", m11, s(0x35), "{vfs}, ({vit}++)", True))
    L(Spec("lqd", m11, s(0x36), "{vft}, (--{vis})", True))
    L(Spec("sqd", m11, s(0x37), "{vfs}, (--{vit})", True))
    L(Spec("div", m11, s(0x38), "Q, {vfs}{fsf}, {vft}{ftf}", False))
    L(Spec("sqrt", m11, s(0x39), "Q, {vft}{ftf}", False))
    L(Spec("rsqrt", m11, s(0x3A), "Q, {vfs}{fsf}, {vft}{ftf}", False))
    L(Spec("waitq", m11, s(0x3B), "", False))
    L(Spec("mtir", m11, s(0x3C), "{vit}, {vfs}{fsf}", False))
    L(Spec("mfir", m11, s(0x3D), "{vft}, {vis}", True))
    L(Spec("ilwr", m11, s(0x3E), "{vit}, ({vis})", True))
    L(Spec("iswr", m11, s(0x3F), "{vit}, ({vis})", True))
    L(Spec("rnext", m11, s(0x40), "{vft}, R", True))
    L(Spec("rget", m11, s(0x41), "{vft}, R", True))
    L(Spec("rinit", m11, s(0x42), "R, {vfs}{fsf}", False))
    L(Spec("rxor", m11, s(0x43), "R, {vfs}{fsf}", False))
    L(Spec("mfp", m11, s(0x64), "{vft}, P", True))
    L(Spec("xtop", m11, s(0x68), "{vit}", False))
    L(Spec("xitop", m11, s(0x69), "{vit}", False))
    L(Spec("xgkick", m11, s(0x6C), "{vis}", False))
    for code, nm in ((0x70, "esadd"), (0x71, "ersadd"), (0x72, "eleng"), (0x73, "erleng"),
                     (0x74, "eatanxy"), (0x75, "eatanxz"), (0x76, "esum")):
        L(Spec(nm, m11, s(code), "P, {vfs}", True))
    for code, nm in ((0x78, "esqrt"), (0x79, "ersqrt"), (0x7A, "ercpr"), (0x7C, "esin"),
                     (0x7D, "eatan"), (0x7E, "eexp")):
        L(Spec(nm, m11, s(code), "P, {vfs}{fsf}", False))
    L(Spec("waitp", m11, s(0x7B), "", False))
    return specs


UPPER_SPECS = _upper_specs()
LOWER_SPECS = _lower_specs()
UPPER_FLAGS = (("e", 30), ("m", 29), ("d", 28), ("t", 27))
I_BIT = 1 << 31
UPPER_OPMASK = (1 << 27) - 1   # bits 26..0 (26,25 must be zero)


def _by_name(specs):
    out = {}
    for sp in specs:
        out.setdefault(sp.name, []).append(sp)
    return out


UPPER_BY_NAME = _by_name(UPPER_SPECS)
LOWER_BY_NAME = _by_name(LOWER_SPECS)


class DecodeError(Exception):
    pass


def _sext(v, bits):
    return v - (1 << bits) if v & (1 << (bits - 1)) else v


def _dest_str(d):
    return "".join(c for i, c in enumerate(COMP) if d & (8 >> i))


def _find(specs, word):
    for sp in specs:
        if (word & sp.fixed_mask) == sp.fixed_val and (word & ~sp.used & 0xFFFFFFFF) == 0:
            return sp
    return None


def _render(sp, word, label_for=None, pc=None):
    text = sp.name
    if sp.has_dest:
        d = _get(word, "dest")
        if d:
            text += "." + _dest_str(d)
    ops = sp.template
    for ph in sp.placeholders:
        field, kind = PLACEHOLDERS[ph]
        v = _get(word, field)
        if kind in ("vf", "vi"):
            r = f"{kind}{v}"
        elif kind == "comp":
            r = COMP[v]
        elif kind == "simm11":
            r = str(_sext(v, 11))
        elif kind == "simm5":
            r = str(_sext(v, 5))
        elif kind == "uimm":
            r = hex(v)
        elif kind == "label":
            target = pc + 1 + _sext(v, 11)
            r = label_for(target) if label_for else f"0x{target:x}"
        ops = ops.replace("{" + ph + "}", r, 1)
    return text, ops


def float_text(bits):
    """Shortest decimal (or 0x bits) that round-trips exactly to float32 bits."""
    f = struct.unpack("<f", struct.pack("<I", bits))[0]
    if f != f or f in (float("inf"), float("-inf")):
        return f"0x{bits:08x}"
    for n in range(1, 10):
        t = f"{f:.{n}g}"
        if struct.unpack("<I", struct.pack("<f", float(t)))[0] == bits:
            if not re.search(r"[.eEn]", t):
                t += ".0"
            return t
    return f"0x{bits:08x}"


def parse_float_bits(text):
    text = text.strip()
    if re.fullmatch(r"0x[0-9a-fA-F]{1,8}", text):
        return int(text, 16)
    if "p" in text.lower():
        val = float.fromhex(text)
    else:
        val = float(text)
    return struct.unpack("<I", struct.pack("<f", val))[0]


def branch_target(lower, pc):
    """VU address targeted by a lower branch word at pc, else None."""
    sp = _find(LOWER_SPECS, lower)
    if sp is None or "label" not in sp.placeholders:
        return None
    return pc + 1 + _sext(lower & 0x7FF, 11)


def disasm_pair(lower, upper, pc=0, label_for=None):
    """Return (upper_text, lower_text). Raises DecodeError if not encodable."""
    usp = _find(UPPER_SPECS, upper & UPPER_OPMASK)
    if usp is None:
        raise DecodeError(f"upper 0x{upper:08x}")
    name, ops = _render(usp, upper & UPPER_OPMASK)
    flags = "".join(c for c, b in UPPER_FLAGS if upper & (1 << b))
    utext = name + (f"[{flags}]" if flags else "") + (" " + ops if ops else "")
    if upper & I_BIT:
        ltext = "loi " + float_text(lower)
    else:
        lsp = _find(LOWER_SPECS, lower)
        if lsp is None:
            raise DecodeError(f"lower 0x{lower:08x}")
        name, ops = _render(lsp, lower, label_for, pc)
        ltext = name + (" " + ops if ops else "")
    return utext, ltext


def _parse_int(t):
    return int(t, 0)


def _assemble_one(by_name, text, pc, resolve):
    text = text.strip()
    m = re.match(r"^([a-z0-9]+)(?:\.([xyzw]+))?(?:\[([emdt]*)\])?\s*(.*)$", text, re.I)
    if not m:
        raise ValueError(f"bad instruction: {text!r}")
    mnem, dest, flags, ops = m.group(1).lower(), m.group(2), m.group(3), m.group(4).strip()
    cands = by_name.get(mnem)
    if not cands:
        raise ValueError(f"unknown mnemonic: {mnem!r}")
    for sp in cands:
        if dest and not sp.has_dest:
            continue
        om = sp.operand_rx.match(ops)
        if not om:
            continue
        word = sp.fixed_val
        if dest:
            d = 0
            for c in dest.lower():
                d |= 8 >> COMP.index(c)
            word |= _put("dest", d)
        for ph, val in zip(sp.placeholders, om.groups()):
            field, kind = PLACEHOLDERS[ph]
            if kind in ("vf", "vi"):
                v = int(val)
            elif kind == "comp":
                v = COMP.index(val.lower())
            elif kind == "simm11":
                v = _parse_int(val) & 0x7FF
            elif kind == "simm5":
                v = _parse_int(val) & 0x1F
            elif kind == "uimm":
                v = _parse_int(val)
            elif kind == "label":
                off = resolve(val) - (pc + 1)
                if not -1024 <= off < 1024:
                    raise ValueError(f"branch out of range: {val}")
                v = off & 0x7FF
            word |= _put(field, v)
        return word, (flags or "")
    raise ValueError(f"operands do not match {mnem}: {ops!r}")


def assemble_pair(utext, ltext, pc=0, resolve=None):
    resolve = resolve or (lambda name: int(name, 0))
    upper, flags = _assemble_one(UPPER_BY_NAME, utext, pc, resolve)
    for c, b in UPPER_FLAGS:
        if c in flags.lower():
            upper |= 1 << b
    lt = ltext.strip()
    if lt.lower().startswith("loi "):
        return parse_float_bits(lt[4:]), upper | I_BIT
    lower, lflags = _assemble_one(LOWER_BY_NAME, lt, pc, resolve)
    if lflags:
        raise ValueError("flags belong to the upper instruction")
    return lower, upper


# ------------------------------------------------------------- VIF / DMA ----

DMA_IDS = ["refe", "cnt", "next", "ref", "refs", "call", "ret", "end"]
VIF_SIMPLE = {0x00: "nop", 0x10: "flushe", 0x11: "flush", 0x13: "flusha", 0x17: "mscnt"}
VIF_IMM = {0x02: "offset", 0x03: "base", 0x04: "itop", 0x05: "stmod", 0x06: "mskpath3",
           0x07: "mark", 0x14: "mscal", 0x15: "mscalf"}
UNPACK_FMT = ["s_32", "s_16", "s_8", None, "v2_32", "v2_16", "v2_8", None,
              "v3_32", "v3_16", "v3_8", None, "v4_32", "v4_16", "v4_8", "v4_5"]


def unpack_words(vnvl, num):
    vn, vl = vnvl >> 2, vnvl & 3
    bits = (32, 16, 8, 5)[vl] * (vn + 1)
    if vnvl == 0xF:
        bits = 16
    num = num or 256
    return (num * bits + 31) // 32


def vif_text(w):
    """Return (text, payload_words, mpg_info)."""
    irq = "[i] " if w & 0x80000000 else ""
    cmd = (w >> 24) & 0x7F
    num = (w >> 16) & 0xFF
    imm = w & 0xFFFF
    base = None
    if cmd in VIF_SIMPLE and num == 0 and imm == 0:
        base = VIF_SIMPLE[cmd], 0, None
    elif cmd in VIF_IMM and num == 0:
        base = f"{VIF_IMM[cmd]} 0x{imm:x}", 0, None
    elif cmd == 0x01 and num == 0:
        base = f"stcycl {imm & 0xFF}, {imm >> 8}", 0, None
    elif cmd == 0x20 and num == 0 and imm == 0:
        base = "stmask", 1, None
    elif cmd in (0x30, 0x31) and num == 0 and imm == 0:
        base = ("strow" if cmd == 0x30 else "stcol"), 4, None
    elif cmd == 0x4A:
        base = f"mpg 0x{imm:x}, {num or 256}", 0, (imm, num or 256)
    elif cmd in (0x50, 0x51) and num == 0:
        base = f"{'direct' if cmd == 0x50 else 'directhl'} {imm or 65536}", (imm or 65536) * 4, None
    elif cmd >= 0x60 and UNPACK_FMT[cmd & 0xF]:
        opts = "".join(o for o, b in ((", usn", 14), (", flg", 15)) if imm & (1 << b))
        mask = ", mask" if cmd & 0x10 else ""
        if (imm & 0x3C00) == 0:
            base = (f"unpack {UNPACK_FMT[cmd & 0xF]}, 0x{imm & 0x3FF:x}, {num or 256}{opts}{mask}",
                    unpack_words(cmd & 0xF, num), None)
    if base is None:
        return f"raw 0x{w:08x}", 0, None
    return irq + base[0], base[1], base[2]


def assemble_vif(text):
    t = text.strip()
    irq = 0
    if t.startswith("[i]"):
        irq = 0x80000000
        t = t[3:].strip()
    parts = re.split(r"[\s,]+", t)
    op, args = parts[0].lower(), parts[1:]
    rev = {v: k for k, v in VIF_SIMPLE.items()}
    revi = {v: k for k, v in VIF_IMM.items()}
    if op == "raw":
        return int(args[0], 0)
    if op in rev:
        return irq | rev[op] << 24
    if op in revi:
        return irq | revi[op] << 24 | int(args[0], 0)
    if op == "stcycl":
        return irq | 0x01 << 24 | int(args[1], 0) << 8 | int(args[0], 0)
    if op in ("stmask", "strow", "stcol"):
        return irq | {"stmask": 0x20, "strow": 0x30, "stcol": 0x31}[op] << 24
    if op == "mpg":
        return irq | 0x4A << 24 | (int(args[1], 0) & 0xFF) << 16 | int(args[0], 0)
    if op in ("direct", "directhl"):
        return irq | (0x50 if op == "direct" else 0x51) << 24 | (int(args[0], 0) & 0xFFFF)
    if op == "unpack":
        cmd = 0x60 | UNPACK_FMT.index(args[0].lower())
        imm = int(args[1], 0)
        for a in args[3:]:
            a = a.lower()
            if a == "usn":
                imm |= 1 << 14
            elif a == "flg":
                imm |= 1 << 15
            elif a == "mask":
                cmd |= 0x10
            else:
                raise ValueError(f"bad unpack option {a}")
        return irq | cmd << 24 | (int(args[2], 0) & 0xFF) << 16 | imm
    raise ValueError(f"unknown vif code: {text!r}")


def dmatag_text(w0, w1):
    qwc, pce, tid, irq = w0 & 0xFFFF, (w0 >> 26) & 3, (w0 >> 28) & 7, w0 >> 31
    if (w0 >> 16) & 0x3FF or pce:
        return f".dmatag_raw 0x{w0:08x}, 0x{w1:08x}"
    s = f".dmatag {DMA_IDS[tid]}, {qwc}"
    if w1:
        s += f", addr=0x{w1:08x}"
    if irq:
        s += ", irq"
    return s


def assemble_dmatag(text):
    parts = [p.strip() for p in text.split(",")]
    w0 = DMA_IDS.index(parts[0].lower()) << 28 | int(parts[1], 0)
    w1 = 0
    for p in parts[2:]:
        if p.lower() == "irq":
            w0 |= 1 << 31
        elif p.lower().startswith("addr="):
            w1 = int(p[5:], 0)
        else:
            raise ValueError(f"bad dmatag option {p}")
    return [w0, w1]


# ------------------------------------------------------------- assembler ----

LABEL_RX = re.compile(r"^([A-Za-z_.$][\w.$]*):\s*(.*)$")


def assemble_text(source, filename="<vsm>"):
    """Assemble .vsm text to bytes (two passes for labels)."""
    lines = []
    for n, raw in enumerate(source.splitlines(), 1):
        line = raw.split(";", 1)[0].rstrip()
        if line.strip():
            lines.append((n, line.strip()))

    def run(labels_by_scope, collect):
        words = []
        pc = 0
        scope = 0
        scopes = [{}]
        for n, line in lines:
            try:
                m = LABEL_RX.match(line)
                if m and not line.startswith("."):
                    if collect:
                        scopes[scope][m.group(1)] = pc
                    line = m.group(2).strip()
                    if not line:
                        continue
                if line.startswith("."):
                    d, _, rest = line.partition(" ")
                    rest = rest.strip()
                    if d == ".dmatag":
                        scope += 1
                        scopes.append({})
                        words += assemble_dmatag(rest)
                    elif d == ".dmatag_raw":
                        scope += 1
                        scopes.append({})
                        words += [int(x, 0) for x in rest.split(",")]
                    elif d == ".vif":
                        w = assemble_vif(rest)
                        words.append(w)
                        if (w >> 24) & 0x7F == 0x4A:
                            pc = w & 0xFFFF
                    elif d == ".word":
                        words += [int(x, 0) & 0xFFFFFFFF for x in rest.split(",")]
                    elif d == ".resume_mpg":
                        pc = int(rest, 0)
                    elif d == ".equ":
                        name, val = [x.strip() for x in rest.split(",")]
                        if collect:
                            scopes[scope][name] = int(val, 0)
                    else:
                        raise ValueError(f"unknown directive {d}")
                    continue
                halves = re.split(r"\s{2,}|\t+", line, maxsplit=1)
                if len(halves) != 2:
                    raise ValueError("expected 'upper  lower' pair")
                table = labels_by_scope[scope] if labels_by_scope else {}

                def resolve(name):
                    if name[0].isdigit():
                        return int(name, 0)
                    if name in table:
                        return table[name]
                    if collect:
                        return pc + 1
                    raise ValueError(f"undefined label {name}")
                lo, up = assemble_pair(halves[0], halves[1], pc, resolve)
                words += [lo, up]
                pc += 1
            except Exception as exc:  # noqa: BLE001
                raise SystemExit(f"{filename}:{n}: {exc}") from exc
        return words, scopes

    _, scopes = run(None, True)
    words, _ = run(scopes, False)
    return struct.pack("<%dI" % len(words), *words)


# ---------------------------------------------------------- disassembler ----

def disasm_raw(data, base=0):
    """Disassemble bare microcode (no VIF framing)."""
    words = struct.unpack("<%dI" % (len(data) // 4), data)
    pairs = [(words[i], words[i + 1]) for i in range(0, len(words) - 1, 2)]
    targets = set()
    for i, (lo, up) in enumerate(pairs):
        if not up & I_BIT:
            t = branch_target(lo, base + i)
            if t is not None:
                targets.add(t)
    out = []
    lab = lambda t: f"L{t:03x}"  # noqa: E731
    for t in sorted(targets):
        if not base <= t < base + len(pairs):
            out.append(f".equ {lab(t)}, 0x{t:x}")
    out.append(f".resume_mpg 0x{base:x}")
    for i, (lo, up) in enumerate(pairs):
        pc = base + i
        if pc in targets:
            out.append(f"{lab(pc)}:")
        u, l = disasm_pair(lo, up, pc, lab)
        out.append(f"    {u:<38}  {l}")
    return "\n".join(out) + "\n"


class Stmt:
    __slots__ = ("addr", "size", "text", "scope", "pc", "label", "kind")

    def __init__(self, addr, size, text, scope, pc=None, kind="dir"):
        self.addr, self.size, self.text, self.scope = addr, size, text, scope
        self.pc, self.label, self.kind = pc, None, kind


def walk_stream(words, base_addr):
    """Parse a buffer of DMA-tagged VIF1 packets into statements.

    Returns (stmts, programs) where programs maps scope -> metadata.
    """
    stmts = []
    programs = {}
    i = 0
    n = len(words)
    scope = -1
    while i < n:
        a = base_addr + i * 4
        w0, w1 = words[i], words[i + 1]
        scope += 1
        qwc = w0 & 0xFFFF
        programs[scope] = {"addr": a, "qwc": qwc, "mpg": [], "targets": set(), "pcs": set()}
        stmts.append(Stmt(a, 8, dmatag_text(w0, w1), scope))
        j, end = i + 2, i + 4 + qwc * 4
        while j < end:
            w = words[j]
            text, payload, mpg = vif_text(w)
            stmts.append(Stmt(base_addr + j * 4, 4, ".vif " + text, scope))
            j += 1
            if mpg:
                vaddr, cnt = mpg
                programs[scope]["mpg"].append((vaddr, cnt))
                for k in range(cnt):
                    lo, up = words[j], words[j + 1]
                    pc = vaddr + k
                    st = Stmt(base_addr + j * 4, 8, (lo, up), scope, pc, "ins")
                    stmts.append(st)
                    programs[scope]["pcs"].add(pc)
                    if not up & I_BIT:
                        t = branch_target(lo, pc)
                        if t is not None:
                            programs[scope]["targets"].add(t)
                    j += 2
            k = 0
            while k < payload:
                # payload lines break at 16-byte address boundaries
                addr = base_addr + (j + k) * 4
                take = min(payload - k, 4 - ((addr >> 2) & 3))
                chunk = words[j + k:j + k + take]
                stmts.append(Stmt(addr, take * 4,
                                  ".word " + ", ".join(f"0x{x:08x}" for x in chunk), scope,
                                  kind="data"))
                k += take
            j += payload
        if j != end:
            raise SystemExit(f"packet at 0x{a:08x} overruns its qwc")
        i = end
    return stmts, programs


def label_name(pc):
    return f"L{pc:03x}"


def render_units(stmts, programs, units):
    """units: list of (name, addr, size). Returns {name: text}."""
    out = {}
    for name, uaddr, usize in units:
        body = [s for s in stmts if uaddr <= s.addr < uaddr + usize]
        if body and body[-1].addr + body[-1].size != uaddr + usize:
            raise SystemExit(f"{name}: statement straddles unit end")
        lines = [f"; {name}: VU1 microcode DMA/VIF1 packets, 0x{uaddr:08x}..0x{uaddr + usize:08x}",
                 "; generated by tools/vu_asm.py dis-units; assemble with tools/vu_asm.py asm",
                 ""]
        cur_scope = None
        for idx, s in enumerate(body):
            if s.scope != cur_scope:
                cur_scope = s.scope
                prog = programs[s.scope]
                here = {x.pc for x in body if x.scope == s.scope and x.kind == "ins"}
                if s.addr != prog["addr"]:
                    lines.append(f"; continued: packet at 0x{prog['addr']:08x}")
                else:
                    lines.append("")
                    lines.append(f"; packet 0x{prog['addr']:08x}: qwc {prog['qwc']}, mpg "
                                 + ", ".join(f"0x{a:x}+{c}" for a, c in prog["mpg"]))
                    lines.append(s.text)
                for t in sorted(prog["targets"] - here):
                    lines.append(f".equ {label_name(t)}, 0x{t:x}")
                if s.kind == "ins" and (idx == 0 or body[idx - 1].kind != "ins"):
                    lines.append(f".resume_mpg 0x{s.pc:x}")
                elif s.kind == "data" and s.addr != prog["addr"]:
                    lines.append("; continued payload")
            if s.kind == "ins":
                prog = programs[s.scope]
                if s.pc in prog["targets"]:
                    lines.append(f"{label_name(s.pc)}:")
                lo, up = s.text
                u, l = disasm_pair(lo, up, s.pc, label_name)
                lines.append(f"    {u:<38}  {l}")
            else:
                if s.text.startswith(".dmatag"):
                    continue
                elif s.text.startswith(".vif mpg"):
                    lines.append(s.text)
                else:
                    lines.append("    " + s.text if s.kind == "data" else s.text)
        out[name] = "\n".join(lines) + "\n"
    return out


# ----------------------------------------------------------- unit helpers ----

UNITS = [
    ("data_u32_00424200", 0x00424200, 0x2000),
    ("data_u32_00426200", 0x00426200, 0x2000),
    ("data_u32_00428200", 0x00428200, 0x2000),
    ("data_u32_0042A200", 0x0042A200, 0x2000),
    ("data_u32_0042C200", 0x0042C200, 0x2000),
    ("data_u32_0042E200", 0x0042E200, 0x2000),
    ("data_u32_00430200", 0x00430200, 0x2000),
    ("data_u32_00432200", 0x00432200, 0x2000),
    ("data_u32_00434200", 0x00434200, 0x2000),
    ("data_u32_00436200", 0x00436200, 0x1F60),
]
REPO = Path(__file__).resolve().parent.parent


BASE_ADDRESS = 0x00100000
DEFAULT_ROM = REPO / "private/SLUS_204.86.rom"


def read_rom_unit(rom, addr, size):
    """Retail bytes of one unit; the ROM file maps VA BASE_ADDRESS at offset 0."""
    data = Path(rom).read_bytes()[addr - BASE_ADDRESS:addr - BASE_ADDRESS + size]
    if len(data) != size:
        raise SystemExit(f"ROM too short for unit at 0x{addr:08X}")
    return data


def load_blob(rom):
    return b"".join(read_rom_unit(rom, addr, size) for _name, addr, size in UNITS)


def disassemble_units(rom):
    blob = load_blob(rom)
    words = struct.unpack("<%dI" % (len(blob) // 4), blob)
    stmts, programs = walk_stream(words, UNITS[0][1])
    return render_units(stmts, programs, UNITS), programs, stmts


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    a = sub.add_parser("asm")
    a.add_argument("input")
    a.add_argument("-o", "--output", required=True)
    d = sub.add_parser("dis-raw")
    d.add_argument("input")
    d.add_argument("--base", type=lambda x: int(x, 0), default=0)
    u = sub.add_parser("dis-units")
    u.add_argument("--rom", default=str(DEFAULT_ROM))
    u.add_argument("--out-dir", default=str(REPO / "src/vu"))
    c = sub.add_parser("check")
    c.add_argument("--rom", default=str(DEFAULT_ROM))
    c.add_argument("--vsm-dir", default=str(REPO / "src/vu"))
    args = ap.parse_args(argv)

    if args.cmd == "asm":
        data = assemble_text(Path(args.input).read_text(encoding="utf-8"), args.input)
        Path(args.output).write_bytes(data)
    elif args.cmd == "dis-raw":
        sys.stdout.write(disasm_raw(Path(args.input).read_bytes(), args.base))
    elif args.cmd == "dis-units":
        texts, _, _ = disassemble_units(args.rom)
        out = Path(args.out_dir)
        out.mkdir(parents=True, exist_ok=True)
        for name, text in texts.items():
            (out / f"{name}.vsm").write_text(text, encoding="utf-8")
    elif args.cmd == "check":
        bad = 0
        for name, addr, size in UNITS:
            want = read_rom_unit(args.rom, addr, size)
            path = Path(args.vsm_dir) / f"{name}.vsm"
            got = assemble_text(path.read_text(encoding="utf-8"), str(path))
            ok = got == want
            bad += not ok
            print(f"{name}: {'OK' if ok else 'MISMATCH'} ({len(got)}/{len(want)} bytes)")
        return 1 if bad else 0
    return 0


if __name__ == "__main__":
    sys.exit(main())
