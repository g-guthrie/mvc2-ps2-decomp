typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern void func_0018C6E0(void *);
extern void (*D_004C0908[2])(void *);
void func_00285C00(u8 *p) {
    s16 v;
    func_0018C6E0(p);
    v = p[0x1E6] ^ 1;
    *(s16 *)(*(u8 **)(p + 0x1DC) + 0x140) = v;
    *(u8 *)(*(u8 **)(p + 0x1DC) + 0x1E6) = v;
    D_004C0908[p[0x20B] & 0x3F](p);
}

extern u8 *func_003DA750(s32, s32, s32);
extern void func_003376F0(u8 *);
extern s32 D_004C283C;
extern V3 D_004B8010;
void func_00337850(u8 *p) {
    u8 *r = func_003DA750(0, 6, 1);
    if (r) {
        r[0x13C] = 1;
        *(void (**)(u8 *))(r + 0x10) = func_003376F0;
        *(s16 *)(r + 0xCC) = 0x2A;
        *(s32 *)(r + 0x84) = D_004C283C;
        *(u32 *)(r + 0xD0) = 0x800C00;
        *(V3 *)(r + 0x34) = D_004B8010;
        *(s16 *)(r + 0x1E) = 1;
        *(u8 **)(r + 0xC8) = p + 0x88;
    }
}

extern void func_003378E0(u8 *);
extern V3 D_004B8020;
void func_00337900(u8 *p) {
    u8 *r = func_003DA750(0, 6, 1);
    if (r) {
        r[0x13C] = 1;
        *(void (**)(u8 *))(r + 0x10) = func_003378E0;
        *(s16 *)(r + 0xCC) = 0x2B;
        *(s32 *)(r + 0x84) = D_004C283C;
        *(u32 *)(r + 0xD0) = 0x800C00;
        *(V3 *)(r + 0x34) = D_004B8020;
        *(s16 *)(r + 0x1E) = 1;
        *(u8 **)(r + 0xC8) = p + 0x88;
    }
}

extern u8 D_00583B92[];
extern s8 D_004BF368[8];
extern s32 D_004C2830;
void func_00139760(u8 *p) {
    u32 s = p[4];
    switch (s) {
    case 0:
        if (D_00583B92[p[0x20]] & (0x10 << p[0x21])) {
            u8 *o = *(u8 **)(p + 0x14);
            p[4] = s + 1;
            p[0x13C] = 1;
            *(s16 *)(p + 0xCC) = (D_004BF368 + p[0x20] * 3)[*(s8 *)(o + 0x4DD)];
            *(s32 *)(p + 0x84) = D_004C2830;
        }
        break;
    case 1:
        break;
    }
}
