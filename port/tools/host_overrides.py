"""R10: per-file exact text replacements for the HOST build only, for source
constructs no mechanical rule can carry to a host compiler.  Each entry must
keep the original semantics; hostify.transform() raises if `old` is missing
(so a src/ change forces the override to be revisited).  Keep this list short.
"""
OVERRIDES = {
    # struct P places `C cEC` (0xC4 bytes) at 0xEC but the next field at
    # 0x13C, written as a negative pad `u8 p1B0[0x13C - 0xEC - sizeof(C)]`.
    # MWCC and i386 clang wrap the size mod 2^32 (offsets come out right);
    # Emscripten clang rejects the >4 GB struct.  Host form: a 0x50-byte head
    # plus an explicit 0xC4-byte copy, identical layout and behaviour.
    "src/fb86_b.c": [
        ("    C cEC;\n    u8 p1B0[0x13C - 0xEC - sizeof(C)];\n",
         "    u8 cEC_head[0x13C - 0xEC]; /* host R10: C cEC overlaps the next fields */\n"),
        ("p->cEC = q->cEC;",
         "__builtin_memmove((u8 *)p + 0xEC, (u8 *)q + 0xEC, sizeof(C)); /* host R10 */"),
    ],
}
