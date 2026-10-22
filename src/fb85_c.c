typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 *D_004C2840;
extern u8 *D_0044F0D0[];
extern s8 D_004CD183[];
extern s32 D_004C271C;

void func_001E24E0(u8 *p, s32 b)
{
    extern void func_001741D0(u8 *, f32 *);
    extern s32 func_00118FA8(f32);
    extern void func_001E3240(u8 *, s32);
    extern void func_001E3D20(s32, s32, s32, s32);
    extern void func_001E4A10(u8, s32, s32, s16, f32);
    extern void func_001E4C40(u8, s32, s32, s16, f32);
    extern void func_001E47E0(u8, s32);
    f32 t[2];
    s32 idx;
    s32 bb;
    s32 S;
    u8 *o;
    u8 r;
    o = *(u8 **)(p + 0x18);
    o = o ? o : p;
    func_001741D0(o + 0x34, &t[0]);
    idx = func_00118FA8(t[0] / 40.0f);
    if (idx <= -1)
        idx = 0;
    if (idx >= 0x10)
        idx = 0xF;
    if (D_004C2840[0x45]) {
        r = D_0044F0D0[p[1]][b & 0xFF];
        if (r == 0xFE)
            return;
        if (r != 0xFF)
            b = r;
    }
    bb = b & 0xFF;
    if (bb == 0x2B) {
        switch (p[1]) {
        case 0:
            break;
        case 3:
            break;
        case 4:
            func_001E3240(p, 17);
            func_001E3240(p, 23);
            func_001E3240(p, 24);
            func_001E3240(p, 30);
            break;
        case 6:
            break;
        case 9:
            func_001E3240(p, 30);
            break;
        case 15:
            func_001E3240(p, 32);
            break;
        case 16:
            func_001E3240(p, 34);
            break;
        case 20:
            func_001E3240(p, 33);
            break;
        case 21:
            func_001E3240(p, 36);
            break;
        case 23:
            break;
        case 24:
            func_001E3240(p, 22);
            break;
        case 28:
            func_001E3240(p, 30);
            break;
        case 29:
            func_001E3240(p, 30);
            break;
        case 31:
            func_001E3240(p, 30);
            break;
        case 39:
            break;
        case 42:
            func_001E3240(p, 35);
            break;
        case 45:
            func_001E3240(p, 33);
            func_001E3240(p, 34);
            func_001E3240(p, 36);
            break;
        case 46:
            func_001E3240(p, 35);
            break;
        case 50:
            func_001E3240(p, 31);
            break;
        case 51:
            func_001E3240(p, 35);
            break;
        case 52:
            break;
        case 54:
            func_001E3240(p, 37);
            break;
        }
    } else {
        S = D_004CD183[o[0x1B8] * 20];
        switch (p[1]) {
        case 0:
            func_001E3D20(S, bb, idx, -1);
            break;
        case 3:
            if (bb == 31) {
                func_001E4A10(S, b, 64, idx, 2.5f);
            } else {
                func_001E3D20(S, bb, idx, -1);
            }
            break;
        case 4:
            if (bb == 17) {
                func_001E4A10(S, b, 192, idx, 2.5f);
            } else if (bb == 23) {
                func_001E4A10(S, b, 192, idx, 2.5f);
            } else if (bb == 24) {
                func_001E4A10(S, b, 192, idx, 2.5f);
            } else if (bb == 30) {
                func_001E4A10(S, b, 128, idx, 0.8f);
            } else {
                func_001E3D20(S, bb, idx, -1);
            }
            break;
        case 6:
            if (bb == 31) {
                func_001E4A10(S, b, 64, idx, 1.0f);
            } else if (bb == 32) {
                func_001E4A10(S, b, 64, idx, 1.5f);
            } else {
                func_001E3D20(S, bb, idx, -1);
            }
            break;
        case 9:
            if (bb == 30) {
                func_001E4A10(S, b, 64, idx, 3.0f);
            } else {
                func_001E3D20(S, bb, idx, -1);
            }
            break;
        case 15:
            if (bb == 32) {
                func_001E4A10(S, b, 128, idx, 3.0f);
            } else if (bb == 36) {
                func_001E47E0(S, b); func_001E4A10(S, b, 96, idx, 1.3f);
            } else {
                func_001E3D20(S, bb, idx, -1);
            }
            break;
        case 16:
            if (bb == 34) {
                func_001E4A10(S, b, 128, idx, 0.5f);
            } else if (bb == 35) {
                func_001E4A10(S, b, 96, idx, 4.0f);
            } else {
                func_001E3D20(S, bb, idx, -1);
            }
            break;
        case 19:
            if (bb == 32) {
                func_001E4A10(S, b, 64, idx, 0.7f);
            } else {
                func_001E3D20(S, bb, idx, -1);
            }
            break;
        case 20:
            if (bb == 35) {
                func_001E4A10(S, b, 64, idx, 0.5f);
            } else {
                func_001E3D20(S, bb, idx, -1);
            }
            break;
        case 21:
            func_001E3D20(S, bb, idx, -1);
            break;
        case 23:
            func_001E3D20(S, bb, idx, -1);
            break;
        case 24:
            if (bb == 22) {
                func_001E4A10(S, b, 64, idx, 1.0f);
            } else {
                func_001E3D20(S, bb, idx, -1);
            }
            break;
        case 28:
            if (bb == 39) {
                func_001E4A10(S, b, 128, idx, 7.0f);
            } else if (bb == 45) {
                func_001E4A10(S, b, 64, idx, 1.5f);
            } else {
                func_001E3D20(S, bb, idx, -1);
            }
            break;
        case 29:
            if (bb == 39) {
                func_001E4A10(S, b, 64, idx, 3.0f);
            } else if (bb == 45) {
                func_001E4A10(S, b, 64, idx, 1.5f);
            } else {
                func_001E3D20(S, bb, idx, -1);
            }
            break;
        case 31:
            if (bb == 30) {
                func_001E4C40(S, b, 96, idx, 0.8f);
            } else if (bb == 31) {
                func_001E4C40(S, b, 96, idx, 0.8f);
            } else if (bb == 36) {
                func_001E4C40(S, b, 96, idx, 0.8f);
            } else {
                func_001E3D20(S, bb, idx, -1);
            }
            break;
        case 42:
            if (bb == 35) {
                func_001E4A10(S, b, 64, idx, 1.0f);
            } else {
                func_001E3D20(S, bb, idx, -1);
            }
            break;
        case 44:
            if (bb == 20) {
                func_001E47E0(S, b); func_001E4A10(S, b, 96, idx, 3.0f);
            } else {
                func_001E3D20(S, bb, idx, -1);
            }
            break;
        case 45:
            func_001E3D20(S, bb, idx, -1);
            break;
        case 46:
            if (bb == 34) {
                func_001E4A10(S, b, 96, idx, 1.5f);
            } else if (bb == 35) {
                func_001E4A10(S, b, 96, idx, 1.5f);
            } else {
                func_001E3D20(S, bb, idx, -1);
            }
            break;
        case 50:
            if (bb == 31) {
                func_001E4A10(S, b, 255, idx, 1.0f);
            } else {
                func_001E3D20(S, bb, idx, -1);
            }
            break;
        case 51:
            if (bb == 34) {
                func_001E4A10(S, b, 96, idx, 1.5f);
            } else if (bb == 35) {
                func_001E4A10(S, b, 96, idx, 1.5f);
            } else {
                func_001E3D20(S, bb, idx, -1);
            }
            break;
        case 52:
            if (bb == 39) {
                func_001E4A10(S, b, 128, idx, 1.0f);
            } else if (bb == 45) {
                func_001E4A10(S, b, 255, idx, 2.0f);
            } else if (bb == 48) {
                func_001E47E0(S, b); func_001E4A10(S, b, 96, idx, 1.5f);
            } else {
                func_001E3D20(S, bb, idx, -1);
            }
            break;
        case 54:
            if (bb == 37) {
                func_001E4A10(S, b, 64, idx, 1.0f);
            } else {
                func_001E3D20(S, bb, idx, -1);
            }
            break;
        case 58:
            func_001E3D20(S, bb, idx, -1);
            break;
        default:
            func_001E3D20(S, bb, idx, -1);
            break;
        }
        D_004C271C++;
        if (D_004C271C > 0x3E8)
            D_004C271C = 0;
    }
}
