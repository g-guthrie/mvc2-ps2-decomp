typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern void func_00309310(void);
extern void func_0030A450(void);
extern void func_00337BA0(int);
extern void func_00337ED0(void);
extern void func_00337F30(int);
extern void func_0033AA20(int);
extern void func_003422F0(int);
extern void func_00359260(u8 *, u8 *);
extern void func_00359350(u8 *, u8 *);
extern void func_00359A90(u8 *);
extern void func_00359AE0(u8 *);
extern void func_00359B80(u8 *);
extern void func_00359BD0(u8 *);
extern void func_00359C20(u8 *);
extern void func_0036EB40(u8 *);
extern void func_003DAA40(u8 *);
extern void func_003C1250(u8 *, int, int);

void func_0030A680(void) {
    func_0030A450();
    func_00309310();
}

void func_00337630(u8 *p) {
    u8 *q = *(u8 **)(p + 0x14);
    if (q[5])
        p[0x13C] = 1;
    else
        p[0x13C] = 0;
}

void func_00337B70(u8 *p) {
    if (--*(s32 *)(p + 0xD8) == 0) {
        p[6] = 0;
        p[4] = 1;
    }
}

void func_0033AB20(void) {
    func_0033AA20(0);
    func_0033AA20(1);
}

void func_003422C0(void) {
    func_003422F0(0);
    func_003422F0(1);
}

void func_00345B40(u8 *p) {
    u8 *q;
    p[4] = 2;
    q = *(u8 **)(p + 0x18) + 0x2B8;
    if (p[0x20] == 0)
        q[2] = 0;
}

void func_0032D110(u8 *p) {
    f32 r = *(f32 *)(p + 8) / (f32)*(s32 *)(p + 4);
    *(f32 *)(p + 0x18) = r;
    *(f32 *)(p + 0x14) = r;
}

void func_0032D130(u8 *p) {
    f32 r = *(f32 *)(p + 0xC) / (f32)*(s32 *)(p + 4);
    *(f32 *)(p + 0x20) = r;
    *(f32 *)(p + 0x1C) = r;
}

void func_0032D150(u8 *p) {
    f32 r = *(f32 *)(p + 0x10) / (f32)*(s32 *)(p + 4);
    *(f32 *)(p + 0x28) = r;
    *(f32 *)(p + 0x24) = r;
}

void func_00347A70(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    p[4]++;
    q[0x2B8] = 0;
    p[0x13C] = 0;
}

void func_00359310(u8 *p, u8 *q) {
    p[5]++;
    *(unsigned short *)(q + 8) = 0xFFFF;
    func_00359260(p, q);
}

void func_003593B0(u8 *p, u8 *q) {
    p[5]++;
    *(unsigned short *)(q + 8) = 0xFFFF;
    func_00359350(p, q);
}

void func_00359AA0(u8 *p) {
    p[5]++;
    p[6] = 0;
    *(s8 *)(p + 0x31) = -2;
    func_00359A90(p);
}

void func_00359AF0(u8 *p) {
    p[5]++;
    p[6] = 0;
    *(s8 *)(p + 0x31) = -2;
    func_00359AE0(p);
}

void func_00359B90(u8 *p) {
    p[5]++;
    p[6] = 0;
    *(s8 *)(p + 0x31) = -2;
    func_00359B80(p);
}

void func_00359BE0(u8 *p) {
    p[5]++;
    p[6] = 0;
    *(s8 *)(p + 0x31) = -2;
    func_00359BD0(p);
}

void func_00359C30(u8 *p) {
    p[5]++;
    p[6] = 0;
    *(s8 *)(p + 0x31) = -2;
    func_00359C20(p);
}

void func_0036E9C0(u8 *p, u8 *q) {
    u8 *r = *(u8 **)(q + 0x1DC);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430) + (*(f32 *)(p + 0x38) - *(f32 *)(r + 0x38));
    func_0036EB40(p);
}

void func_0037B400(u8 *p, u8 *q) {
    if (q)
        *(s32 *)(q + 0x2CC) = 0;
    func_003DAA40(p);
}

void func_00337B40(u8 *p) {
    if (--*(s16 *)(p + 0x1C) == 0)
        p[4] = 0;
}

void func_0034CF30(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + *(f32 *)(p + 0x64);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) + *(f32 *)(p + 0x70);
}

void func_00338020(void) {
    func_00337BA0(0x14);
    func_00337F30(0x29);
    func_00337ED0();
}

void func_00313C40(u8 *p) {
    if ((*(s16 *)(p + 0x1C) & 3) == 0)
        func_003C1250(p, 3, 0);
}

void func_0035AE70(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18) + 0x2B8;
    if (p[0x20] == 0)
        p[0x21] = 0;
    q[0xE] = p[0x20];
    q[0xF] = p[0x21];
    p[5] = 0;
}

extern s32 D_004F1CC8;
extern s32 D_004F1CC4;
extern s32 D_004F1CC0;
extern s32 D_004F1CCC;
extern s32 D_004F1CD0;

void func_003298B0(s32 a, s32 b, s32 c) {
    D_004F1CC8 = a;
    D_004F1CC4 = c;
    D_004F1CC0 = 1;
    D_004F1CCC = b;
    D_004F1CD0 = b;
}


