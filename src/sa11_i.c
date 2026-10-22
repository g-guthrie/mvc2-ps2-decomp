typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x4A]; u8 f4A[1]; } G_i;
extern G_i *D_004C2794;
extern u8 D_004D18A1[];
typedef struct { u8 *q; s32 a; s32 b; } T_i;
extern T_i D_004D18BC[];

void func_00187A70(u8 *p) {
    u8 *q;
    s32 k;
    s32 r;
    if (p[0x1E4] != 0x1D) return;
    switch (p[0x268]) {
    case 0:
        if (D_004D18A1[0] & 4) return;
        q = D_004D18BC[p[2]].q;
        k = q[0x1B8];
        if (D_004C2794->f4A[q[2]] & (1 << (k / 2))) return;
        if (q[0] != 0) return;
        if (*(s16 *)(q + 0x434) <= 0) return;
        if (*(s16 *)(q + 0x2B4) != 0) return;
        *(u16 *)(q + 0x354) = *(u16 *)(p + 0x354);
        *(u16 *)(q + 0x35C) = *(u16 *)(p + 0x35C);
        *(u16 *)(q + 0x356) = *(u16 *)(p + 0x356);
        *(u16 *)(q + 0x358) = *(u16 *)(p + 0x358);
        *(u16 *)(q + 0x35A) = *(u16 *)(p + 0x35A);
        *(u16 *)(q + 0x35E) = *(u16 *)(p + 0x35E);
        *(u16 *)(q + 0x362) = *(u16 *)(p + 0x362);
        *(u16 *)(q + 0x360) = *(u16 *)(p + 0x360);
        r = (**(s32 (**)(u8 *))(*(u8 **)(q + 0x43C) + 0x34))(q);
        if (r) {
            p[0x268] = 6;
            p[0x26B] = 1;
            return;
        }
        break;
    default:
        break;
    }
}
