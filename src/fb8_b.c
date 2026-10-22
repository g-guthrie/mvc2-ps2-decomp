typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 pad0[3];
    u8 b3;
    u8 pad4;
    u8 b5;
    s8 b6;
    s8 b7;
    u8 pad8[2];
    s16 hA;
} PK_b;

extern PK_b *D_004C2840;
extern s32 D_004D1788[];
extern u8 D_004D17C9[];
extern u32 D_004D17F8[];
extern s32 D_004D17CC[];
extern u8 D_004D17CB[];
extern u8 D_004D17C1[];
extern u8 D_004D1792[];
extern u8 D_004D1793[];
extern u8 D_004D17C0[];
extern u8 D_004D179B[];
extern s32 D_004D17A4[];
extern s32 D_006336E8[];
extern s32 D_00633670[];
extern s32 D_00633678[];

void func_0041F190(void)
{
    extern void func_0041DF20();
    extern void func_00151640();
    extern s32 func_001315F0();
    extern s32 func_001317B0();
    extern void func_001E3CE0(s32);
    extern s32 func_0038C750(s32, s32);
    extern void func_003298B0(s32, s32, s32);
    extern s32 func_003299D0();
    extern void func_0012FC40();
    PK_b *p = D_004C2840;
    s32 idx;
    s32 a3;
    s32 r;

    switch (p->b6) {
    case 0:
        switch (p->b7) {
        case 0:
            func_0041DF20();
            idx = D_004D17CC[0];
            if (D_006336E8[idx] == 0) return;
            if (D_00633670[idx * 3] != 2) goto reset;
            if (D_00633678[idx * 3] == 0) {
                D_004D17C9[0] = 0x1C;
                func_00151640();
                D_004D17F8[0] = 0;
                D_004C2840->b7 = D_004C2840->b7 + 1;
            } else {
                D_004C2840->b6 = 1;
                D_004C2840->b7 = 0;
            }
            break;
        case 1:
            func_0041DF20();
            if (D_004D1788[0] == 0) {
                if (D_004D17C9[0] == 0x19) goto reset;
                D_004D17C9[0] = 0x19;
                func_00151640();
                goto reset;
            } else {
                D_004D17F8[0] = D_004D17F8[0] + 1;
                if (func_001315F0() == 0 && D_004D17F8[0] < 0xB4) return;
                func_001E3CE0(3);
                goto reset;
            }
        }
        break;
    case 1:
        func_0041DF20();
        {
            PK_b *q = D_004C2840;
            s8 *pb = &q->b7;
            switch (q->b7) {
            case 0:
                idx = D_004D17CC[0];
                a3 = D_006336E8[idx];
                if (a3 == 0) return;
                if (D_00633670[idx * 3] != 2) goto reset;
                if (a3 == 4) {
                    q->b6 = 2;
                    D_004C2840->b7 = 0;
                    D_004D17C9[0] = 0x1B;
                    D_004D1792[0] = 0;
                    D_004D1793[0] = 0;
                    D_004D17C0[0] = 0;
                    goto call1;
                } else if (a3 == 3) {
                    *pb = 1;
                    D_004D17C9[0] = 2;
                    goto call1;
                } else if (a3 == 1) {
                    goto reset;
                } else if (a3 == 5) {
                    *pb = 1;
                    D_004D17C9[0] = 2;
                    goto call1;
                } else {
                    D_004D17C1[0] = 0;
                    q->b6 = 4;
                    D_004C2840->b7 = 0;
                }
                break;
            call1:
                func_00151640();
                break;
            case 1:
                if (D_004D1788[0] == 0) {
                    if (D_004D17C9[0] == 0x19) goto reset;
                    D_004D17C9[0] = 0x19;
                    func_00151640();
                    goto reset;
                } else {
                    if (func_001317B0() == 0) return;
                    func_001E3CE0(3);
                    goto reset;
                }
            }
        }
        break;
    case 2:
        D_004D17C1[0] = 1;
        r = func_0038C750(D_004D17CC[0], 0);
        if (r == 1) {
            D_004D17C1[0] = 0;
            D_004C2840->b6 = D_004C2840->b6 + 1;
            D_004C2840->b7 = 0;
        } else if (r == 0) {
            D_004D17C1[0] = 0;
            D_004C2840->b6 = 4;
            D_004C2840->b7 = 0;
        } else {
            return;
        }
        break;
    case 3:
        func_0041DF20();
        {
            PK_b *q = D_004C2840;
            s8 *pb = &q->b7;
            switch (q->b7) {
            case 0:
                D_004D179B[0] = 1;
                D_004D17C9[0] = 0x10;
                D_004D17A4[0] = D_004D17CC[0];
                *pb = 1;
                func_00151640();
                D_004D17F8[0] = 0;
                break;
            case 1:
                if (D_004D1788[0] == 0) {
                    if (D_004D17C9[0] != 0x19) {
                        D_004D17C9[0] = 0x19;
                        func_00151640();
                    }
                    func_001E3CE0(3);
                    D_004C2840->b6 = 5;
                    func_003298B0(0xFF000000, 0xA, 1);
                }
                D_004D17F8[0] = D_004D17F8[0] + 1;
                if (func_001315F0() == 0 && D_004D17F8[0] <= 0xB4) return;
                D_004C2840->b6 = 5;
                func_003298B0(0xFF000000, 0xA, 1);
                break;
            }
        }
        break;
    case 4:
        func_0041DF20();
        {
            PK_b *q = D_004C2840;
            s8 *pb = &q->b7;
            switch (q->b7) {
            case 0:
                D_004D17F8[0] = 0;
                *pb = 3;
                D_004D17C9[0] = 0x11;
                func_00151640();
                break;
            case 1:
                if (D_004D1788[0] == 0) D_004D17F8[0] = 0xB5;
                D_004D17F8[0] = D_004D17F8[0] + 1;
                if (func_001315F0() == 0 && D_004D17F8[0] <= 0xB4) return;
                D_004D17C9[0] = 0x1A;
                func_00151640();
                D_004C2840->b7 = D_004C2840->b7 + 1;
                break;
            case 2:
                if (D_004D1788[0] == 0) {
                    if (D_004D17C9[0] == 0x19) goto reset;
                    D_004D17C9[0] = 0x19;
                    func_00151640();
                    goto reset;
                } else {
                    if (func_001317B0() != 0) goto reset;
                }
                break;
            case 3:
                if (D_004D1788[0] == 0) {
                    if (D_004D17C9[0] == 0x19) goto reset;
                    D_004D17C9[0] = 0x19;
                    func_00151640();
                    goto reset;
                } else {
                    D_004D17F8[0] = D_004D17F8[0] + 1;
                    if (func_001317B0() != 0) goto reset;
                    if (D_004D17F8[0] <= 0xB4) break;
                    goto reset;
                }
            }
        }
        break;
    case 5:
        if (func_003299D0() != 0) return;
        D_004C2840->b3 = 1;
        D_004C2840->b5 = 0;
        D_004C2840->b6 = 0;
        D_004C2840->b7 = 0;
        D_004D17C9[0] = 0;
        if (D_004D17CB[0] == 0) return;
        D_004D17CB[0] = 0;
        func_0012FC40();
        break;
    }
    return;
reset:
    D_004C2840->b5 = 1;
    D_004C2840->b6 = 0;
    D_004C2840->b7 = 0;
    D_004C2840->hA = 0;
}
