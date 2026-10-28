/* nearmiss: MW 3.0.3 or 3.0, -O3 -sdatathreshold 0, 19/95 words: compiler hoists 'daddu a0,s1' into the bnez(0x151)/bltz(2nd f670) slots from both successors; retail leaves nop and fills the following jal slot */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

s32 func_003A98C0(u8 *p, u8 *q) {
    extern s8 func_00175700();
    extern s8 func_00175670();
    extern s32 func_003A9A50(u8 *, u8 *);
    extern s32 func_00174170();
    extern void func_001754A0(u8 *, s32, s32);
    extern void func_001E7F60();
    extern s32 func_001D7CE0(u8 *, s32);
    extern void func_001E3710(u8 *, s32);
    s16 h;

    if (p[5] == 0) {
        h = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = h;
        if (h <= 0) {
            { u32 t = p[5]; p[5] = t + 1; }
            if (p[0x21] == 0) {
                u32 v = func_00174170() & 3;
                func_001754A0(p, 0x1B, (u8)(v + 0xA));
            }
        } else {
            if (*(s8 *)(p + 0x151) == 0) func_00175700(p);
            func_001E7F60(p);
        }
        if (p[6] == 0 && *(s8 *)(p + 0x1B2) != 0 && *(u8 *)(*(u8 **)(p + 0x1C4) + 0x247) == 9
            && func_001D7CE0(q, 1) != 0) {
            { u32 t = p[6]; p[6] = t + 1; }
            func_001E3710(p, 0xA);
            goto end;
        }
    } else {
        if (p[0x21] != 0) {
            if (func_00175700() < 0) goto L;
        } else if (func_00175670() < 0 || func_00175670(p) < 0) {
            goto L;
        }
end:
        return;
L:
        return func_003A9A50(p, q);
    }
}
