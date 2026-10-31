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
    # The gallery's state hook D_0043CD0C (a .data word: sc6_d.c writes it as
    # D_0043CD0C[0]) is stored through its literal EE address here; on the
    # host that address is not the variable (SIGSEGV entering the gallery).
    "src/initialize_runtime_effect_backend_0041C4B0.c": [
        ("    *(void (**)(s32, s32))0x0043CD0C = func_0041C550;",
         "    { extern void (*D_0043CD0C[])(); D_0043CD0C[0] = (void (*)())func_0041C550; } /* host R10: EE address 0x0043CD0C */"),
    ],
    "src/initialize_runtime_animation_backend_0041C400.c": [
        ("    *(void (**)(s32, s32))0x0043CD0C = func_0041C460;",
         "    { extern void (*D_0043CD0C[])(); D_0043CD0C[0] = (void (*)())func_0041C460; } /* host R10: EE address 0x0043CD0C */"),
    ],
    # func_0016EEC0 (pad vibration timers) reads `idx` before setting it
    # when a timer is armed (< 0) but the pad is not in the vibrating mode:
    # retail keeps idx in $s1, so it reads the caller's $s1, which is 0 all
    # the way down from crt0 (src/ee_crt0.S clears $17; the main loop and
    # its callees save and restore it).  Host: start idx at 0, as retail.
    # D_004C2010 is a function table (func_003B6470: D_004C2010[p[5]](p, q))
    # credited as the raw EE address 0x003B5F30: the host jumped to that
    # number (SIGSEGV after Sentinel's third assist, assist sweep, ARCADE_DIFF.md
    # 7.3).  The only literal code address in a credited data initializer
    # (scan of src/ and src/data/).  Host form: the function's address.
    "src/data/D_004C2010.c": [
        ("u32 D_004C2010[2] = {\n    0x003B5F30u,",
         "extern void func_003B5F30(); /* host R10: a function table */\nu32 D_004C2010[2] = {\n    (u32)func_003B5F30,"),
    ],
    "src/sa11_l.c": [
        ("    s32 idx;\n", "    s32 idx = 0; /* host R10: retail's $s1 from the main loop (0) */\n"),
    ],
    "src/r12_07_c.c": [
        ("sb = &func_004180E0();",
         "{ static S10 ee_page0; func_004180E0(); sb = &ee_page0; } /* host R10: EE address 0 */"),
    ],
}
