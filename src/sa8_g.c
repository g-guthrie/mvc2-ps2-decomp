typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_00463BB0[59]; /* defined in src/data/data_actor_state_offsets_00463BB0.c */

void func_0036E750(u8 *p, u8 *q, s32 *r)
{
    extern void func_0036EA50(u8 *, u8 *, s32 *);
    extern void func_0036EAA0(u8 *, u8 *, s32 *);
    extern s32 func_0036EAE0(u8 *, u8 *, u8 *);
    extern int func_00175700(u8 *);
    extern int func_001757E0(u8 *, s32, s32);
    extern void func_001E7F60(u8 *);
    u8 *s;
    s32 v;
    s16 h;
    u32 t;
    s = *(u8 **)(q + 0x220);
    v = *(s8 *)(p + 0x1B2);
    if (v < 0 && (v & 0x80) != 0) {
        p[0x1B2] = v | -0x80;
        func_0036EA50(p, q, r);
        if (r[1] != 0) {
            t = p[5];
            p[5] = t + 1;
            func_0036EAA0(p, q, r);
            *(s32 *)(p + 0x5C) = 0;
            *(s32 *)(p + 0x60) = 0;
            *(s32 *)(p + 0x68) = 0;
            *(s32 *)(p + 0x6C) = 0;
            *(u32 *)(p + 0x6C) = 0xBECDB6DB;
            *(s16 *)(p + 0x140) = *(s16 *)(q + 0x140) ^ 1;
            func_001757E0(p, 0x17, (u8)(D_00463BB0[s[1]] + 0x25));
            func_0036EAE0(p, q, (u8 *)r);
            return;
        }
        p[5] = 3;
    } else {
        h = *(s16 *)(p + 0x1C);
        *(s16 *)(p + 0x1C) = h - 1;
        if (h == 0) {
            t = p[4];
            p[4] = t + 1;
            p[0x13C] = 0;
        } else {
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
            *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
            *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
            func_00175700(p);
            func_001E7F60(p);
        }
    }
}
