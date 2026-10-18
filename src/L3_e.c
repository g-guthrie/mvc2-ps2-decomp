typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x51]; s8 b51; } G3e;

extern u16 D_004C291C[16];
extern s8 D_00583BDF[];
extern s8 D_00583BDE[];
extern G3e *D_004C2840;
extern s8 D_004B7630[];
extern s8 D_004B7650[];
extern s8 D_004C27C4;
extern s8 D_004C27C0;
extern s8 D_004C27D0;

s32 func_0032A570(u8 *p) {
    extern void func_001E3CE0(s32);
    extern s32 func_00417A40(void);
    s32 old, cur;
    s8 n;
    old = D_00583BDF[0];
    n = D_00583BDE[0] + D_004C2840->b51 + 10;
    if (D_004C291C[*(s8 *)(p + 0x538)] & 0x3000) {
        func_001E3CE0(1);
        if (D_004C291C[*(s8 *)(p + 0x538)] & 0x2000) {
            D_00583BDF[0] = (D_00583BDF[0] + n - 1) % n;
        }
        if (D_004C291C[*(s8 *)(p + 0x538)] & 0x1000) {
            D_00583BDF[0] = (D_00583BDF[0] + n + 1) % n;
        }
    }
    if (D_004C291C[*(s8 *)(p + 0x538)] & 0xC00) {
        func_001E3CE0(4);
        if (D_004C291C[*(s8 *)(p + 0x538)] & 0x800) {
            p[0x557] = (p[0x557] + 4) % 5;
        }
        if (D_004C291C[*(s8 *)(p + 0x538)] & 0x400) {
            p[0x557] = (p[0x557] + 6) % 5;
        }
    }
    cur = D_00583BDF[0];
    if (cur != old) {
        D_004C27C4 = 1;
        D_004C27C0 = 0x1D;
    }
    if (D_004C2840->b51 != 0) {
        D_004C27D0 = D_004B7630[cur];
    } else {
        D_004C27D0 = D_004B7650[cur];
    }
    if (D_004C291C[*(s8 *)(p + 0x538)] & 0x360) {
        func_001E3CE0(2);
        if (D_00583BDF[0] == 0) {
            D_004C27D0 = func_00417A40() % 8;
            D_004C27C4 = 1;
            D_004C27C0 = 0x1D;
        }
        return 1;
    }
    return 0;
}
