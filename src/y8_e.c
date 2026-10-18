typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern f32 D_004F1FD0;
extern f32 D_004643BC[];
extern u8 *D_004C2794;
extern void (*D_00455458[])(u8 *);
extern void (*D_00463DB0[])(u8 *, u8 *, u8 *);

typedef struct { u8 pad[0x34]; f32 f34; u8 pad2[0x1E6 - 0x38]; u8 f1e6; u8 pad3[0x220 - 0x1E7]; u8 *f220; } S_69D30;
s32 func_00269D30(S_69D30 *p) {
    extern void func_001757E0();
    f32 k;
    f32 f0;
    u8 v = p->f1e6;
    k = -23.333332061767578f;
    if (v != 0) { k = -k; }
    f0 = *(f32 *)(p->f220 + 0x34) + k;
    if (!(f0 < p->f34) && v != 0) return 0;
    if (f0 < p->f34 && v == 0) return 0;
    ((u8 *)p)[0x20D] = 0;
    *(u32 *)((u8 *)p + 0x5C) = 0;
    *(u32 *)((u8 *)p + 0x60) = 0;
    *(u32 *)((u8 *)p + 0x68) = 0;
    *(u32 *)((u8 *)p + 0x6C) = 0;
    ((u8 *)p)[6] = 3;
    ((u8 *)p)[7] = 0;
    func_001757E0(p, 0x16, 0x1F);
    return 1;
}
