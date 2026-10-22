typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct O {
    u8 p0[4];
    u8 b4, b5, p6, b7;
    u8 p8[0x1E - 8];
    s16 h1E;
    u8 p20[3];
    u8 b23;
    u8 p24[0x34 - 0x24];
    f32 f34, f38, f3C;
    u8 p40[0x10];
    f32 f50, f54;
    u8 p58[0x78 - 0x58];
    f32 f78, f7C, f80;
    u32 w84;
    u8 p88[0xCC - 0x88];
    s16 hCC;
    u8 pCE[2];
    s32 wD0;
    u8 pD4[0x13C - 0xD4];
    u8 b13C;
    u8 p13D[0x1E4 - 0x13D];
} O;
extern u32 D_004C27FC;
extern u8 D_004D179A[];
extern f32 D_00443ED0[];
extern O *D_004CAE30[];
extern O *D_004CAE48[];
extern O *D_004CAE6C[];
extern O *D_004CAE70[];
extern O *D_004CAE7C[];

void func_0014B020(O *p) {
    extern s32 func_0012ABC0(s32, s32);
    extern void func_001E3CE0(s32);
    extern void func_0012AD00(O *);
    u16 k;
    s32 i;
    O *o;
    k = func_0012ABC0(3, 0);
    if (p->b23 == 0) {
        p->f34 = 2.8599999f;
        p->f3C = -12.8699999f;
        if (p->b4 == 0) {
            p->b5 = 0;
            p->b4 = 1;
        } else {
            if (k & 0x2000) {
                if (p->b5 != 0) {
                    p->b5 = p->b5 - 1;
                    p->h1E = -9;
                    func_001E3CE0(1);
                }
            }
            if (k & 0x1000) {
                if (p->b5 != 7) {
                    p->b5 = p->b5 + 1;
                    p->h1E = -9;
                    func_001E3CE0(1);
                }
            }
        }
        if (p->b5 == 7) {
            p->b13C = 1;
            p->f34 = 6.01999998f;
            p->f38 = -7.61999989f;
            p->f3C = -13.0500002f;
            p->f50 = 1.0f;
            p->f54 = 0.300000012f;
            D_004CAE70[0]->b13C = 0;
            D_004CAE30[0]->b7 = 0;
            D_004CAE7C[0]->f80 = 1.0f;
            D_004CAE7C[0]->f7C = 1.0f;
            D_004CAE7C[0]->f78 = 1.0f;
        } else {
            p->b13C = 1;
            p->f38 = D_00443ED0[p->b5];
            p->f50 = 0.699999988f;
            p->f54 = 0.200000003f;
            D_004CAE6C[0]->hCC = p->b5 + 0xBF;
            D_004CAE6C[0]->w84 = D_004C27FC;
            if (D_004D179A[0] >= p->b5 + 1) {
                D_004CAE6C[0]->b13C = 1;
            } else {
                D_004CAE6C[0]->b13C = 0;
            }
            D_004CAE70[0]->b13C = 1;
            D_004CAE70[0]->f34 = p->f34 - 1.58000004f;
            D_004CAE70[0]->f38 = p->f38;
            D_004CAE70[0]->f3C = 0.100000001f + p->f3C;
            D_004CAE7C[0]->f80 = 0.800000012f;
            D_004CAE7C[0]->f7C = 0.800000012f;
            D_004CAE7C[0]->f78 = 0.800000012f;
        }
        o = D_004CAE48[0];
        i = 0;
        do {
            o->wD0 = 0x400;
            if (i == p->b5) {
                o->f78 = 1.0f;
                o->f7C = 0.800000012f;
                o->f80 = 0.200000003f;
            } else if (i + 1 <= D_004D179A[0]) {
                o->f78 = 0.400000006f;
                o->f80 = 1.0f;
                o->f7C = 1.0f;
            } else {
                o->f78 = 0.400000006f;
                o->f7C = 0.200000003f;
                o->f80 = 0.5f;
            }
            i++;
            o++;
        } while (i < 7);
    } else {
        if (p->b4 == 0) {
            p->b5 = 0;
            p->b4 = 1;
        } else {
            if (k & 0x2000) {
                if (p->b5 != 0) {
                    p->b5 = p->b5 - 1;
                    p->h1E = -9;
                    func_001E3CE0(1);
                }
            }
            if (k & 0x1000) {
                if (p->b5 != 1) {
                    p->b5 = p->b5 + 1;
                    p->h1E = -9;
                    func_001E3CE0(1);
                }
            }
        }
        if (p->b5 != 0) {
            p->b13C = 1;
            p->f34 = 6.01999998f;
            p->f38 = -7.61999989f;
            p->f3C = -13.0500002f;
            p->f50 = 1.0f;
            p->f54 = 0.300000012f;
            D_004CAE30[0]->b7 = 0;
            D_004CAE7C[0]->f80 = 1.0f;
            D_004CAE7C[0]->f7C = 1.0f;
            D_004CAE7C[0]->f78 = 1.0f;
        } else {
            p->b13C = 0;
            D_004CAE7C[0]->f80 = 0.800000012f;
            D_004CAE7C[0]->f7C = 0.800000012f;
            D_004CAE7C[0]->f78 = 0.800000012f;
        }
    }
    func_0012AD00(p);
}
