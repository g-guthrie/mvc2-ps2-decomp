typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[4]; u8 b4; } K48;
typedef struct { u8 pad[5]; s8 b5; } K2840;
typedef struct { u8 pad[0x23]; u8 b23; } K4;
typedef struct { u8 pad[5]; u8 b5; u8 pad2[0xDC - 6]; s32 wdc; } K8;
typedef struct {
    u8 pad0[4];
    K4 *p4;
    K8 *p8;
    u8 pad1[4];
    s16 h10;
    s16 pad12;
    s16 h14[3];
    s16 pad1a;
    s16 h1c[3][3];
    u8 pad2e[0x36 - 0x2E];
    s16 h36;
} G;

extern s16 D_004CA078[];
extern s16 D_004CA052[];
extern G D_004CA040;
extern K48 *D_004CA048[];
extern u16 D_004F7F92[];
extern u8 D_004D179A[];
extern u32 D_0043CD08[];
extern u8 *D_004C2840;
extern void func_0012CB90();
extern void func_0012CE00();

static s16 func_0012B8D0(s16 a, s16 b)
{
    if (b >= 3) return 4;
    return (a + b + 4) % 4;
}

void func_0012CF80(void)
{
    extern void func_001E3CE0(s32);
    extern void func_001E3890(s32);
    extern void func_0014CA80(void);
    extern void func_001317F0(s32);
    extern void func_0014D670(s32);
    extern s32 func_0012C5C0(G *, s32, s32);
    extern void func_0012C470(G *);
    extern void func_0014C280(s32, s32, s32);
    G *g;
    s32 i;
    s32 r;
    s16 *s3;
    s32 sh;
    u32 *ptr;
    r = 0;
    g = &D_004CA040;
    i = func_0012B8D0(D_004CA078[0], D_004CA052[0]);
    if (D_004CA048[0]->b4 == 0) {
        if (g->p8->b5 == 0) {
            sh = i * 6;
            s3 = (s16 *)(sh + (u32)g + 0x1C);
            if (*s3 > D_004F7F92[0]) {
                g->p4->b23 = 5;
                func_001E3CE0(5);
                goto L19C;
            }
            func_001E3890(0x2A);
            D_004F7F92[0] -= *(u16 *)s3;
            func_0014CA80();
            if (i == 1 || i == 2) {
                sh = g->h14[i];
                if (sh >= 0x20) {
                    ptr = (u32 *)(D_004C2840 + 0x34);
                } else {
                    ptr = (u32 *)(D_004C2840 + 0x30);
                }
                *ptr |= 1 << sh;
            } else if (i == 0) {
                if (g->h10 != 0) {
                    sh = g->h14[i];
                    if (sh >= 0x20) {
                        ptr = (u32 *)(D_004C2840 + 0x3C);
                    } else {
                        ptr = (u32 *)(D_004C2840 + 0x38);
                    }
                    *ptr |= 1 << sh;
                } else if (D_004D179A[0] < 7) {
                    D_004D179A[0]++;
                }
            } else {
                func_001317F0(g->h14[i]);
            }
            g->h14[i] = -1;
            g->h36++;
            func_0014D670(i);
            g->p4->b23 = 4;
            r = func_0012C5C0(g, 0, 1);
        } else {
            func_0012C470(g);
            if (g->p8->wdc != 0) {
                func_001E3CE0(2);
            } else {
                func_001E3CE0(3);
            }
        }
L19C:
        switch (r) {
        case -1:
            D_004C2840[5] = 3;
            func_0014C280(0, 0, 1);
            func_0014C280(1, 0, 1);
            func_0014C280(2, 0, 1);
            func_0014C280(3, 0, 1);
            D_0043CD08[0] = (u32)func_0012CE00;
            break;
        case 1:
            D_004C2840[5] = 4;
            func_0014C280(0, 0, 2);
            func_0014C280(1, 0, 2);
            func_0014C280(2, 0, 2);
            func_0014C280(3, 0, 2);
            D_0043CD08[0] = (u32)func_0012CE00;
            break;
        default:
            D_004C2840[5] = 2;
            D_0043CD08[0] = (u32)func_0012CB90;
            break;
        }
    }
}
