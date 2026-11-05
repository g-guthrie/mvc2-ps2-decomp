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
    # Explicit calls of the EE soft-double compares (_dpflt = func_00100240
    # "a < b", _dpfgt = func_00100290 "a > b"; libgcc-style, the double in
    # $a0:$a1, the 0 in $a2).  Their credited bodies are `(void)` and
    # tail-call the compare (func_00119AB8) whose result is in $v0, so on
    # the host every such test was false: e.g. a dash or a projectile assist
    # that waits for its velocity to change sign never advanced (Ryu alpha,
    # Ken alpha, Akuma beta: the partner stayed in state 0x15 after 15/03, so
    # no further assists).  Host form: the same compare in C.
    # func_00185010 (the per-frame check of a player's special/hit state,
    # func_0017D270) returns the state handler's $v0: the C falls off the
    # end after `D_00448E30[p[7]](p);` (a jalr then jr $ra), and R14 made the
    # host return 0, so a handler's "consumed" result (e.g. func_00185180 ->
    # func_00185380) never stopped func_0017D270 and the player took a hit
    # the PS2 skips (oracle: attract demo, player 1, +3481 frames).  Most
    # handlers are int; for the void ones see the oracle notes in BOOT_NOTES.
    "src/grok_w5_0018.c": [
        ("    D_00448E30[p[7]](p);\n}",
         "    return ((s32 (*)(u8 *))D_00448E30[p[7]])(p); /* host R10: the handler's $v0 */\n}"),
    ],
    # func_001E6490's `Obj o` is 6 words, but func_004161D0 (src/r4c.c, the
    # TIM2 header parse) fills 7 (w18 at +0x18).  On the EE the extra word
    # lands in an unused stack slot; on the host it overwrote the local `v`
    # (the texture/CLUT handle pair), so func_003EA660 got a CLUT handle of 0
    # and divided by zero in func_003DBD80 (character select, a portrait
    # load; showed up with a different stack layout).  Host form: room for
    # the seventh word.
    "src/rb35_c.c": [
        ("typedef struct { s32 f0, f4, f8, fC, f10, f14; } Obj;",
         "typedef struct { s32 f0, f4, f8, fC, f10, f14, f18; } Obj; /* host R10: func_004161D0 writes +0x18 */"),
    ],
    # Two calls the R12 pass left unprototyped (the TU's declarations are
    # K&R and the raw build saw no mismatch).  Under MVC2_PS2_FLOAT the
    # wasm backend sees both arities in one module and wasm-ld rejects the
    # link ("function signature mismatch").  The arguments are what the asm
    # passes: func_002BCBE0's $a1 is still q at `jal func_002BCE90`
    # (0x002BCC18); func_00405CC0's $a0 is still p at the first
    # `jal func_00405968` (0x00405D04).  (R12 class, for the r12 work.)
    "src/w20a0_j.c": [
        ("        func_002BCE90(p);\n", "        func_002BCE90(p, q); /* host R10: $a1 = q */\n"),
    ],
    "src/w193_b.c": [
        ("if (p[3] == 0 && func_00405968() == -1)",
         "if (p[3] == 0 && func_00405968(p) == -1) /* host R10: $a0 = p */"),
    ],
    # jtbl_00475ABC is not a jump table: its first word 0x00400020 is the
    # s16 pair (32, 64), the fourth entry of the effect offset table
    # D_00475AB0 (x, y pairs read by func_003BDE30, src/fb43_a.c: a Thanos
    # effect follows its owner by these offsets).  Credited as the address of
    # func_00400020, the host stored a host code address there, so the effect
    # flew off to x = 13839 and the CPU's threat check (func_00169470) saw a
    # different scene (oracle: Thanos vs Ken, +1646 frames).  Host form: the
    # literal word, as the second entry already is.
    "src/data/jtbl_00475ABC.c": [
        ("    func_00400020,\n", "    (Mvc2Address)0x00400020u, /* host R10: data, the s16 pair (32, 64) */\n"),
    ],
    # The same for the last entry of jtbl_004BFBB8 (0x004BFC18 = D_004BFC18):
    # 0x00300020 is the s16 pair (0x20, 0x30), a hit-stun/timer table that
    # func_001F1F60 (src/sa12_j.c) reads as D_004BFC18[p[0x1B7]] into
    # p+0x1C.  The dispatch through this table (func_001F0E80, jtbl_004BFC10
    # = entries 22..23) never reaches entry 24.  As a host code address the
    # timer started at 0xB740 instead of 0x20 (oracle fuzz seed 5, +2115).
    "src/data/jtbl_004BFBB8.c": [
        ("    func_00300020,\n",
         "    (Mvc2StateCallback)0x00300020u, /* host R10: data D_004BFC18, the s16 pair (0x20, 0x30) */\n"),
    ],
    # And jtbl_004C1BF0 (2 entries for its dispatcher func_00360A00): its
    # "entries" 6 and 7, 0x00400050 and 0x00200030, are D_004C1C08[4] =
    # {0x50, 0x40, 0x30, 0x20}, the s16 speeds residual_00361A00 (src/a1c_c.c)
    # reads as D_004C1C08[p[0x21] & 3] (found by scanning the tables for
    # entries that a TU declares as sub-word data; same class as above).
    "src/data/jtbl_004C1BF0.c": [
        ("    func_00400050,\n    func_00200030,\n",
         "    (Mvc2OwnerStateCallback)0x00400050u, /* host R10: data D_004C1C08, s16 (0x50, 0x40) */\n"
         "    (Mvc2OwnerStateCallback)0x00200030u, /* host R10: data D_004C1C08 + 4, s16 (0x30, 0x20) */\n"),
    ],
    # func_001A1FC0 calls through D_0044AFF0 with only a0; at the jalr
    # (0x001A2034) $a1 = *(a0 + 0x18) and $a2 = $a1 + 0x2B8, the C's a1/a2,
    # and the entries (func_001A2050 ...) read $a1 (oracle fuzz seed 39:
    # SIGSEGV in func_00185960 through func_001A2200 with q = garbage).
    # R12 class: gen_indirect.py only matches `D_x[i]()` calls.
    # func_0018A990(p, q) reads *(u16 *)(q + 6) (the input word of an actor
    # record at its other callers); here q = &v, a u16 at sp+0x2E, so the EE
    # reads sp+0x34 = the caller's (func_002D8F30) sp+4: bits 32-47 of the $s0
    # it saved with sq, a sign-extended positive address, so 0.  The host
    # read stack garbage and set p[0x1B7]/p[0x212] (oracle fuzz seeds 5, 53:
    # Storm, player[0]+0x210 and +0x1B4).
    "src/hy1_k.c": [
        ("    func_0018A990(p, &v);\n",
         "    { u16 w[4] = { v, 0, 0, 0 }; func_0018A990(p, w); } /* host R10: q + 6 is 0 on the EE */\n"),
    ],
    # Same class, found by scanning the cast-pointer table calls against the
    # retail table entries: func_00351210 jumps through D_00462500 with $a0
    # still a0 (0x00351250), the entries take it; the C passes nothing.
    "src/wave1x.c": [
        ("        (*(void (**)(void))(D_00462500 + *(u8 *)(a0 + 5) * 4))();\n",
         "        (*(void (**)(u8 *))(D_00462500 + *(u8 *)(a0 + 5) * 4))(a0); /* host R12: $a0 */\n"),
    ],
    # func_003AE590 (R20-widened to p, __rp1..3) jumps through D_00473B90
    # with $a0..$a3 = its own arguments (0x003AE5D4); the C passes nothing.
    "src/wave7.c": [
        ("        (*(void (**)(void))(D_00473B90 + p[4] * 4))();\n",
         "        (*(void (**)())(D_00473B90 + p[4] * 4))(p, __rp1, __rp2, __rp3); /* host R12: $a0..$a3 */\n"),
    ],
    # func_002271E0 reads D_004517C0[p[0x151]] (8 floats) with indices past
    # the end: 8..63 land in jtbl_004517E0, jtbl_00451800 ... (code
    # addresses 0x002xxxxx, and zero padding; the retail words from 64 on are
    # float data again), denormals as floats, and the EE FPU treats denormal
    # operands as 0, so x += d leaves x alone (seed 79 reads index 16).  On the host those words are host code addresses
    # (0x08xxxxxx, a normal ~1e-34) and the round-toward-zero add moved x by
    # an ulp (oracle fuzz seed 79, player[4]+0x34 C41D9EEE vs C41D9EEF).
    "src/dp7_b.c": [
        ("        d = D_004517C0[(s32)v];\n",
         "        d = ((s32)v >= 8 && (s32)v < 64) ? 0.0f : D_004517C0[(s32)v]; /* host R10: jtbl_004517E0 words are EE denormals */\n"),
    ],
    # func_00185640(a, b) calls the character handler *(a + 0x43C) + 0x28
    # with $a1 still b (0x00185670); the Storm handler func_002E3920(p, q)
    # writes q's direction fields (oracle fuzz seed 240: q was garbage, a
    # record half-way, and player[4]+0x04 / +0xA8 changed).
    "src/q6_x.c": [
        ("    (*(void (**)(u8 *))(*(u8 **)(a + 0x43C) + 0x28))(a);\n",
         "    (*(void (**)(u8 *, u8 *))(*(u8 **)(a + 0x43C) + 0x28))(a, b); /* host R12: $a1 = b */\n"),
    ],
    "src/n6.c": [
        ("        (*(void (**)(u8 *))(D_0044AFF0 + U8(a0, 4) * 4))(a0);\n",
         "        (*(void (**)(u8 *, u8 *, u8 *))(D_0044AFF0 + U8(a0, 4) * 4))(a0, a1, a2); /* host R12: $a1, $a2 */\n"),
    ],
    "src/wave32.c": [
        ("if (func_00100240(*(f32 *)(p + 0x5C) * v, 0)) {",
         "if ((double)(*(f32 *)(p + 0x5C) * v) < 0.0) { /* host R10: _dpflt */"),
    ],
    "src/wave22.c": [
        ("if (func_00100240((double)(nw * old), 0)) {",
         "if ((double)(nw * old) < 0.0) { /* host R10: _dpflt */"),
    ],
    "src/wave27.c": [
        ("    d = fptodp(*(f32 *)(a + 0x5C) * v);\n    if (func_00100240(d, 0) != 0) {",
         "    d = 0;\n    if ((double)(*(f32 *)(a + 0x5C) * v) < 0.0) { /* host R10: fptodp + _dpflt */"),
    ],
    "src/grok_v3_residual_00368A40.c": [
        ("if (func_00100290(func_00119058(d), 0)) {",
         "if ((double)(d) > 0.0) { /* host R10: _dpfgt of the float widened to double */"),
    ],
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

