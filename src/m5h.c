typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 p0[0x4]; u8 a; u8 b; u8 p1[0x1A]; u8 t; } T1;

extern void func_00175700(void *p);
extern void func_001757E0(void *p, s32 a, s32 b);
extern void func_003C5780(void *p);
void func_003C63C0(u8 *p) {
    s16 v;
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v < 0) {
        u32 t = p[5];
        p[5] = t + 1;
        func_001757E0(p, 0x15, 0x1E);
        func_003C5780(p);
    }
}

extern u8 D_00457C70[];
extern s32 func_00189310(void *p, void *q, void *r);
extern void func_0018A990(void *p, void *q);
extern void func_00186A60(void *p, s32 a);
