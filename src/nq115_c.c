typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3c;
typedef struct { s8 b[16]; } B16c;

extern u8 D_004C2A60;
extern u8 *D_004C2A68;
extern u8 D_0062C530[];

void func_003DAE90(void) {
    extern void func_003ED920(void);
    extern void func_003DB890(u8 *, u32);
    extern void func_003DB8E0(u8 *);
    extern void func_003DB020(void);
    s32 i;
    s32 so;
    s32 dof;
    u8 *src;
    u8 *e;
    u16 h;

    func_003ED920();
    D_004C2A60 = 0;
    i = 0;
    so = 0;
    dof = 0;
    while ((s16)i < 5) {
        src = D_0062C530 + so;
        D_004C2A68[dof] = src[0];
        D_004C2A68[dof + 1] = src[1];
        *(u16 *)(D_004C2A68 + dof + 2) = *(u16 *)(src + 2);
        *(f32 *)(D_004C2A68 + dof + 4) = *(f32 *)(src + 4);
        e = D_004C2A68 + dof;
        h = *(u16 *)(e + 2);
        if (h != 0 && h != 0x8000) {
            D_004C2A60++;
        }
        *(V3c *)(e + 0x2C) = *(V3c *)(src + 0x1C);
        *(V3c *)(D_004C2A68 + dof + 0x38) = *(V3c *)(src + 0x28);
        *(B16c *)(D_004C2A68 + dof + 0x1C) = *(B16c *)(src + 0xC);
        func_003DB890(D_004C2A68 + dof, *(u32 *)(src + 8));
        func_003DB8E0(D_004C2A68 + dof);
        e = D_004C2A68 + dof;
        i = (s16)(i + 1);
        so += 0x34;
        dof += 0x88;
        *(u32 *)(e + 0x44) = *(u32 *)(e + 0x10);
    }
    func_003DB020();
}
