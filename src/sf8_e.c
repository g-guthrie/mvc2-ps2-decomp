/* MW 3.0.3: MWWARM@src/wrm1_l.c "-O3 -Op -fp off -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { V3 a; V3 b; } E3E0;
extern E3E0 D_0045E3E0[];
extern u8 *D_004C2840;
typedef struct { u8 pad[0x1C]; s16 h1C; } PK;
extern s32 D_004C283C;

void func_0032F1B0(u8 *p)
{
    extern u32 func_00417A40(void);
    extern f32 func_00417440(u32);
    PK *sa = (PK *)p;
    s16 v;
    u32 t;

    switch (p[4]) {
    case 0:
        p[0x13C] = 0;
        v = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = v;
        if (v >= 0x3C) {
        sa->h1C = 0x3C;
        t = *(u32 *)(D_004C2840 + 0x94);
        if (!(t > 0x1F4 && t < 0x3E8) && !(t > 0xDAC && t < 0x1194)) {
        p[4]++;
        p[0x20] = func_00417A40() % 6;
        *(s16 *)(p + 0x1C) = 0;
        p[0x13C] = 1;
        *(s16 *)(p + 0xCC) = (s32)func_00417A40() % 2 + 9;
        *(s32 *)(p + 0x84) = D_004C283C;
        *(V3 *)(p + 0x34) = D_0045E3E0[p[0x20]].a;
        *(s32 *)(p + 0x48) = (s32)func_00417A40() % 0x4000;
        }
        }
        break;
    case 1:
        *(f32 *)(p + 0x34) += (D_0045E3E0[p[0x20]].b.x - D_0045E3E0[p[0x20]].a.x) / 120.0f;
        *(f32 *)(p + 0x38) += (D_0045E3E0[p[0x20]].b.y - D_0045E3E0[p[0x20]].a.y) / 120.0f;
        *(f32 *)(p + 0x3C) += (D_0045E3E0[p[0x20]].b.z - D_0045E3E0[p[0x20]].a.z) / 120.0f;
        *(f32 *)(p + 0x74) = func_00417440((u32)(s32)(0.15 * (double)(s32)((u32)(s32)(0.5 + 65536.0 * (double)(180.0f * (*(s16 *)(p + 0x1C) / 120.0f)) / 360.0) & 0xFFFF)));
        v = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = v;
        if (v >= 0x78) {
            p[4] = 0;
            sa->h1C = 0;
        }
        break;
    }
}
