typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x1C]; s32 f1C; } GA;
typedef struct { u8 pad[0x428]; u32 f428; } GB;

extern GA *D_004C2840;
extern s8 D_004C0FB0[8];
extern s8 D_004D18DE[];
extern u8 D_004D18E6[];
extern void (*D_0045A750[])(u8 *);

void func_002D7560(u8 *p)
{
    extern void func_00175C00(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u32 t;
    t = p[6];
    if (t == 0) {
        p[6] = t + 1;
        p[7] = 0;
        func_00175C00(p, 0);
        switch (p[0x20]) {
        case 0:
            if (((GB *)*(u32 *)(p + 0x220))->f428 & 0x4000000) {
                p[0x20] = 6;
            } else {
                p[0x20] = D_004C0FB0[(D_004C2840->f1C & 3) + (D_004D18E6[0] ? 4 : 0)];
            }
            break;
        case 1:
            p[0x20] = 2;
            func_001757E0(p, 0x13, 2);
            break;
        case 2:
        case 3:
            if (D_004D18DE[0] == p[2]) {
                p[0x20] = 7;
            } else {
                p[0x20] = 5;
                func_001757E0(p, 0x13, 5);
            }
            break;
        case 4:
            p[0x20] = 3;
            func_001757E0(p, 0x13, 5);
            break;
        }
    } else {
        D_0045A750[p[0x20]](p);
    }
}
