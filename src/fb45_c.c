typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x76]; u8 f76; } G2f;
extern G2f *D_004C2794;
extern u8 D_0045B980[][4];
extern u8 D_0045B990[][4];

void func_002F0C50(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern void func_001D77A0(u8 *);
    extern void func_001D6E10(u8 *);
    extern void func_001D7070(u8 *);
    extern void func_001D7520(u8 *);
    extern void func_001906C0(u8 *, s32, s32, s32);
    extern void func_00131AB0(u8 *, u8 *, s32);
    extern void func_00175C00(u8 *, s32);
    extern void func_001830D0(u8 *, u32 *, s32);
    u32 v[4];
    s32 s0;
    s32 t;

    func_00175700(p);
    t = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = t;
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x33C] = 5;
        t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        s0 = 0;
        if (p[0x212] != 0) s0 = s0 + 2;
        if (p[0x1B7] != 0) s0 = s0 + 1;
        if (s0 == 0) s0 = 1;
        if (*(s32 *)(p + 0x2D4) != s0) {
            func_001D77A0(p);
            *(s32 *)(p + 0x30C) = 0;
        } else {
            *(s32 *)(p + 0x30C) = *(s32 *)(p + 0x30C) + 1;
            if (*(s32 *)(p + 0x30C) > 2) *(s32 *)(p + 0x30C) = 2;
        }
        *(s32 *)(p + 0x2D4) = s0;
        *(s32 *)(p + 0x2CC) = 0xFF;
        *(s32 *)(p + 0x2D8) = 0;
        p[0x219] = D_0045B980[*(s32 *)(p + 0x30C)][*(s32 *)(p + 0x2D4)];
        p[0x21A] = D_0045B990[*(s32 *)(p + 0x30C)][*(s32 *)(p + 0x2D4)];
        p[0x216] = 0;
        s0 = *(s32 *)(p + 0x2D0);
        *(s32 *)(p + 0x2D0) = 0x480;
        switch (*(s32 *)(p + 0x2D4)) {
        case 1:
            func_001D7520(p);
            break;
        case 2:
            func_001D7070(p);
            if (*(s32 *)(p + 0x30C) < 2) {
                func_001906C0(p, 0x480, 0, 0);
            } else {
                p[0x216] = 1;
            }
            break;
        case 3:
            func_001D6E10(p);
            break;
        case 0:
            *(s32 *)(p + 0x2D0) = 0;
            break;
        }
        func_00131AB0(p, (u8 *)((s32)p + 0x2D0), *(s32 *)(p + 0x30C) + 10);
        if (*(s32 *)(p + 0x30C) != 0) {
            if (s0 < 0x240) s0 = 0x240;
            *(s32 *)(p + 0x2D0) = s0;
        }
        func_00175C00(p, 1);
        *(s32 *)(p + 0x2B8) = 0;
        v[0] = 0x41AD5555;
        v[1] = 0x43B84924;
        func_001830D0(p, v, 1);
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        p[0x33B] = 1;
        D_004C2794->f76 = (*(s8 *)(p + 2) * 16) | 1;
        p[0x33C] = 0x10;
    }
}
