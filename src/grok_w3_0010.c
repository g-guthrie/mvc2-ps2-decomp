typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_00438250;
extern s32 D_0043B6F8;
extern s32 D_00438304;
extern s32 D_004C3C00[];
extern s32 D_004C3AE4;
extern s32 D_004C3AEC;

extern void func_0010D090(s32);
extern void func_00103E00(s32);
extern s32 func_001041F0(s32);

void func_001001C8(void) { func_0010D090(0); }

void func_00104260(void) { D_00438250 = 0; }

s32 func_0011B370(void) { return D_0043B6F8; }

void func_00107AE8(void) { func_00103E00(D_00438304); }

s32 func_00105F10(s32 i) { return D_004C3C00[i]; }

s32 func_00105F28(s32 i, s32 v) { return D_004C3C00[i] = v; }

void func_00105EE0(s32 *a0, s32 *a1) {
    s32 *tbl = (s32 *)a1[7];
    tbl[a0[4]] = a0[5];
}

s32 func_00119D88(s32 x) { return x < 0 ? -x : x; }

void func_001037B8(f32 *d, f32 *s) {
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
}

s32 func_0010C038(void) {
    return (func_001041F0(4) & 0x10000) != 0;
}

void func_0011DB30(s32 *a0, s32 *a1) {
    if (!a1) {
        return;
    }
    a0 = (s32 *)((u8 *)*(s32 **)((u8 *)a0 + 76) + (a1[1] << 2));
    *a1 = *a0;
    *a0 = (s32)a1;
}

void func_00106270(s32 a0) {
    s32 v1 = a0 << 3;
    s32 base = a0 >= 0 ? D_004C3AE4 : D_004C3AEC;
    *(s32 *)(v1 + base) = 0;
}

void func_00106240(s32 a0, s32 a1, s32 a2) {
    s32 v1 = a0 << 3;
    s32 base = a0 >= 0 ? D_004C3AE4 : D_004C3AEC;
    *(s32 *)(v1 + 4 + base) = a2;
    *(s32 *)(v1 + base) = a1;
}

u8 *func_0010CE78(u8 *a0, u8 *a1, u32 a2) {
    u32 a3 = 0;
    if (a2) {
        do {
            u8 v = *a1;
            a3++;
            a1++;
            *a0 = v;
            a0++;
        } while (a3 < a2);
    }
    return a0;
}


