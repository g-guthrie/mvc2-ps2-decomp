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

