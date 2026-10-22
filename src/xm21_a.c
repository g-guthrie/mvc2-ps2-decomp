typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 x[16]; } W64;
typedef struct { s32 x[19]; } W76;
typedef struct { s32 x[25]; } W100;

extern s32 D_004C2AA0;
extern s32 D_004C2A7C;
extern s32 D_004C2AB8;
extern s32 D_004C2ABC;
extern s32 D_004C2AC0;
extern s32 D_004C2AC4;
extern f32 D_004C2AC8;
extern f32 D_004C2ACC;
extern u32 D_004C2AD0;
extern u32 D_004C2AD4;
extern s32 D_004C2AEC;
extern s32 D_004C2A98[2];
extern W64 D_0061B8A0[];
extern W76 D_0061A334[];
extern W100 D_0061902C[];
extern W100 D_0061B2F0[];
extern W64 D_0061C720;
extern u8 D_0061C6E0[];
extern u8 D_0061BE20[];
extern u8 D_0061BE60[];
extern u8 D_0061BEA0[];
extern u8 D_0061C760[];

s32 func_003DF850(s32 id, u32 val)
{
    extern void func_003DE530(u8 *);
    extern void func_003E0A90(s32);
    extern void func_003E00B0(s32);
    extern void func_003DE160(u8 *, u8 *, u8 *);
    extern void func_003DD4E0(s32, s32, s32, s32, s32, f32, f32);
    extern void func_003E06D0(s32, s32);
    extern void func_003E0B50(s32, s32);
    extern void func_003E0390(s32, s32);
    extern void func_003E0530(s32, s32);
    s32 *q;
    s32 v;

    if (id >= 0x19 && id < 0x39) {
        if (val != 0) {
            D_0061B8A0[id] = *(W64 *)val;
            D_004C2AA0 |= 1 << (id - 0x19);
        } else {
            D_004C2AA0 &= ~(1 << (id - 0x19));
        }
        return 1;
    }
    if (id >= 0x39 && id < 0x59) {
        D_0061A334[id] = *(W76 *)val;
        return 1;
    }
    if (id >= 0x59 && id < 0x5C) {
        D_0061902C[id] = *(W100 *)val;
        func_003DE530((u8 *)&D_0061B2F0[id - 0x59] + 0x34);
        return 1;
    }
    switch (id) {
    case 0:
    case 3:
    case 8:
    case 9:
    case 0xA:
    case 0xB:
        break;
    case 0xE:
        D_004C2AC0 = val;
        break;
    case 0xF:
        if (D_004C2AC4 != val) {
            D_004C2AC4 = val;
            func_003E0A90(val);
        }
        break;
    case 0x10:
        D_004C2ACC = *(f32 *)&val;
        break;
    case 0x11:
        D_004C2AC8 = *(f32 *)&val;
        break;
    case 0x12:
        D_004C2AD4 &= 0xFFFE7FFF;
        if (val != 0) D_004C2AD4 |= 0x8000;
        break;
    case 0x13:
        break;
    case 1:
        D_004C2AD4 &= 0xFFFFFC7F;
        switch (val) {
        case 1: D_004C2AD4 |= 0x100; break;
        case 2: D_004C2AD4 |= 0x80; break;
        case 0: break;
        }
        break;
    case 2:
        D_004C2AD4 &= 0xFFFFFFF3;
        switch (val) {
        case 1: D_004C2AD4 |= 4; break;
        case 2: D_004C2AD4 |= 8; break;
        case 0: break;
        }
        break;
    case 0xD:
        if ((D_004C2AD0 & 0xC00) != val) {
            D_004C2AD0 &= 0xFFFFF3FF;
            D_004C2AD0 |= val;
            func_003E06D0(D_004C2AD0, 0);
        }
        break;
    case 0x5D:
        if ((D_004C2AD0 & 0xFF) != val) {
            D_004C2AD0 &= 0xFFFFFF00;
            D_004C2AD0 |= val;
            func_003E06D0(D_004C2AD0, 0);
        }
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        v = val;
        if (id == 4) D_004C2AEC = v;
        D_004C2A98[id] = v;
        break;
    case 0x14:
        func_003E00B0(val);
        break;
    case 0x16:
        D_0061C720 = *(W64 *)val;
        D_004C2AA0 = -1;
        break;
    case 0x17:
        *(W64 *)D_0061C6E0 = *(W64 *)val;
        D_004C2AA0 = -1;
        func_003DE160(D_0061BE20, D_0061C6E0, D_0061C760);
        func_003DE160(D_0061BE60, D_0061C6E0, D_0061BEA0);
        break;
    case 0x15:
        D_004C2AD4 &= 0xFFFFFFFC;
        if (val != 1) {
            if (val == 2) D_004C2AD4 |= 2;
        }
        break;
    case 0x18:
        q = (s32 *)val;
        func_003DD4E0(0x22, q[0], q[1], q[2], q[3], *(f32 *)&q[4], *(f32 *)&q[5]);
        D_004C2AA0 = -1;
        break;
    case 0x5C:
        D_004C2AD4 &= 0xFFFFFF;
        D_004C2AD4 |= val;
        break;
    case 0x5F:
        D_004C2AB8 = val;
        break;
    case 0x61:
        D_004C2AD4 &= 0xFFFFBFFF;
        if (val != 0) D_004C2AD4 |= 0x4000;
        break;
    case 0x62:
        D_004C2AD0 &= 0xFFFEFFFF;
        if (val == 0x10000) D_004C2AD0 |= 0x10000;
        func_003E0B50(D_004C2AD0, 0);
        break;
    case 0x63:
        D_004C2AD0 &= 0xFFF9FFFF;
        if (val != 0) {
            if (val == 0x20000) D_004C2AD0 |= 0x20000;
        }
        break;
    case 0x65:
        D_004C2AD4 &= 0xFFFDFFFF;
        if (val != 0) D_004C2AD4 |= 0x20000;
        break;
    case 0x66:
        D_004C2ABC = val;
        break;
    case 0xC:
        D_004C2AD4 &= 0xFFFFFFBF;
        if (val == 1) D_004C2AD4 |= 0x40;
        break;
    case 0x6C:
        switch (val) {
        case 0:
        case 1:
        case 3:
        case 7:
            if (D_004C2A7C != val) {
                D_004C2A7C = val;
                func_003E0390(val, 0);
            }
            break;
        case 2:
        case 4:
        case 5:
        case 6:
            break;
        }
    case 0x6B:
        func_003E0530(val, 0);
        break;
    }
    return 1;
}
