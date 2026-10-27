typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C2840;
extern u8 *D_004C2794;
extern u8 D_004C26B0;
extern u8 D_004C26AC;
extern s8 D_004C2864;
extern s8 *D_004C29C4;
extern u8 *D_004C2954;
extern u8 D_004C1258[8];
extern u16 D_004C1260[4];
extern void (*D_004BFE30[2])(u8 *, u8 *);
extern void (*D_004BFE20[2])(u8 *);
extern void (*const D_004BF790[14])(u8 *, void *) __attribute__((section(".sdata")));
extern void (*D_004771B0[])(void);
extern s32 (*D_0045E930[])(u8 *);
extern s32 D_004F1CB4[];
extern s32 D_004F1CB8[];
extern s32 D_004F1CBC[];

void func_00219260(u8 *p) {
    p[0x1B5] = *(s8 *)(p + 0x22) + 0x52;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    { u32 offset = p[2] * 2; offset += (u32)D_004C2794; ++*(s16 *)(offset + 0x7C); }
    p[0x2BA] = p[0x286];
}



extern void func_001757E0(u8 *, s32, u8);
void func_002E76A0(u8 *p) {
    s32 a;
    s32 b;
    if (p[0x20D] == 0) {
        b = 1;
        a = 0x3A;
    } else {
        b = 2;
        a = 0x3B;
    }
    p[0x1B5] = a;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    { u32 offset = p[2] * 2; offset += (u32)D_004C2794; ++*(s16 *)(offset + 0x7C); }
    func_001757E0(p, 0x16, b);
}

extern void func_00175670(u8 *);
void func_00334B40(u8 *p) {
    p[0x13C] = 1;
    if (D_0045E930[p[5]](p)) p[4] = 3;
}

extern void func_0020D2A0(u8 *, u8 *);


extern s32 func_003D92F0(u8 *);
extern void func_001843A0(u8 *);


void func_001A72C0(u8 *a,void *owner_context) {
    u8 *b=owner_context;
    *(s8 *)(a + 0x24) = *(s8 *)(b + 0x24);
    if (b[0x169] != 0x13) a[4]++;
    else D_004BF790[a[5]](a, b);
}
extern void (*D_004C2158[2])(u8 *, u8 *) __attribute__((section(".sdata")));
void func_003C4550(u8 *a, u8 *b) {
    *(s8 *)(a + 0x24) = *(s8 *)(b + 0x24);
    if (b[0x169] != 0x16) a[4]++;
    else D_004C2158[a[5]](a, b);
}

extern void func_003DAA40(u8 *);
void func_0013DEC0(u8 *p) {
    if (*(s16 *)(D_004C2840 + 0xE)) {
        p[5]++;
        *(s16 *)(p + 0x1C) = 0;
        p[0x13C] = 1;
        if (p[0x21]) func_003DAA40(p);
    }
}

extern s32 func_0012ABC0(s32, s32);
extern s32 func_0012A990(s32, s32, s32, s32);
void func_0012A120(u8 *p) {
    s32 r = func_0012ABC0(3, 0);
    D_004C2864 = func_0012A990(r, D_004C2864, 3, 2);
    p[1] = D_004C2864;
}

extern void func_001E3710(u8 *, u8);
void func_002F1D90(u8 *p) {
    u32 v = D_004C1258[*(s32 *)(p + 0x2D4)];
    if (v) func_001E3710(p, v);
    *(u16 *)(p + 0x1C0) = D_004C1260[*(s32 *)(p + 0x2D4)];
}

typedef struct { float x, y, z; } V3;
extern void func_0015B200(u8 *, V3 *, s32, s32);
extern void func_00350FD0(u8 *);
void func_00350A60(u8 *p) {
    V3 v;
    v = *(V3 *)(p + 0x34);
    func_0015B200(p, &v, 1, 0xC9);
    D_004C2954[3] = 0;
    func_00350FD0(p);
}

extern void func_0016F0D0(void);
void func_003D2B30(void) {
    D_004771B0[*(s8 *)(D_004C2840 + 2)]();
    func_0016F0D0();
}

extern s8 func_00175700(u8 *);
void func_00374DB0(u8 *p) {
    u8 *q;
    if (func_00175700(p) < 0) p[4]++;
    q = *(u8 **)(p + 0x18);
    *(float *)(p + 0x34) = *(float *)(q + 0x34);
    *(float *)(p + 0x38) = *(float *)(q + 0x38);
}

void func_003C1140(u8 *p) {
    s16 n;
    func_00175700(p);
    *(s8 *)(p + 0x13C) ^= 1;
    n = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = n;
    if (n == 0) p[4]++;
}
