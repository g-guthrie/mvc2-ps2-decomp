typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794;
extern u8 D_004F20B0[];
void func_001905F0(void) {
    u8 *g = D_004C2794;
    if (g[6] == 0 && g[0] == 4) {
        s32 i = 0;
        u8 *e;
        s32 off = 0;
        do {
            e = D_004F20B0 + off;
            if (e[0] == 0) {
                s16 v = *(s16 *)(e + 0x2B4);
                if (v != 0) *(s16 *)(e + 0x2B4) = v - 1;
            }
            i++;
            off += 0x5B8;
        } while (i < 6);
    }
}

extern void func_0016B0C0(void *p, void *q, s32 n);
extern s32 func_00174170(void);
extern s8 D_004BF480[4];
s32 func_00165D50(u8 *p, u8 *q) {
    s32 v;
    func_0016B0C0(p, q, 0);
    func_0016B0C0(p, q, 1);
    v = *(s32 *)(p + 0x4C8);
    if (v == 0) {
        v = D_004BF480[func_00174170() & 3];
    }
    p[0x472] = v;
    return 1;
}
