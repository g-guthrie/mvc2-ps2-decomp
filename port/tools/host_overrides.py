"""R10: per-file exact text replacements for the HOST build only, for source
constructs no mechanical rule can carry to a host compiler.  Each entry must
keep the original semantics; hostify.transform() raises if `old` is missing
(so a src/ change forces the override to be revisited).  Keep this list short.
"""
OVERRIDES = {
    # the destination of func_003EF980 (a byte copy, func_003DCDC0) is given
    # through the EE's uncached mirror (| 0x20000000): same RAM on the host
    # (R21 covers the pointer-cast form; this one is a plain argument)
    "src/gr22_d.c": [
        ("func_003EF980(m[2], m[1] | 0x20000000, m[3]);",
         "func_003EF980(m[2], m[1] /* host R10: uncached mirror */, m[3]);"),
    ],
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
    # func_0038AA30 takes `&func_004180E0()`: the callee returns 0 and MWCC
    # uses $v0 as the struct address, so retail copies 10 bytes from EE
    # address 0 (kernel RAM). Clang rejects the address of an rvalue, and the
    # host has no RAM at 0: read a zeroed stand-in after making the call.
    # func_00417EB0(V3 *) (normalise in place, return the length) is called
    # with a V3 by value: MWCC passes a by-value struct as the address of a
    # caller-made copy, so the callee normalises that copy.  i386 pushes the
    # struct itself (the callee reads x as a pointer: SIGSEGV on the stage
    # whose effect calls func_00330380).  Host form: pass the copy's address.
    "src/sLa1_c.c": [
        ("extern f32 func_00417EB0(V3_b);", "extern f32 func_00417EB0(V3_b *); /* host R10: by-value struct = address of a copy */"),
        ("r = func_00417EB0(w);", "r = func_00417EB0(&w); /* host R10 */"),
    ],
    "src/r12_07_c.c": [
        ("sb = &func_004180E0();",
         "{ static S10 ee_page0; func_004180E0(); sb = &ee_page0; } /* host R10: EE address 0 */"),
    ],
}
