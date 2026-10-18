typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;


void func_002D33E0(u8 *p) {
    extern void func_001820A0();
    extern u32 D_004C0F80[2];
    if (p[0x20D] == 2) {
        func_001820A0();
        if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        }
    }
    ((void (*)(u8 *))D_004C0F80[p[6]])(p);
}

typedef struct { u8 pad[0x7C]; s16 h7c[1]; } G7C;

void func_00240140(u8 *p) {
    extern s8 func_00175700();
    extern void func_00184540();
    extern G7C *D_004C2794;
    if (func_00175700(p) < 0) {
        func_00184540(p);
        return;
    }
    switch (p[0x1FC]) {
    case 0:
        break;
    case 1:
        break;
    case 2:
        if (p[0x15B] != 0) {
            p[0x1B5] = p[0x15B];
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            {
                s16 *q = (s16 *)((p[2] << 1) + (u32)D_004C2794);
                q[0x7C / 2] = q[0x7C / 2] + 1;
            }
            p[0x15B] = 0;
        }
        break;
    }
}
