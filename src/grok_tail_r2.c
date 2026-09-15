typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern void func_0039E450(u8 *);
extern void func_003DAA40();
extern void func_00184540(u8 *);
extern void func_0011D8F8(void *, s32, s32);
extern void func_001757E0(u8 *, s32, s32);
extern void func_00416A50(void *);
extern void func_003F0E60(void *);
extern void func_003F0C50(void *, void *);
extern void func_003F0A60(void *, void *);
extern void func_003F0DB0(void *, void *);
extern void func_003F0DF0(void *, void *);
extern void func_003F0A40(void *, void *);
extern void func_003F09C0(void *, void *, s32);
extern void func_003F0A20();
extern void func_003DCD40(void *, s32, s32);

extern u8 D_00583B9B;
extern u8 D_00583B90[];
extern u8 D_0044DDA0[];
extern u8 D_004492A0[];
extern char D_004F1CC0[];
extern char D_005BF280[];
extern char D_0062C020[];
extern char D_0038A680[];
extern char D_00632480[];

void func_0039CEF0(u8 *p) {
    s8 *q = *(s8 **)(p + 24);
    q[435]--;
    func_0039E450(p);
}

void func_0037B400(u8 *p, u8 *q) {
    if (q) {
        *(s32 *)(q + 716) = 0;
    }
    func_003DAA40(p, q);
}

void func_002C40D0(u8 *p) {
    p[533] = 0;
    *(s32 *)(p + 92) = 0;
    *(s32 *)(p + 104) = 0;
    *(s32 *)(p + 96) = 0;
    *(s32 *)(p + 108) = 0xBF4DB6DB;
    func_00184540(p);
}

void func_002CAFA0(u8 *p) {
    p[533] = 0;
    *(s32 *)(p + 96) = 0;
    *(s32 *)(p + 104) = 0;
    *(s32 *)(p + 92) = 0;
    *(s32 *)(p + 108) = 0xBF4DB6DB;
    func_00184540(p);
}

void func_00329890(void) { func_0011D8F8(D_004F1CC0, 0, 20); }

void func_0013C5A0(void) {
    D_00583B9B = 2;
    func_003DAA40();
}

void func_0013A480(u8 *p) {
    D_00583B90[p[32]] = 5;
    func_003DAA40(p);
}

void func_001CCF40(u8 *p, s32 a1) {
    func_001757E0(p, 23, D_0044DDA0[a1 & 0xFF]);
}

void func_00191F20(u8 *p, u8 a1) {
    p[34] = a1;
    func_001757E0(p, 26, D_004492A0[p[34] & 15]);
}

void func_0038A690(void) { func_00416A50(D_0038A680); }

void func_003DB9F0(void) { func_003F0E60(D_005BF280); }

void func_003DB9B0(void *p) { func_003F0C50(D_005BF280, p); }

void func_003DB9C0(void *p) { func_003F0A60(D_005BF280, p); }

void func_003DB9D0(void *p) { func_003F0DB0(D_005BF280, p); }

void func_003DB9E0(void *p) { func_003F0DF0(D_005BF280, p); }

void func_003DCFB0(void *p) { func_003F0A40(D_0062C020, p); }

void func_003DCF70(void *p) { func_003F09C0(D_0062C020, p, 0); }

void func_003DCF90(void *p) { func_003F0A20(D_0062C020, 0, p); }

void func_003DCFC0(void *p) { func_003F09C0(D_0062C020, p, 1); }

void func_00413D30(void) { func_003DCD40(D_00632480, 0, 200); }
