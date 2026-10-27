typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x20E]; u16 h; } S98h;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G98c;
extern G98c *D_004C2794;
extern u8 D_004BFDA4[4], D_004BFD9C[4], D_004BFDB4[4], D_004BFDA0[4], D_004BFDB8[4], D_004BFDBC[4];

void func_002044A0(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E3710(u8 *, s32);
    u32 h;
    u32 t;
    s32 v;

    h = *(u16 *)(p + 0x20E);
    if (h & 0x1000) {
        p[6] = 1;
        p[0x1EA] = (s8)p[0x1EA] & 0xF;
        p[0x210] = 0;
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        if (((S98h *)p)->h & 0xC00) {
            p[0x168] = 0xD;
            p[0x1B5] = 0x15;
        } else {
            p[0x168] = 0xC;
            p[0x1B5] = 0x14;
        }
        *(u8 **)(p + 0x408) = D_004BFDA4;
        t = *(u8 *)(p + 0x1B5);
        p[0x1B5] = t;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        func_001757E0(p, 0x14, p[0x168]);
        return;
    }
    if ((h & 0x3C00) == 0x800) {
        p[6] = 3;
        p[0x1EA] = (s8)p[0x1EA] & 0xF;
        p[0x210] = 0;
        if (p[0x1FC] == 0) {
            *(u8 **)(p + 0x408) = D_004BFDA4;
        } else {
            *(u8 **)(p + 0x408) = D_004BFDA4;
        }
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        p[0x1B5] = 0x19;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        func_001757E0(p, 0x14, 0xE);
    } else {
        switch (p[0x1FC]) {
        case 0:
            if (p[0x210] == 0) {
                p[0x168] = 0;
                p[0x1B5] = 0xF;
                *(u8 **)(p + 0x408) = D_004BFD9C;
            } else {
                p[0x168] = 8;
                p[0x1B5] = 0x16;
                *(u8 **)(p + 0x408) = D_004BFDB4;
            }
            func_001E3710(p, 0x14);
            p[0x1BB] = 0;
            break;
        case 1:
            if (p[0x210] == 0) {
                p[0x168] = 1;
                p[0x1B5] = 0x10;
                *(u8 **)(p + 0x408) = D_004BFDA0;
            } else {
                p[0x168] = 9;
                p[0x1B5] = 0x17;
                *(u8 **)(p + 0x408) = D_004BFDB8;
            }
            func_001E3710(p, 0x15);
            p[0x1BB] = 1;
            break;
        case 2:
            if (p[0x210] == 0) {
                p[0x168] = 2;
                p[0x1B5] = 0x11;
                *(u8 **)(p + 0x408) = D_004BFDA4;
            } else {
                p[0x168] = 0xA;
                p[0x1B5] = 0x18;
                *(u8 **)(p + 0x408) = D_004BFDBC;
            }
            func_001E3710(p, 0x16);
            p[0x1BB] = 2;
            break;
        }
        t = *(u8 *)(p + 0x1B5);
        p[0x1B5] = t;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        if (p[0x210] == 0) p[0x169] = 0xC; else p[0x169] = 0x14;
        func_001757E0(p, p[0x169], p[0x168]);
        v = (s8)p[0x1EA];
        if ((v & 0xF0) != 0) p[0x1EA] = v - 0x10;
    }
}
