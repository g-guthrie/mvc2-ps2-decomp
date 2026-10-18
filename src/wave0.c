typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00163F70();
extern void func_00414720();
extern void func_00417770(f32, f32);
extern u8 D_004F1F40[];
extern void func_001757E0();
extern void func_00178F20();
extern s8 D_00583B96[];
extern s8 D_00583B94[];
extern s8 D_0043F9A0[][8];
extern s32 func_0028A490();
extern void func_0028A530();
extern void func_0028B0B0();
extern u8 *func_0019A4C0();
extern s32 func_00175700();
extern void func_00126400();
extern s32 D_004D3690[];
extern void func_00123060();
extern void func_00151A20(u8);
extern void func_001520E0(u8);
extern void func_001754A0();
extern void func_001EBBD0();
extern void func_00345830();

void func_001230C0(void) {
    func_00414720(D_004F1F40);
    func_00417770(0.0f, 0.0f);
}

void func_00169BC0(u8 *p, s32 i) {
    u8 *q = p + 0x474;
    q += i * 8;
    func_00163F70(p, q);
}


void func_002F6760(u8 *p) {
    u8 *q = p;
    p = (u8 *)(u32)q[0x20B];
    if ((u32)p == 0xC0) return;
    if ((u32)p == 0xC0) return;
    func_00178F20(*(s32 *)(q + 0x1DC));
}

s32 func_0018AA10(u8 *p, u16 a, u16 *out) {
    u16 v = a & ((*(u16 *)(p + 0x358) ^ *(u16 *)(p + 0x356)) | (*(u16 *)(p + 0x356) ^ *(u16 *)(p + 0x354)));
    *out = v;
    return !(!!(a ^ v) != 0);
}

s32 func_00137F90(u8 i) {
    return D_0043F9A0[D_00583B96[i]][D_00583B94[i]];
}


typedef struct { f32 x, y, z; } V3;
void func_003543E0(u8 *p) {
    u8 *n = func_0019A4C0(p, 8);
    if (n) {
        *(V3 *)(n + 0x34) = *(V3 *)(p + 0x34);
    }
}





void func_0024C110(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        p[6]++;
        func_00126400();
    }
}


void func_001534D0(s32 i) {
    if (D_004D3690[i]) {
        func_00123060();
        func_00151A20(i);
        func_001520E0(i);
    }
}

void func_00199330(u8 *p) {
    u8 *v = *(u8 **)(p + 0x18);
    f32 f = 213.33333f;
    u8 *a2 = *(u8 **)(v + 0x220);
    if (*(s16 *)(v + 0x140) != 0) f = -f;
    *(f32 *)(p + 0x34) = *(f32 *)(a2 + 0x34) + f;
    *(f32 *)(p + 0x38) = *(f32 *)(a2 + 0x38);
    *(s16 *)(p + 0x140) = *(s16 *)(v + 0x140);
    func_001754A0(p, 0x1B, (u8)(p[0x21] * 2 + 0x10));
}

void func_001EBDB0(u8 *p) {
    func_001EBBD0(p);
    func_00175700();
    if (*(s8 *)(p + 0x151) != 0) {
        *(s8 *)(p + 0x151) = 0;
        p[6]++;
        func_00345830(p, 1);
    }
}

void func_00186EA0(u8 *p) {
    u8 v;
    *(s32 *)(p + 0x5C) = 0;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    p[0x210] = 0;
    p[0x20D] = 0;
    v = (*(u16 *)(p + 0x35E) & 0x400) >> 10;
    p[0x1E7] = v;
    if (p[0x216] & 0x80) v += 6;
    func_001757E0(p, 0, (u8)(v + 2));
}

void func_001B5EA0(u8 *p) {
    p[6]++;
    func_001754A0(p, 0x1B, p[0x20]);
    *(s16 *)(p + 0x140) = 0;
    *(f32 *)(p + 0x38) += 154.28571f;
}


s32 func_00370730(u8 *a0, u8 *a1, u8 *a2) {
    if (*(s32 *)(a2 + 8) != 0) {
        u8 *t = *(u8 **)(a1 + 0x220);
        a1[0x1FE] = 1;
        if (a0[5] == 5) {
            *(f32 *)(t + 0x34) = *(f32 *)(a0 + 0x34);
            *(f32 *)(t + 0x38) = *(f32 *)(a0 + 0x38);
            t[0x13C] = 1;
            t[0x20A] = 0xF;
            t[0x1B5] = 0x23;
            *(s32 *)(a2 + 8) = 0;
        }
    }
    return *(s32 *)(a2 + 8);
}
