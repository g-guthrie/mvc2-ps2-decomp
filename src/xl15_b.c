typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { s16 s[16]; } P32;
#pragma pack(1)
typedef struct { f32 f; s16 h; } LC;
#pragma pack()

extern u8 D_0062C090[];
extern u8 D_0062C091[];
extern u8 D_0062C092[];
extern u8 D_0062C093[];
extern u8 D_0062C094[];
extern u8 D_0062C095[];
extern u8 D_0062C530[];
extern u8 D_0062C531[];
extern u8 D_0062C532[];
extern u8 D_0062C538[];
extern u8 D_0062C54C[];
extern u8 D_0062C54E[];
extern u8 D_0062C558[];
extern u8 D_0062C55A[];
extern u8 D_0062C640[];
extern u8 D_0062C660[];
extern u8 D_0062C662[];
extern u8 D_0062C700[];
extern u8 D_0062C701[];
extern u8 D_0062C702[];
extern u8 D_0062C704[];
extern u8 D_0062C705[];
extern u8 D_0062C706[];
extern u8 D_0062C707[];
extern u8 D_0062C500[];
extern u8 D_00478D50[];
extern u8 D_00478DD0[];
extern u8 D_004BA430[];
extern u8 D_004C2AF8[8];
extern u8 D_004C2AF0[8];
extern LC D_004C21F8;


