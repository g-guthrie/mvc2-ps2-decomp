typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern void func_0039E450();
extern void func_003DD020();
extern void func_003F09C0();
extern void func_003F0A40();
extern void func_003F0A60();
extern void func_003F0C50();
extern void func_003F0DB0();
extern void func_003F0DF0();
extern void func_003F0E60();
extern void func_0040EF48();
extern void func_00416A50();
s32 func_003F0A20(s32 *p, s32 i, s32 *out);

extern u8 D_0038A680[];
extern u8 D_004D18D3;
extern u8 D_004D1901;
extern u8 D_004F1F40;
extern u8 D_004F1F47;
extern u8 D_004F1F48;
extern s16 D_004F7D1E;
extern s16 D_004F7D2E;
extern s16 D_004F7F7A;
extern s16 D_004F7F7C;
extern u8 D_005BF280[];
extern u8 D_0062C020[];

void func_003880A0(u8 *p, s8 *q) {
    if (!q[0x1b4])
        p[6] = 0;
}

void func_0038A690(void) { func_00416A50(D_0038A680); }

void func_0039CEF0(u8 *p) {
    s8 *q = *(s8 **)(p + 24);
    q[435]--;
    func_0039E450();
}

void func_0039D100(u8 *p) {
    if (!*(s8 *)(p + 434)) {
        p[435] = 4;
        p[5]++;
    }
}

void func_003B9F00(u8 *p) {
    u8 *q = *(u8 **)(p + 24);
    if (q[4] != 1) {
        p[4]++;
        p[316] = 0;
    }
}

void func_003B9F30(u8 *p) {
    u8 *q = *(u8 **)(p + 24);
    if (q[4] != 1) {
        p[4]++;
        p[5] = 0;
        p[316] = 0;
    }
}

s32 func_003BD650(u8 *p) {
    u8 v = *(u8 *)(*(u8 **)(p + 24) + 5);
    if (v == 3)
        return -1;
    return 0;
}

void func_003C3910(u8 *p) {
    s16 v = *(s16 *)(p + 28);
    *(s16 *)(p + 28) = v - 1;
    if (v == 0) {
        p[5]++;
        p[316] = 1;
    }
}

void func_003D2020(void) {
    D_004F1F47 = 0;
    D_004F1F48 = 0;
    D_004F1F40 = 1;
}

void func_003D6AC0(void) {
    D_004F7F7C = 0;
    D_004F7D1E = 0;
    D_004F7D2E = 0;
    D_004F7F7A = 0;
}

void func_003D9080(void) {
    D_004D18D3 = 0;
    D_004D1901 = 0;
}

void func_003DB9B0(void *p) { func_003F0C50(D_005BF280, p); }
void func_003DB9C0(void *p) { func_003F0A60(D_005BF280, p); }
void func_003DB9D0(void *p) { func_003F0DB0(D_005BF280, p); }
void func_003DB9E0(void *p) { func_003F0DF0(D_005BF280, p); }
void func_003DB9F0(void) { func_003F0E60(D_005BF280); }

void func_003DCF70(void *p) { func_003F09C0(D_0062C020, p, 0); }
void func_003DCF90(void *p) { func_003F0A20((s32 *)D_0062C020, 0, p); }
void func_003DCFB0(void *p) { func_003F0A40(D_0062C020, p); }
void func_003DCFC0(void *p) { func_003F09C0(D_0062C020, p, 1); }

s32 func_003DE860(void) {
    func_003DD020();
    return 1;
}

s32 func_003F0A20(s32 *p, s32 i, s32 *out) {
    out[0] = p[i + 3];
    out[1] = i;
    return 1;
}

s32 func_003FF338(void) {
    func_0040EF48();
    return 0;
}
