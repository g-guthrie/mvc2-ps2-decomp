typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long u64;
typedef signed long s64;

typedef struct { u8 pad0[0x12]; s16 h12; s16 h14; s16 h16; s16 h18; u8 pad1[2]; u32 w1C; u8 pad2[0x20]; } E64;
extern E64 D_0061C7A0[];
extern E64 D_006207A0[];

void func_00413510(u64 *dst, u32 a, u32 b) {
    E64 *f = &D_006207A0[(a & 0xFFFF) - 1];
    E64 *e = &D_0061C7A0[(b & 0xFFFF) - 1];
    *dst = ((u64)f->h12 | ((u64)(f->h18 / 64) << 14) | ((u64)f->w1C << 20) | ((u64)f->h14 << 26)
            | ((u64)f->h16 << 30) | ((u64)4 << 32) | ((u64)e->h12 << 37) | ((u64)e->w1C << 51)
            | ((u64)0x40000000 << 32));
}
