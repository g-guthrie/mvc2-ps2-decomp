typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad0[0x540]; s8 b540; u8 pad1[0x2F]; u8 b570; u8 pad2[0x5B8 - 0x571]; } PL;
extern PL D_004F20B0[];
extern PL D_004F2668[];
extern PL D_004F2C20[];
extern PL D_004F31D8[];
extern PL D_004F3790[];
extern PL D_004F3D48[];
extern s8 D_004F25F0[];
extern u8 D_004F2620[];
extern s8 D_004F3160[];
extern u8 D_004F3190[];
extern s8 D_004F2BA8[];
extern u8 D_004F2BD8[];
extern s8 D_004F3718[];
extern u8 D_004F3748[];
extern s32 D_004C28B8;
extern s32 D_004C28BC;
extern s32 D_004C28AC;
extern u8 *D_004C2840;
extern u8 D_004C2610;
extern u8 D_004C260C;
extern u8 D_004C27D0;
extern u8 D_0043CD80[];
extern u32 D_00446810[];
extern u16 D_004ACC10[];
extern s32 D_004CA190[];
extern s32 D_004CA1B0[];
extern s32 D_004CA1D0[];

void func_0012E780(u32 n)
{
    extern void func_0012E320();
    extern void func_0012E5E0(u16, u16, s32);
    extern void func_0012EF50(PL *);
    extern void func_0012EF80(PL *);
    extern void func_0012EFB0();
    s32 i;
    u8 k;
    PL *p, *q;
    u8 *t;
    u32 a1, a3;
    switch (n) {
    case 0:
        func_0012E320();
        func_0012E5E0(2, 0x348, D_004C28B8);
        func_0012E5E0(2, 0x347, D_004C28B8 + 0x49000);
        func_0012E5E0(2, 0x343, D_004C28B8 + 0x170000);
        break;
    case 3:
        for (i = 0; i < 6; i++) {
            p = &D_004F20B0[i];
            a1 = D_004C2610;
            a3 = a1 & 1;
            if (a3 != 0 && (i & 1) == 0) continue;
            if ((a1 & 2) != 0 && (i & 1) != 0) continue;
            t = D_0043CD80;
            if ((i & 1) == 0) {
                if ((a1 & 2) != 0) t += 6;
                else if (a3 != 0) t += 12;
            }
            for (;;) {
                if (*t != i) {
                    q = &D_004F20B0[*t];
                    if (p->b540 == q->b540) {
                        func_0012E5E0(0xFFFF, q->b570, p->b570);
                        break;
                    }
                    t++;
                    continue;
                } else {
                    func_0012EF50(p);
                    break;
                }
            }
        }
        break;
    case 4:
        func_0012E5E0(2, *(u16 *)(D_00446810 + D_004C27D0), D_004C28B8);
        func_0012E5E0(2, 0x31F, D_004C28AC + 0x61000);
        func_0012E5E0(2, 0x320, D_004C28B8 + 0x18A000);
        i = 0;
        do {
            func_0012EF50(&D_004F20B0[i]);
            i += 2;
        } while (i < 6);
        break;
    case 5:
        func_0012E320();
        func_0012E5E0(2, 0x350, D_004C28B8);
        func_0012E5E0(2, 0x34F, D_004C28B8 + 0x100000);
        i = 1;
        do {
            func_0012EF50(&D_004F20B0[i]);
            i += 2;
        } while (i < 6);
        break;
    case 6:
        func_0012E320();
        func_0012E5E0(2, 0x354, D_004C28B8);
        func_0012E5E0(2, 0x353, D_004C28B8 + 0x51000);
        break;
    case 7:
        func_0012E320();
        func_0012E5E0(2, 0x352, D_004C28B8);
        func_0012E5E0(2, 0x351, D_004C28B8 + 0x110000);
        func_0012E5E0(2, 0x35C, D_004C28BC);
        func_0012E5E0(2, 0x35D, D_004C28BC + 0x100000);
        func_0012E5E0(1, 0x3E, D_004C28B8 + 0x160000);
        break;
    case 8:
        func_0012E320();
    case 12:
        func_0012E5E0(2, 0x95, D_004C28B8);
        func_0012E5E0(2, 0x345, D_004C28B8 + 0x185000);
        break;
    case 10:
        func_0012E320();
        func_0012EFB0();
        break;
    case 11:
        func_0012E320();
        a1 = *(s8 *)(D_004C2840 + 0x88);
        if (D_004C2610 & a1) break;
        i = (a1 == 2) ? 1 : 0;
        if (i < 6) {
            do {
                p = &D_004F20B0[i];
                func_0012EF50(p);
                func_0012E5E0(2, D_004ACC10[p->b540], D_004CA190[p->b570]);
                i += 2;
            } while (i < 6);
        }
        break;
    case 13:
        i = 0;
        goto l13;
    case 14:
        i = 1;
    l13:
        if (i < 6) {
            do {
                p = &D_004F20B0[i];
                if (*(s32 *)(D_004C2840 + 0x98) == D_004C28BC)
                    func_0012E5E0(2, D_004ACC10[p->b540], D_004CA1B0[p->b570]);
                else
                    func_0012E5E0(2, D_004ACC10[p->b540], D_004CA1D0[p->b570]);
                i += 2;
            } while (i < 6);
        }
        break;
    case 15:
    case 16:
        i = n - 15;
        if (i < 6) {
            do {
                func_0012EF80(&D_004F20B0[i]);
                i += 2;
            } while (i < 6);
        }
    case 24:
        D_004C260C = 1;
        if (*(s32 *)(D_004C2840 + 0x98) == D_004C28BC) D_004C260C = 2;
        break;
    case 17:
        if (*(s8 *)(D_004C2840 + 0x90) & 1) D_004C260C = 1;
        else D_004C260C = 2;
        break;
    case 18:
        if (D_004C260C & 1) func_0012EF50(D_004F20B0);
        break;
    case 20:
        if (D_004C260C & 1) {
            p = D_004F2C20;
            if (*(s8 *)((s32)p + 0x540) == D_004F25F0[0])
                func_0012E5E0(0xFFFF, D_004F2620[0], p->b570);
            else
                func_0012EF50(p);
        }
        break;
    case 22:
        if (D_004C260C & 1) {
            p = D_004F3790;
            if (*(s8 *)((s32)p + 0x540) == D_004F25F0[0]) {
                func_0012E5E0(0xFFFF, D_004F2620[0], p->b570);
                D_004C2610 |= D_004C260C;
            } else if (*(s8 *)((s32)p + 0x540) == D_004F3160[0]) {
                func_0012E5E0(0xFFFF, D_004F3190[0], p->b570);
                D_004C2610 |= D_004C260C;
            } else {
                func_0012EF80(p);
            }
        }
        break;
    case 19:
        if (D_004C260C & 2) func_0012EF50(D_004F2668);
        break;
    case 21:
        if (D_004C260C & 2) {
            p = D_004F31D8;
            if (*(s8 *)((s32)p + 0x540) == D_004F2BA8[0])
                func_0012E5E0(0xFFFF, D_004F2BD8[0], p->b570);
            else
                func_0012EF50(p);
        }
        break;
    case 23:
        if (D_004C260C & 2) {
            p = D_004F3D48;
            if (*(s8 *)((s32)p + 0x540) == D_004F2BA8[0]) {
                func_0012E5E0(0xFFFF, D_004F2BD8[0], p->b570);
                D_004C2610 |= D_004C260C;
            } else if (*(s8 *)((s32)p + 0x540) == D_004F3718[0]) {
                func_0012E5E0(0xFFFF, D_004F3748[0], p->b570);
                D_004C2610 |= D_004C260C;
            } else {
                func_0012EF80(p);
            }
        }
        break;
    case 25:
        func_0012E5E0(2, *(s8 *)(D_004C2840 + 5) + 0x391, D_004C28B8);
        break;
    case 27:
        func_0012E5E0(3, 1, D_004C28BC);
        break;
    case 28:
        func_0012E5E0(3, 0, D_004C28BC + 0xF000);
        break;
    default:
        break;
    }
}
