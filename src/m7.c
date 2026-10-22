typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00291800(u8 *a);
extern void func_002918A0(u8 *a, u8 *b);
extern void func_00292420(u8 *a, u8 *b);
/* func_00291860: not yet matched without a stand-in callee. */

static void cp3(u8 *d, s8 *s) {
    d[0x544] = s[0];
    d[0x545] = s[1];
    d[0x546] = s[2];
}


extern void *func_003DA750(s32, s32, s32);
extern void func_0034FB40();
void func_0034FAE0(u8 *p) {
    u8 *r = func_003DA750(0, 1, 0);
    if (r) {
        *(void **)(r + 0x10) = func_0034FB40;
        *(u32 *)(r + 0x18) = *(u32 *)(p + 0x18);
        *(u8 **)(r + 0x14) = p;
        r[0x20] = 2;
        *(s16 *)(r + 0x26) = 0x503;
    }
}

extern u8 D_00584B50[], D_004B85C0[], D_004B85A0[], D_004B85D0[];
extern u32 D_00464CA4;
extern void func_0011F938();
void func_0038CFB0(s32 a) {
    if (!a) {
        func_0011F938(D_00584B50, D_004B85C0, D_004B85A0, D_00464CA4, D_004B85A0, D_00464CA4);
    } else {
        func_0011F938(D_00584B50, D_004B85D0);
    }
}

extern void func_00395A00();
void func_00395990(u8 *p, s32 b) {
    u8 *r = func_003DA750(0, 2, 0);
    if (r) {
        *(void **)(r + 0x10) = func_00395A00;
        *(u8 **)(r + 0x18) = p;
        *(u32 *)(r + 0xD0) = *(u16 *)(p + 0x168);
        r[0x20] = b;
        *(s16 *)(r + 0x26) = 0x2200;
    }
}

extern u8 D_004F20B0[];
extern void func_001843A0(u8 *);
void func_003D9440(void) {
    s32 i = 0;
    u8 *p = 0;
    do {
        u8 *q = D_004F20B0 + (s32)p;
        if (q[0x1E4] == 0x16) func_001843A0(q);
        i++;
        p += 0x5B8;
    } while (i < 6);
}

extern void func_00163050(u8 *, s32);
extern void func_001631B0(u8 *, s32);
extern void func_00163310(u8 *, s32);
extern void func_00163480(u8 *, s32);
extern void func_001635F0(u8 *, s32);
extern void func_00163760(u8 *, s32);
void func_00163930(u8 *a, s32 b) {
    func_00163050(a, b);
    func_001631B0(a, b);
    func_00163310(a, b);
    func_00163480(a, b);
    func_001635F0(a, b);
    func_00163760(a, b);
}

extern void func_00363CB0();
void func_00363C30(u8 *a, u8 *b, s32 c, s32 d) {
    u8 *r = func_003DA750(0, 1, 0);
    if (r) {
        *(void **)(r + 0x10) = func_00363CB0;
        *(u8 **)(r + 0x18) = a;
        *(u8 **)(r + 0x14) = b;
        r[0x20] = c;
        r[0x23] = d;
    }
}

extern void func_003C8650();
void func_003C8780(u8 *a, u8 *b) {
    if (b[5]) {
        func_003C8650(a, b);
    } else {
        u32 t = b[0x1E4];
        if (t != 0x1D && t != 0x16) {
            func_003C8650(a, b);
        } else {
            *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34);
            *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38);
            *(s8 *)(a + 0x24) = *(s8 *)(b + 0x24);
            *(s8 *)(a + 0x31) = *(s8 *)(a + 0x1E);
        }
    }
}


