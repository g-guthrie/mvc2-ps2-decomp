typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G15c;
extern G15c *D_004C2794;
extern u8 *D_004C299C;
extern u8 *D_004C2998;
extern u16 D_004D18DC[];
extern u8 D_004D18DB[];

void func_0037FAE0(u8 *p) {
    extern void func_0037F920(u8 *);
    extern s32 func_0037F550(u8 *);
    extern void func_0037F480(u8 *);
    extern void func_001E7F60(u8 *);
    u32 t;
    u8 n, e;
    s8 d;
    u32 w;
    if ((*(u8 **)(p + 0x18))[4] >= 2) {
        t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
        func_0037F920(p);
        return;
    }
    if ((D_004D18DC[0] & (1 << D_004D18DB[0])) != 0) return;
    D_004C299C[1] = 1;
    if (D_004C2998[2] < D_004C299C[6]) {
        p[0x13C] = 0;
        return;
    }
    if (D_004C2998[2] == D_004C299C[6]) {
        D_004C299C[1] = 2;
        ((s8 *)D_004C299C)[0] = -1;
    }
    p[0x13C] = func_0037F550(p);
    if (((s8 *)p)[0x1B2] != 0) {
        D_004C299C[1] = 1;
        ((s8 *)D_004C299C)[0] = -1;
        D_004C2998[7] = 0xFF;
        d = ((s8 *)p)[0x1B4] - 1;
        p[0x1B4] = d;
        if (d == 0) {
            w = D_004C299C[5];
            n = w + 1;
            D_004C299C[5] = n;
            e = 0x35;
            if (n >= 4) {
                e = 0x36;
                D_004C299C[5] = 0;
            }
            p[0x1B5] = e;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
        }
    }
    if (((s8 *)p)[0x13C] != 0) func_0037F480(p);
    if (D_004C2998[7] == 0) func_001E7F60(p);
}
