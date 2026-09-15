typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern signed char *D_004C2840;
extern void *D_004C2804;
extern void *D_004C2810;
extern void *D_004C2818;
extern char D_0014C3D0[];
extern char D_00148DE0[];
extern char D_001444C0[];
extern char D_00141130[];
extern u8 D_004D17CA[];
extern void (*D_00442570[])(u8 *);

extern void func_0012AC70(s32, void *);
extern void func_0012ACC0(s32);
extern void func_0012AD00(void);
extern void func_00149AD0(u8 *);
extern void func_003298B0(s32, s32, s32);
extern void func_003DAA40(u8 *);
extern u8 *func_003DA750(s32, s32, s32);

void func_0014E770(u8 *p) {
    u8 *q = *(u8 **)(p + 24);
    if (*(s32 *)(q + 220) != 0) {
        if (q[4] == 1) {
            *(s16 *)(p + 30) = *(s16 *)(q + 30);
        } else {
            *(s16 *)(p + 30) = *(s16 *)(q + 30);
        }
    }
}

void func_0014D630(void) {
    u8 *p = func_003DA750(0, 13, 1);
    if (p) {
        p[316] = 1;
        *(char **)(p + 16) = D_0014C3D0;
        *(s32 *)(p + 208) = 0;
    }
}

void func_0014A380(u8 *p) {
    if (D_004C2840[4] == p[32]) {
        p[316] = 1;
        func_0012AD00();
    } else {
        p[316] = 0;
        *(s16 *)(p + 30) = 0;
    }
}

void func_00149A70(u8 *p) {
    u8 t = p[4];
    if (t != 0) {
        func_00149AD0(p);
    } else {
        if (D_004D17CA[0] != p[35]) {
            p[4] = (u8)(t + 1);
            p[316] = 0;
        }
    }
}

void func_00146B80(u8 *p) {
    if (p[4] == 0) {
        p[4] = (u8)(p[4] + 1);
        p[316] = 1;
        *(s32 *)(p + 52) = 0xBF86A7F0;
        *(s32 *)(p + 56) = 0x400B020C;
        *(s16 *)(p + 204) = 0x53;
        *(void **)(p + 132) = D_004C2804;
    }
}

void func_00148F80(void) {
    func_0012ACC0(0);
    D_004C2840[2] = 0;
    D_004C2840[3] = 0;
    func_003298B0(0xFF000000, 10, 1);
    func_0012AC70(1, D_00148DE0);
}

void func_0014C710(u8 *p) {
    func_0012AD00();
    if (*(f32 *)(p + 116) >= 1.0f) {
        *(s32 *)(p + 116) = 0x3F7D70A4;
    }
}

void func_00144460(void) {
    u8 *p = func_003DA750(0, 6, 1);
    if (p) {
        p[316] = 1;
        *(char **)(p + 16) = D_001444C0;
        *(s16 *)(p + 204) = 8;
        *(void **)(p + 132) = D_004C2810;
        *(s32 *)(p + 208) = 0x800;
    }
}

void func_001410D0(void) {
    u8 *p = func_003DA750(0, 13, 1);
    if (p) {
        p[316] = 1;
        *(char **)(p + 16) = D_00141130;
        *(s16 *)(p + 204) = 9;
        *(void **)(p + 132) = D_004C2818;
        *(s32 *)(p + 208) = 0x800C00;
    }
}

void func_00144EF0(u8 *p) {
    if (D_004C2840[2] != 3) {
        func_003DAA40(p);
    } else {
        D_00442570[p[4]](p);
    }
}




