typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_004C27D0;
extern u8 *D_004C2840;
extern s8 *D_004C299C;
extern u8 *D_004C2794;
extern u8 D_004BFA40[8];
extern void (*D_004C1C7C[2])(u8 *);
extern u8 D_004F20B0[];
extern u8 D_004F2668[];

extern void func_003D11E0(void);
extern void func_003D1410(void);
extern void func_001757E0(u8 *, s32, s32);
extern void func_00172B50(u8 *);
extern void func_001E3710(u8 *, s32);
extern void func_001C09A0(u8 *, s32);

void func_003D1190(void) {
    switch (D_004C27D0) {
    case 0:
        func_003D11E0();
        break;
    case 4:
        func_003D1410();
        break;
    }
}

void func_0037F440(u8 *p) {
    s16 t = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = t;
    if (t <= 0) {
        *(s16 *)(p + 0x1C) = 1;
        *D_004C299C -= 1;
    }
}

void func_0034B2D0(u8 *p) {
    unsigned int offset;
    *(volatile u8 *)(p + 0x1b5) = 0x50;
    p[0x1b2] = *(u16 *)(p + 0x1c0) = 0;
    *(int *)(p + 0x1d8) = 0;
    offset = p[2] * 2;
    offset += (unsigned int)D_004C2794;
    ++*(short *)(offset + 0x7c);
    func_001757E0(p, 0x16, 0xA);
}

void func_00299D60(u8 *p) {
    unsigned int offset;
    if (*(s8 *)(p + 0x151)) {
        *(s8 *)(p + 0x151) = 0;
        *(volatile u8 *)(p + 0x1b5) = 0x53;
        p[0x1b2] = *(u16 *)(p + 0x1c0) = 0;
        *(int *)(p + 0x1d8) = 0;
        offset = p[2] * 2;
        offset += (unsigned int)D_004C2794;
        ++*(short *)(offset + 0x7c);
    }
}

void func_0036B850(u8 *p) {
    D_004C1C7C[p[5]](p);
    if (*(s8 *)(p + 0x1B2)) {
        p[4] += 1;
        p[0x13C] = 0;
    }
}

void func_001C50B0(u8 *p, u8 *q) {
    p[4] = 2;
    q[0x2B8] = p[0x20];
    *(s32 *)(p + 0xD0) = q[2];
    func_001E3710(p, 0x2A);
    func_001C09A0(p, D_004BFA40[p[0x20]]);
}
