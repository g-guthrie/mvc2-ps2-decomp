typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x1C]; s16 h1c; } SA;
extern u8 D_004D18E6[];
extern u8 D_004C0B40[8];

void func_0029D370(u8 *p) {
    extern s32 func_00174170(void);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00176160(u8 *, s32, s32, s32);
    extern void func_00175700();
    extern void func_001E3210(u8 *, s32);
    extern void func_001CB610(u8 *, s32);
    SA *sa;
    u32 t = p[6];
    if (t == 0) {
        p[6] = t + 1;
        if (D_004D18E6[0] == 0) {
            p[7] = 0;
        } else {
            u32 h = (u32)(*(s16 *)(p + 0x4F0) & 0x360) & 0xFFFF;
            if (h != 0) {
                u16 g = h;
                u8 a = 0;
                if (g & 0x200) a = 0;
                if (g & 0x100) a = 1;
                if ((g & 0x300) == 0x300) a = 3;
                if (g & 0x40) a = 0;
                if (g & 0x20) a = 1;
                if ((g & 0x60) == 0x60) a = 3;
                p[7] = a;
            } else {
                p[7] = D_004C0B40[func_00174170() & 7];
            }
        }
        func_001757E0(p, 0x13, p[7]);
        *(s16 *)(p + 0x1C) = 0;
        func_00176160(p, 3, 0xB, 1);
        return;
    }
    func_00175700(p);
    sa = (SA *)p;
    if (p[7] == 1) {
        s16 v = sa->h1c;
        if (v != 0) {
            v = v - 1;
            sa->h1c = v;
            if (v <= 0) {
                func_001E3210(p, 0x13);
                *(s16 *)(p + 0x1C) = 0;
            }
        }
        p[0x33A] = 0xFF;
        if (*(s8 *)(p + 0x151) != 0) {
            *(s16 *)(p + 0x1C) = 0x3C;
            p[0x151] = 0;
            func_001CB610(p, 0xE);
        }
    }
}
