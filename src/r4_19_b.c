/* func_00260070: MW 3.0 (try30) -O3 -sdatathreshold 0 -fp off, compiled warm after src/nf10_b.c (MWWARM_30@src/nf10_b.c). */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    f32 f0, f4, f8, fc, f10, f14, f18;
} E260;

extern E260 D_00453BA0[];
typedef struct { u8 pad[0x1E]; s16 h; } S1E;

void func_00260070(u8 *p)
{
    extern void func_001B0F40(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    E260 *e; S1E *sa;
    u16 i;
    f32 v;

    if (*(s16 *)(p + 0x1E) < 4) {
        i = (*(u16 *)(p + 0x354) & 0x3C00) >> 10;
        e = D_00453BA0;
        p[0x23] = i;
        p[0x21] = p[0x23];
        e += i;
        if (e->f10) {
            p[6]++;
            *(s16 *)(p + 0x1C) = 0x1E;
            sa = (S1E *)p; sa->h += 1;
            *(f32 *)(p + 0x5C) = e->f0;
            *(f32 *)(p + 0x68) = e->f4;
            *(f32 *)(p + 0x60) = e->f8;
            *(f32 *)(p + 0x6C) = e->fc;
            p[7] = (u32)e->f18;
            if (e->f14 >= 0.0f) v = e->f14; else v = (f32)*(s16 *)(p + 0x140);
            *(s16 *)(p + 0x140) = (s32)v;
            func_001B0F40(p, 0);
            func_001B0F40(p, 1);
            *(s32 *)(p + 0x48) = 0;
            func_001757E0(p, 0x16, 1);
        }
    }
}
