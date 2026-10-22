typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_004D17C0[];
extern s32 D_004D17F8[];
extern s32 D_00633698[];
extern u8 D_00584AE0[];
extern u8 D_00464E90[];
extern s32 D_004C29B8;
extern s32 D_004C29B4;
extern volatile s32 D_004C29B0;

s32 func_0038B2E0(s32 a, s32 b, s32 c)
{
    extern s32 func_00418D70(s32);
    extern void func_0038CDD0(s8);
    extern void func_0038CE40(s8);
    extern void func_0038D010(s8, s32);
    extern void func_0038AA30(u8);
    extern s32 func_0038D1B0(s8);
    extern s32 func_0038D220(s8);
    extern s32 func_0038D290(s8, s32, s32);
    extern s32 func_0038D310(s8, s32);
    extern s32 func_00419520(s32, s32, u8 *);
    extern s32 func_00419840(s32, s32, u8 *, s32);
    extern s32 func_00419B90(s32, s32, s32);
    extern s32 func_00419950(s32);
    s32 r;
    s8 t;
    s32 m;
    u8 *q;

    switch (D_004D17C0[0]) {
    case 0:
        if (func_00418D70(0) < 0) {
            break;
        }
        D_004D17C0[0]++;
    case 1:
        if (c != 0) {
            func_0038CDD0((s8)a);
            if (func_00419520(b, 0, q = D_00584AE0) < 0) {
err:
                D_004D17C0[0] = 0;
                return -0x10000;
            }
            D_004D17C0[0] = 0x14;
        } else {
            D_004D17C0[0] = 0xA;
        }
        break;
    case 0xA:
        func_0038CE40((s8)a);
        if (func_00419840(b, 0, q = D_00584AE0, 0x203) < 0) {
            goto err;
        }
        D_004D17C0[0]++;
    case 0xB:
        switch (func_00418D70(0)) {
        case 0:
            D_004D17C0[0]++;
            func_0038AA30(a);
            t = (s8)a;
            D_004C29B8 = D_00633698[0];
            D_004C29B4 = func_0038D1B0(t);
            D_004C29B0 = func_0038D220(t);
            if (func_00419B90(D_004C29B8, D_004C29B4, D_004C29B0) < 0) goto err;
            break;
        case 1:
            goto err;
        }
        break;
    case 0xC:
        switch (func_00418D70(0)) {
        case 0:
            D_004D17C0[0]++;
            if (func_00419950(D_004C29B8) < 0) goto err;
            break;
        case 1:
            goto err;
        }
        break;
    case 0xD:
        switch (func_00418D70(0)) {
        case 0:
            D_004D17C0[0] = 0;
            return 0;
        case 1:
            goto err;
        }
        break;
    case 0x14:
        switch (func_00418D70(0)) {
        case 0:
inc:
            D_004D17C0[0]++;
            break;
        case 1:
            if (D_00633698[0] == -4) goto inc;
            goto err;
        }
        break;
    case 0x15:
        func_0038D010((s8)a, 0);
        if (func_00419840(b, 0, q = D_00584AE0, 0x203) < 0) goto err;
        D_004D17C0[0]++;
    case 0x16:
        switch (func_00418D70(0)) {
        case 0:
            D_004D17C0[0]++;
            D_004C29B4 = (s32)D_00464E90;
            D_004C29B0 = 0x3C4;
            D_004C29B8 = D_00633698[0];
            if (func_00419B90(D_004C29B8, D_004C29B4, 0x3C4) < 0) goto err;
            break;
        case 1:
            goto err;
        }
        break;
    case 0x17:
        switch (func_00418D70(0)) {
        case 0:
            D_004D17F8[0] = 1;
            D_004D17C0[0]++;
            if (func_00419950(D_004C29B8) < 0) goto err;
            break;
        case 1:
            goto err;
        }
        break;
    case 0x18:
        switch (func_00418D70(0)) {
        case 0:
    body18:
            D_004D17C0[0]++;
            func_0038D010((s8)a, D_004D17F8[0]);
            if (func_00419840(b, 0, q = D_00584AE0, 0x203) < 0) goto err;
            break;
        case 1:
            goto err;
        }
        break;
    case 0x19:
        switch (func_00418D70(0)) {
        case 0:
            t = (s8)a;
            D_004D17C0[0]++;
            D_004C29B8 = D_00633698[0];
            D_004C29B4 = func_0038D290(t, D_004D17F8[0] + (m = -1), m);
            D_004C29B0 = func_0038D310(t, D_004D17F8[0] - 1);
            if (func_00419B90(D_004C29B8, D_004C29B4, D_004C29B0) < 0) goto err;
            break;
        case 1:
            goto err;
        }
        break;
    case 0x1A:
        switch (func_00418D70(0)) {
        case 0:
            D_004D17C0[0]++;
            if (func_00419950(D_004C29B8) < 0) goto err;
            break;
        case 1:
            goto err;
        }
        break;
    case 0x1B:
        switch (func_00418D70(0)) {
        case 0:
            D_004D17F8[0]++;
            if ((u32)D_004D17F8[0] < 4) {
                if ((s8)a == 4) {
                    D_004D17C0[0] = 0x18;
                    goto body18;
                }
            }
            D_004D17C0[0] = 0xA;
            break;
        case 1:
            goto err;
        }
        break;
    }
    return -1;
}
