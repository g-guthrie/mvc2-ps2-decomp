typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


extern u8 D_00457B50[];
s32 func_00294080(u8 *p) {
    extern s32 func_0018AB10();
    extern void func_0038D390();
    s32 s0;
    s32 t;
    u8 *c;
    s0 = 0;
    t = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = t;
    if ((s16)t == 0) goto loop;
    if (func_0018AB10() == 0) goto end;
    t = p[0x2C4];
    p[0x2C4] = t + 1;
    c = p + 0x2B8;
    if (p[0x2C4] <= 0) goto end;
    c[0xC] = 0;
    *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) - 4;
    if (*(s16 *)(p + 0x1E) > 0) goto end;
loop:
    s0 = *(s16 *)(D_00457B50 + (p[7] << 2));
    if (s0 == -1) goto end;
    func_0038D390(p, s0 & 0xFF);
    *(s16 *)(p + 0x1E) = *(s16 *)(D_00457B50 + (p[7] << 2) + 2);
    t = p[7];
    p[7] = t + 1;
    if (*(s16 *)(p + 0x1E) == 0) goto loop;
end:
    return s0;
}
