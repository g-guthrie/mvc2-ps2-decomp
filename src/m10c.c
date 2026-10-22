typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 *D_004C2794;
extern s32 func_00175700(void *p);
extern void func_002F1D90(void *p);
void func_002EEAD0(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        s16 *q;
        *(s32 *)(p + 0x334) = 0;
        p[0x1B5] = 0x1A;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        q = (s16*)(((u32)p[2] << 1) + (u32)D_004C2794);
        q[0x7C / 2] = q[0x7C / 2] + 1;
        func_002F1D90(p);
    }
}
extern void (*D_004C1BD0[2])(u8 *, u8 *);
extern int func_00174470(const void *);
void func_00360860(u8 *p, u8 *q) {
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    if (!func_00174470(p) || !(*(f32 *)(q + 0x430) <= *(f32 *)(p + 0x38))) {
        u32 t = p[4];
        p[4] = t + 1;
    } else {
        D_004C1BD0[p[5]](p, q);
    }
}
extern void func_001843A0(void *p);
extern void func_001E3710(void *p, s32 a);
void func_002DFE40(u8 *p) {
    s8 r = func_00175700(p);
    if (r < 0) {
        func_001843A0(p);
    } else if (*(s8 *)(p + 0x151)) {
        s16 *q;
        *(s8 *)(p + 0x151) = 0;
        p[0x1B5] = 0x45;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        q = (s16 *)(((u32)p[2] << 1) + (u32)D_004C2794);
        q[0x7C / 2] = q[0x7C / 2] + 1;
        func_001E3710(p, 0x16);
    }
}
