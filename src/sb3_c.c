typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_004B7C20[];

void func_00331AB0(u8 *p)
{
    extern void func_00331C20(u8 *);
    extern void func_003319E0(u8 *);
    u8 *q;
    s32 i;
    if (p[6] < p[7] - 1) {
        q = (u8 *)D_004B7C20;
        for (i = 0; i < p[4]; i++) {
            q = q + *(s16 *)q * 4;
        }
        q += 2;
        *(s32 *)(p + 0xD4) = *(s16 *)(q + (p[6] & 0xFF) * 2);
        q += (p[7] - 1) * 2;
        q += p[6] * 2;
        *(s32 *)(p + 0xD8) = *(s16 *)q;
        p[5] = 2;
        func_00331C20(p);
    } else {
        p[4]++;
        p[4] = (u32)p[4] % 6u;
        p[5] = 0;
        p[6] = 0;
        func_003319E0(p);
    }
}

void func_003315C0(u8 *p)
{
    extern void func_00331730(u8 *);
    extern void func_003314F0(u8 *);
    u8 *q;
    s32 i;
    if (p[6] < p[7] - 1) {
        q = (u8 *)D_004B7C20;
        for (i = 0; i < p[4]; i++) {
            q = q + *(s16 *)q * 4;
        }
        q += 2;
        *(s32 *)(p + 0xD4) = *(s16 *)(q + (p[6] & 0xFF) * 2);
        q += (p[7] - 1) * 2;
        q += p[6] * 2;
        *(s32 *)(p + 0xD8) = *(s16 *)q;
        p[5] = 2;
        func_00331730(p);
    } else {
        p[4]++;
        p[4] = (u32)p[4] % 6u;
        p[5] = 0;
        p[6] = 0;
        func_003314F0(p);
    }
}