# ---- Arcade-accuracy CODE toggles (ARCADE_DIFF.md section 10) ----------------
# Not R10 fixes: each adds a test of `mvc2_arc_code` (port/host/arcade_code.c,
# settings arcade.*) that selects the NAOMI program's behaviour; with the bit
# clear (the default) the PS2 code runs unchanged.
_ARC = {
    # func_001827B0 (NAOMI 0x0C042414): flying-screen edge clamp.  PS2
    # 35 + 16 units inside the camera bound, NAOMI 35 (0x420C0000 only).
    # 0.0f + d == d exactly in every rounding mode.
    "src/e080_e.c": [
        ("void func_001827B0(u8 *p) {",
         "extern int mvc2_arc_code __attribute__((weak)); /* host: arcade.fs_edge (arcade_code.c; weak: not game glue) */\nvoid func_001827B0(u8 *p) {"),
        ("        t = 35.0f + (16.0f + d[0x98 / 4]);",
         "        t = 35.0f + (((mvc2_arc_code & 1) ? 0.0f : 16.0f) + d[0x98 / 4]); /* host: arcade.fs_edge */"),
        ("        t = (d[0x9C / 4] - 16.0f) - 35.0f;",
         "        t = (d[0x9C / 4] - ((mvc2_arc_code & 1) ? 0.0f : 16.0f)) - 35.0f; /* host: arcade.fs_edge */"),
    ],
    # func_00179590 (NAOMI 0x0C039928): the hit-stop branch clears Servbot's
    # (0x3A) input words when +0x216 & 0x80; the NAOMI branch has no clause.
    "src/xl8_a.c": [
        ("        if (p[1] == 0x3A) {\n            if ((p[0x216] & 0x80) != 0) {",
         "        if (p[1] == 0x3A && !(mvc2_arc_code & 2)) { /* host: arcade.servbot_hitstop */\n"
         "            if ((p[0x216] & 0x80) != 0) {"),
        ("typedef unsigned char u8;\n", "typedef unsigned char u8;\nextern int mvc2_arc_code __attribute__((weak)); /* host: arcade.servbot_hitstop (arcade_code.c) */\n"),
    ],
}
for _k, _v in _ARC.items():
    OVERRIDES.setdefault(_k, []).extend(_v)
