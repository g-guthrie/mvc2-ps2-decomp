typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef unsigned int u32;

extern void func_0039E450(u8 *);
extern void func_003DAA40();
extern void func_00184540(u8 *);
extern void *func_0011D8F8(void *, s32, u32);
extern int func_001757E0(u8 *, int, int);
extern void func_00416A50(void *);
extern void func_003F0E60(void *);
extern s32 func_003F0C50(u8 *, s32);
typedef struct {s32 f0;u32 f4;s32 f8,fC,f10;u32 f14,f18;} S3F;
extern u32 func_003F0A60(S3F *,u32);
extern s32 func_003F0DF0(void *, s32);
extern void func_003F0A40(void *, void *);
extern void *func_003F09C0(void *, u32, s32);
extern void func_003F0A20();
extern void func_003DCD40(void *, s32, s32);

extern u8 D_00583B9B;
extern u8 D_00583B90[];
extern u8 data_u8_0044DDA0[18];
extern u8 D_004492A0[];
extern char D_004F1CC0[];
extern char D_005BF280[];
extern char D_0062C020[];
extern char D_0038A680[];
extern char D_00632480[];

void func_00329890(void) { func_0011D8F8(D_004F1CC0, 0, 20); }

void func_001CCF40(u8 *p, s32 a1) {
    func_001757E0(p, 23, data_u8_0044DDA0[a1 & 0xFF]);
}

void func_00191F20(u8 *p, u8 a1) {
    p[34] = a1;
    func_001757E0(p, 26, D_004492A0[p[34] & 15]);
}

void func_00413D30(void) { func_003DCD40(D_00632480, 0, 200); }
