typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G28a;
extern G28a *D_004C2794;
extern u8 data_s8_004C10D4[4];
extern u8 D_004C10D8[4];
extern u8 D_004C10DC[4];
extern u8 D_004C10EC[4];
extern u8 D_004C10F0[4];
extern u8 D_004C10F4[4];

void func_002E4ED0(u8 *p)
{
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *a2;
    s32 s0;
    s32 v0;
    s32 v1;
    s32 m;
    f32 f;

    a2 = p + 0x2B8;
    switch (p[0x1FC]) {
    case 0:
        v0 = 0xF;
        s0 = 0;
        v1 = 0x14;
        if (p[0x210] == 0) {
            *(u8 **)(p + 0x408) = data_s8_004C10D4;
        } else {
            *(u8 **)(p + 0x408) = D_004C10EC;
        }
        p[0x1BB] = 0;
        break;
    case 1:
        s0 = 1;
        v0 = 0x10;
        v1 = 0x15;
        if (p[0x210] == 0) {
            *(u8 **)(p + 0x408) = D_004C10D8;
        } else {
            *(u8 **)(p + 0x408) = D_004C10F0;
        }
        p[0x1BB] = 1;
        break;
    case 2:
        s0 = 2;
        v0 = 0x11;
        v1 = 0x16;
        if ((*(u16 *)(p + 0x20E) & 0x1000) != 0) {
            f = 188.57142639160156f + *(f32 *)(p + 0x430);
            if (!(*(f32 *)(p + 0x38) <= f)) {
                *(s32 *)(p + 0x5C) = 0;
                *(s32 *)(p + 0x60) = 0;
                v0 = 0x12;
                *(s32 *)(p + 0x68) = 0;
                s0 = 5;
                *(s32 *)(p + 0x6C) = 0;
                p[6] = 0;
                p[0x210] = 0;
                p[0x1EA] = 0;
                p[0x1E8] = 0;
                a2[0x10] = 1;
            }
        }
        if (p[0x210] == 0) {
            *(u8 **)(p + 0x408) = D_004C10DC;
        } else {
            *(u8 **)(p + 0x408) = D_004C10F4;
        }
        p[0x1BB] = 2;
        break;
    default:
        break;
    }
    p[0x1B5] = v0;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001E3710(p, v1 & 0xFF);
    func_001757E0(p, 0xC, s0 & 0xFF);
}
