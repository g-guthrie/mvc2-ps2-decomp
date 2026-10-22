typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3_d;
typedef struct { s16 a, b; } P2_d;
typedef struct { u8 pad[0x84]; s8 f84; } K_d;
extern K_d *D_004C2840;
extern s32 D_004C283C;
typedef struct { V3_d row[1]; } M_d;
extern M_d *D_0045F7A0[];
extern s32 D_0045F7D0[];
extern P2_d D_0045F180[];

void func_0033EB00(u8 *p)
{
    extern void func_0032FEB0(f32, f32 *, f32 *, f32 *);
    f32 vx, vy, vz;
    s32 n;
    M_d *m;
    s16 i;

    n = D_0045F7D0[p[0x20]];
    m = D_0045F7A0[p[0x20]];
    *(s16 *)(p + 0xCC) = D_0045F180[(u32)D_004C2840->f84 % 0x12].a + 0x12;
    *(s32 *)(p + 0x84) = D_004C283C;
    func_0032FEB0((f32)*(s16 *)(p + 0x1C) / 50.0f, &vx, &vy, &vz);
    i = *(s16 *)(p + 0x1E);
    *(f32 *)(p + 0x34) = vx * m->row[i-1].x + vy * m->row[i].x + vz * m->row[i+1].x;
    *(f32 *)(p + 0x38) = vx * m->row[i-1].y + vy * m->row[i].y + vz * m->row[i+1].y;
    *(f32 *)(p + 0x3C) = vx * m->row[i-1].z + vy * m->row[i].z + vz * m->row[i+1].z;
    i = *(s16 *)(p + 0x1C) + 1;
    *(s16 *)(p + 0x1C) = i;
    if (i >= 50) {
        *(s16 *)(p + 0x1C) = 0;
        i = *(s16 *)(p + 0x1E) + 1;
        *(s16 *)(p + 0x1E) = i;
        if (i + 1 >= n) *(s16 *)(p + 0x1E) = 1;
    }
}
