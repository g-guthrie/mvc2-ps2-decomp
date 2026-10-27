typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef float f32;
extern volatile s8 D_004F7F6A[];
extern s8 D_004F1F47[];
extern u8 D_004F1F45;
extern u8 D_004F1F46;
extern u32 D_00448940[];
extern void func_003D3750(void);
extern void func_002F7240(u8 *);
extern void func_002F7540(u8 *, s32);
extern s32 func_00175670(u8 *);
extern void func_0015D8F0(f32 *, s32);
extern void func_003C1CF0(u8 *);
extern void func_002555E0(void);
extern s32 func_00175700(u8 *);
extern void func_001230F0(void);
extern void func_00123120(void);
extern void func_0015B200(u8 *, u8 *, s32, s32);
extern void func_001E3710(u8 *, s32);
extern void func_0039E450(u8 *);
extern void func_00177CE0(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_001AB600(u8 *, u8 *);
extern void func_002FA200(u8 *);
extern void func_00184540(u8 *);
extern s32 func_003246B0(u8 *);
extern s32 func_00324830(u8 *);
extern s32 func_00324590(u8 *);

void func_003D4920(void) { func_003D3750(); switch (D_004F7F6A[0]) { case 0: break; } }

void func_002F7210(u8 *p) { func_002F7240(p); func_002F7540(p, (s32)(p + 0x2B8)); }

s32 func_001CB5D0(u8 *p) { s32 r = func_00175670(p); p[0x159] = 0xE0; return (s8)r; }

void func_00183D10(u8 *p) {
    f32 v[3];
    v[0] = *(f32 *)(p + 0x34);
    v[1] = *(f32 *)(p + 0x430);
    v[2] = *(f32 *)(p + 0x3C);
    func_0015D8F0(v, *(s16 *)(p + 0x140));
}

void func_00123200(void) {
    switch (D_004F1F47[0]) {
    case 0:
        func_001230F0();
    case 1:
        func_00123120();
    }
}

s32 func_001896E0(u8 *a, u8 *b, u8 *c) {
    if ((*(u16 *)(a + 0x35E) & *(u16 *)(b + 8)) == 0) { return c[0] = 0; }
    c[1] = *(s8 *)b;
    c[2] = a[0x1E6];
    c[0] += 1;
    return 0;
}

void func_003361A0(u8 *p) {
    s32 d = -0x889;
    if (*(s16 *)(p + 0x1E) != 0) d = 0x889;
    *(s32 *)(p + 0x44) += d;
    if (*(s16 *)(p + 0x1C) != 0) {
        *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) - 1;
    } else {
        *(s16 *)(p + 0x140) ^= 1;
        p[7] = 0;
        p[5] = 0;
    }
}

void func_0039DAC0(u8 *p) {
    p[4]++;
    func_0015B200(p, p + 0x34, 1, 8);
    func_001E3710(p, 0x49);
    func_0039E450(p);
}

void func_001779D0(u8 *p) {
    p[0x208] = 2;
    p[0x209] = 2;
    p[0x13C] = 1;
    func_00177CE0(p);
    ((void (*)(u8 *))D_00448940[p[6]])(p);
}

void func_001AB5A0(u8 *p, u8 *q) {
    p[7]++;
    *(s16 *)(p + 0x140) = *(s16 *)(q + 0x140);
    func_001757E0(p, 0x17, 0x1B);
    func_001AB600(p, q);
}

void func_00218A30(u8 *p) {
    if (*(s8 *)(p + 0x150) != 0) {
        if (*(s8 *)(p + 0x539) == 0) {
            if (((u16)(*(u16 *)(p + 0x35C) | *(u16 *)(p + 0x366)) & 0x300) != 0) {
                *(s16 *)(p + 0x1C) = 1;
                *(s16 *)(p + 0x366) = 0;
            }
        } else if (p[0x425] == 0) {
            *(s16 *)(p + 0x1C) = 1;
        }
    }
}



void func_00324230(u8 *p) {
    if (func_003246B0(p) == 0 && func_00324830(p) == 0 && func_00324590(p) == 0) func_00175700(p);
}
