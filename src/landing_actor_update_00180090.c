typedef struct { unsigned char bytes[28]; } Frame;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef signed int s32;
extern int func_00175700(u8 *);
extern s32 func_001864A0(u8 *);
extern void func_0018F730(u8 *);
extern void func_001E3A10(u8 *);
extern void func_00158C70(u8 *, int);
extern s32 func_00186CE0(u8 *, u8);
extern u8 D_004F1F45, D_004F1F46;
void func_00180090(u8 *p) {
    func_00175700(p);
    *(float *)(p+0x34) += *(float *)(p+0x5c);
    *(float *)(p+0x5c) += *(float *)(p+0x68);
    *(float *)(p+0x38) += *(float *)(p+0x60);
    *(float *)(p+0x60) += *(float *)(p+0x6c);
    if (func_001864A0(p)) {
        { u8 *q = *(u8 **)(p+0x1dc);
          *(u8 **)(p+0x1d0) = (u8 *)&((Frame *)*(u8 **)(q+0x184))[p[0x1b5]&0x7f]; }
        func_0018F730(p);
        *(u16 *)(p+0x140) = p[0x1e6];
        func_001E3A10(p);
        func_00158C70(p+0x34, p[2]);
        D_004F1F45 = 3;
        D_004F1F46 = 1;
        p[0x20d] = 3;
        *(u16 *)(p+0x1fa) = p[0x209] = 64;
        p[0x1f7] = 100;
        func_00186CE0(p,23);
    }
}
