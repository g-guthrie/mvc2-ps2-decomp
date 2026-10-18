typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void (*D_004BF8B0[2])(u8 *);
extern u8 *D_004C25D4[1];
extern f32 D_004F1FEC[];
extern f32 D_004F1FF8[];
extern void func_00126970(f32 *, f32 *);
extern void func_00126280(s32, u8 *);
extern void func_00126340(s32, u8 *);

void func_001B3190(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    u32 t;
    D_004BF8B0[p[5]](p);
    if (q[0x1E4] != 0x16) {
        t = p[4];
        p[4] = t + 1;
    }
}

void func_00125A80(u8 *p) {
    D_004F1FEC[0] = *(f32 *)(D_004C25D4[0] + 0x34);
    func_00126970(D_004F1FEC, D_004F1FF8);
    D_004F1FF8[0] = D_004F1FEC[0];
    func_00126280(0, p);
    func_00126340(0, p);
}

extern u8 *D_004C2794[1];
extern s32 (*D_00455458[])(u8 *);
extern void func_00280E70();

typedef struct { f32 f0; u8 pad[3]; u8 b7; } G2974;
extern G2974 *D_004C2974[1];
extern void func_001757E0(u8 *, s32, s32);
void func_00367140(u8 *p) {
    f32 v;
    p[5] = 4;
    p[6] = 0;
    if (D_004C2974[0]->b7 != 0) v = 5.0f; else v = -5.0f;
    *(f32 *)(p + 0x5C) = v;
    *(f32 *)(p + 0x68) = 0.0f;
    *(u32 *)(p + 0x60) = 0x41092492;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    *(f32 *)(p + 0x38) = D_004C2974[0]->f0;
    p[0x168] = (((*(s16 *)(p + 0x140)) ^ D_004C2974[0]->b7) != 0) ? 0xC : 0xE;
    func_001757E0(p, 0x17, p[0x168]);
}
