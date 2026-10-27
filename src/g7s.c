typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern float *D_004C26D0;

void func_00192E30(u8 *p) {
    *(float *)(p + 0x34) = *(float *)(*(u8 **)(p + 0x18) + 0x34);
    *(float *)(p + 0x38) = *(float *)(*(u8 **)(p + 0x18) + 0x38);
    if (*(s16 *)(p + 0x140) != 0) {
        *(float *)(p + 0x34) += D_004C26D0[0];
    } else {
        *(float *)(p + 0x34) -= D_004C26D0[0];
    }
    *(float *)(p + 0x38) += D_004C26D0[1];
}

extern u8 D_004C12E0[2];
extern void func_001757E0();
extern void func_002F4210();

void func_002F41A0(u8 *p, u16 *q) {
    u32 t = p[6];
    p[6] = t + 1;
    *(s8 *)(p + 0x1B1) = -128;
    p[0x201] = 0;
    p[0x206] = 0;
    func_001757E0(p, 0x15, D_004C12E0[*q]);
    func_002F4210(p, q);
}

typedef struct V3 { float x, y, z; } V3;
extern s32 D_004C283C;
extern V3 D_0045EDD0;
extern u8 *func_003DA750();
extern void func_0033C810();

void func_0033C820(void) {
    u8 *r = func_003DA750(0, 6, 1);
    if (r != 0) {
        r[0x13C] = 1;
        *(void **)(r + 0x10) = func_0033C810;
        *(s16 *)(r + 0xCC) = 0xB;
        *(s32 *)(r + 0x84) = D_004C283C;
        *(V3 *)(r + 0x34) = D_0045EDD0;
        *(s32 *)(r + 0xD0) = 0x901;
    }
}

extern u8 *D_004C2840;
extern volatile s8 D_00583BC7[];
extern s8 D_00583B92[];
extern s8 D_00583B90[];
extern void func_0032E350();

void func_0032C320(void) {
    *(s8 *)(D_004C2840 + 4) += 1;
    *(s16 *)(D_004C2840 + 8) = 0x3C;
    D_00583B92[D_00583BC7[0]] = 0x77;
    func_0032E350(D_00583BC7[0]);
    D_00583B90[D_00583BC7[0]] = 0;
}

extern u16 *D_004C29AC;
extern u8 *D_004C29A8;
extern void func_003859F0(u8 *);
extern int func_00175700(u8 *);

void func_00385970(u8 *a0) {
    u8 *a1 = *(u8 **)(a0 + 0x18);
    if (*D_004C29AC != *(u16 *)(a1 + 0x168)) {
        func_003859F0(a0);
    } else {
        *(float *)(a0 + 0x34) = *(float *)(a1 + 0x34);
        *(float *)(a0 + 0x38) = *(float *)(a1 + 0x38);
        if (D_004C29A8[1] != 0) {
            func_00175700(a0);
        } else {
            func_003859F0(a0);
        }
    }
}
