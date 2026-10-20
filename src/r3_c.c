typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef signed long long s64;
typedef float f32;

extern u32 *func_003F1F00(void *file);
extern u32 *func_003F1F10(s32, s32);
s32 func_003F1950(s32 a) {
    u32 *p;
    if ((*func_003F1F00((void *)a) & 1) != 0) {
        if ((p = func_003F1F10(a, 1)) != 0) return p[1];
        return 0;
    }
    return 0;
}

typedef struct { u8 pad[4]; u32 *f4; u8 pad2[0x12]; s16 f1a; } S;
static u64 *func_00420A00(S *p) { return *(u64 **)((u8 *)p + 0x10); }
static s32 func_00420A20(S *p, s32 k) { return *(s32 *)((u8 *)p + 0x14) == k; }
s32 func_00420B30(S *p, u64 v, s32 n) {
    u64 *q = func_00420A00(p);
    if (func_00420A20(p, 2) == 0) return 0;
    p->f4 = (u32 *)q;
    q[0] = ((u64)0x4000000 << 32) | (u32)0x8000 | ((u64)n << 60);
    q[1] = v;
    p->f1a = n;
    return 1;
}

typedef struct { u8 pad0; s8 f1; u16 f2; } K;
void func_003EE480(K *k, u8 c) {
    switch (c) {
    case 0:    k->f2 = 0;      k->f1 = 0;    break;
    case 0x63: k->f2 = 8;      k->f1 = 0;    break;
    case 0x41: k->f2 = 1;      k->f1 = 0;    break;
    case 0x73: k->f2 = 1;      k->f1 = 0x60; break;
    case 0x79: k->f2 = 1;      k->f1 = 0x73; break;
    case 0x53:
    case 0x23:
    default:   k->f2 = 0x8000; k->f1 = 0;    break;
    }
}

s32 func_0041CE80(u8 c) { if (c > 0x3A) return -1; if (c >= 0x1B) return c - 3; return c; }

