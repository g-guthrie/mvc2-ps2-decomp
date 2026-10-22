typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { s32 w0, w4, w8; } TE;
extern TE D_00633670[];
extern u8 D_004D17C0[];
extern s32 D_00633698[];
extern s32 D_005852A0[];
extern u8 D_00584AE0[];
extern s32 D_004C29B0;
extern s32 *D_004C29B4;
extern s32 D_004C29B8;

s32 func_0038C4A0(s32 a, s32 b)
{
    extern s32 func_00418D70();
    extern s32 func_00419310(), func_00419950();
    extern s32 func_00419840(s32, s32, void *, s32);
    extern s32 func_00419AC0(s32, s32 *, u32);
    extern void func_0038CE40();
    extern s32 func_0038D220(), func_0038C210();
    extern void func_0038B8C0(), func_0038A9C0();
    TE *t = &D_00633670[b];
    s32 r;
    u32 u;
    u8 st = D_004D17C0[0];
    switch (st) {
    case 0:
        if (func_00418D70(0) < 0) goto m1;
        if (func_00419310(b, 0) < 0) {
        fail:
            D_004D17C0[0] = 0;
            return -0x10000;
        }
        u = D_004D17C0[0]; D_004D17C0[0] = u + 1;
    case 1:
        switch (func_00418D70(0)) {
        case 0:
            if (t->w0 != 2) { D_004D17C0[0] = 0; return -0xFF; }
            if (t->w8 == 0) { D_004D17C0[0] = 0; return -0xFD; }
            func_0038CE40((s8)a);
            if (func_00419840(b, 0, D_00584AE0, 1) < 0) goto fail;
            u = D_004D17C0[0]; D_004D17C0[0] = u + 1;
            goto m1;
        case 1:
            goto fail;
        default:
            goto m1;
        }
    case 2:
        switch (func_00418D70(0)) {
        case 0:
            u = D_004D17C0[0];
            D_004C29B4 = D_005852A0;
            D_004C29B8 = D_00633698[0];
            D_004D17C0[0] = u + 1;
            D_004C29B0 = func_0038D220((s8)a);
            if (func_00419AC0(D_004C29B8, D_004C29B4, D_004C29B0) < 0) goto fail;
            goto m1;
        case 1:
            goto fail;
        default:
            goto m1;
        }
    case 3:
        switch (func_00418D70(0)) {
        case 0:
            u = D_004D17C0[0] + 1;
            D_004C29B0 = D_00633698[0];
            D_004D17C0[0] = u;
            if (func_00419950(D_004C29B8) < 0) goto fail;
            goto m1;
        case 1:
            goto fail;
        default:
            goto m1;
        }
    case 4:
        switch (func_00418D70(0)) {
        case 0:
            b = a & 0xFF;
            r = func_0038C210(a);
            if (r == 0) func_0038B8C0(b); else func_0038A9C0(b);
            D_004D17C0[0] = 0;
            return r;
        case 1:
            goto fail;
        default:
            goto m1;
        }
    default:
        goto fail;
    }
m1:
    return -1;
}