s32 func_003EDA60(s32 i)
{
    extern s32 func_0010D990(s32, s32);
    extern s32 func_0010DD70(s32, s32, s32, s32);
    extern s32 func_0010DEA8(s32, s32, s32, s32);
    extern s32 func_0010DAA8(s32, s32);
    extern s32 func_0010E260(s32, s32);
    extern s32 func_0010E2C0(s32, s32);
    extern s32 func_0010E020(s32, s32, void *);
    extern s32 func_0010D910(s32, s32, void *);
    extern void func_003EE480(u8 *, s32);
    u8 *fp;
    s32 s6;
    s32 s5;
    s32 r;
    s32 v;
    s32 x;
    s32 y;
    s32 o12;
    s32 o32;
    s32 k;
    s32 t2;
    s32 kind;
    s32 h;
    u8 buf[12];
    P32 *s2;
    u8 *s3;
    P32 *s4;
    u8 *a1p;
    u8 *T;
    s32 o52;
    s32 off8;
    s32 off4;
    s32 *q;
    s32 j;
    LC loc;

    o12 = i * 12;
    fp = D_0062C090 + o12;
    if (*fp == 0) return 0;
    s6 = D_0062C092[o12];
    s5 = D_0062C093[o12];
    o32 = i * 32;
    s4 = (P32 *)(D_0062C660 + o32);
    s2 = (P32 *)(D_0062C700 + o32);
    *s2 = *s4;
    r = func_0010D990(s6, s5);
    switch (r) {
    case 0:
        *fp = 1;
        D_0062C091[o12] = 10;
        D_0062C094[o12] = 0;
        D_0062C095[o12] = 0;
        *s2 = *(P32 *)D_0062C640;
        break;
    case 7:
        *fp = 2;
        D_0062C091[o12] = 10;
        break;
    default:
        *fp = 2;
        if (D_004C2AF8[i] != D_004C2AF0[i]) D_0062C091[o12] = 10;
        s3 = D_0062C091 + o12;
        switch (*s3) {
        case 10:
            x = func_0010DD70(s6, s5, 1, 0);
            y = func_0010DD70(s6, s5, 2, 0);
            if (x != 0) {
                if (y > 0) x = y;
                if (y != 0) D_0062C095[o12] = 1;
                else D_0062C095[o12] = 0;
                switch (x) {
                case 7: *s3 = 0x46; break;
                case 4: *s3 = 0x28; break;
                default: *s3 = 0x5A; break;
                }
            }
            break;
        case 0x28:
            if (D_004C2AF8[i] != 0 && func_0010DD70(s6, s5, 4, -1) != 0) {
                *s3 = 0x29;
                D_004C2AF8[i] = 0;
            } else {
                loc = D_004C21F8;
                func_0010E020(i, 0, &loc);
                *s3 = 0x5A;
            }
            break;
        case 0x29:
            if (func_0010DEA8(s6, s5, 1, 0) == 1) *s3 = 0x2A;
            break;
        case 0x2A:
            v = func_0010DAA8(s6, s5);
            if (v == 1) *s3 = 0x29;
            if (v == 0) *s3 = 10;
            break;
        case 0x46:
            v = func_0010E260(s6, s5);
            if (v == 1) *s3 = 0x4C;
            else *s3 = 0x5A;
            break;
        case 0x4C:
            v = func_0010E2C0(s6, s5);
            if (v == 1) *s3 = 0x4D;
            break;
        case 0x4D:
            v = func_0010DAA8(s6, s5);
            if (v == 1) *s3 = 0x4C;
            if (v == 0) *s3 = 0x5A;
            break;
        default:
            if (r == 2 || r == 6) {
                v = func_0010D910(s6, s5, s2);
                a1p = D_0062C094 + o12;
                if (*a1p != (y = D_0062C701[o32])) {
                    *s3 = 10;
                    *a1p = y;
                } else if (v == 0 || *(u8 *)s2 == 0xFF) {
                    *s2 = *s4;
                } else {
                    *fp = 1;
                }
            } else {
                *s2 = *s4;
            }
            break;
        }
        break;
    }
    *(D_0062C530 + i * 52) = *fp;
    o52 = i * 52;
    T = D_0062C530 + o52;
    func_003EE480(T, D_0062C701[o32]);
    h = *(u16 *)(D_0062C532 + o52);
    if (h != 0 && (h & 3) == 0) *(u16 *)(D_0062C532 + o52) = 0x8000;
    for (k = 0; k < 16; k++) T[0xC + k] = 0;
    for (k = 0; k < 12; k++) buf[k] = ((u8 *)s2)[8 + k] / 2;
    *(s16 *)(D_0062C702 + o32) = ~*(s16 *)(D_0062C702 + o32);
    h = *(u16 *)(D_0062C532 + o52);
    switch (h) {
    case 1: case 2: case 4: case 8: case 0x10: case 0x20:
        t2 = 0;
        j = 0;
        off8 = 0;
        off4 = 0;
        do {
            q = (s32 *)(D_00478D50 + off8);
            if (*(u16 *)((u8 *)s2 + 2) & q[0]) {
                t2 |= *(s32 *)(D_004BA430 + off4);
                T[0xC + j] = 0x7F;
            }
            switch (q[1]) {
            case 1:
                if (T[1] & 0x10) {
                    v = buf[D_00478DD0[j]];
                    if (v < *(s16 *)(D_0062C500 + i * 8)) T[0xC + j] = 0;
                    else T[0xC + j] = v;
                }
                break;
            case 2:
                if (T[1] & 1) {
                    v = buf[D_00478DD0[j]];
                    if (v < *(s16 *)(D_0062C500 + i * 8)) T[0xC + j] = 0;
                    else T[0xC + j] = v;
                }
                break;
            case 3:
                if (T[1] & 2) {
                    v = buf[D_00478DD0[j]];
                    if (v < *(s16 *)(D_0062C500 + i * 8)) T[0xC + j] = 0;
                    else T[0xC + j] = v;
                }
                break;
            }
            j++;
            off8 += 8;
            off4 += 4;
        } while (j < 16);
        *(s32 *)(D_0062C538 + o52) = t2;
        if (D_0062C531[o52] & 0x20) {
            *(s16 *)(D_0062C54C + o52) = D_0062C706[o32] - 0x80;
            *(s16 *)(D_0062C54E + o52) = D_0062C707[o32] - 0x80;
            if (*(s16 *)(D_0062C54C + o52) < -0x7F) *(s16 *)(D_0062C54C + o52) = -0x7F;
            if (*(s16 *)(D_0062C54E + o52) < -0x7F) *(s16 *)(D_0062C54E + o52) = -0x7F;
        }
        if (D_0062C531[o52] & 0x40) {
            *(s16 *)(D_0062C558 + o52) = D_0062C704[o32] - 0x80;
            *(s16 *)(D_0062C55A + o52) = D_0062C705[o32] - 0x80;
            if (*(s16 *)(D_0062C558 + o52) < -0x7F) *(s16 *)(D_0062C558 + o52) = -0x7F;
            if (*(s16 *)(D_0062C55A + o52) < -0x7F) *(s16 *)(D_0062C55A + o52) = -0x7F;
        }
        *s4 = *s2;
        *(s16 *)(D_0062C662 + o32) = ~*(s16 *)(D_0062C662 + o32);
        break;
    default:
        *(s32 *)(D_0062C538 + o52) = 0;
        *(s16 *)(D_0062C54C + o52) = 0;
        *(s16 *)(D_0062C54E + o52) = 0;
        *(s16 *)(D_0062C558 + o52) = 0;
        *(s16 *)(D_0062C55A + o52) = 0;
        break;
    }
    return 1;
}
