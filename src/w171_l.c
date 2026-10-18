typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 a, b, c, d; } Row8120;
extern Row8120 D_00459EA0[];
extern Row8120 data_u32_00454930[];
extern s32 func_00175700(u8 *);
extern void func_00186A20(u8 *);

typedef struct { u8 pad[0x160]; s8 b[8]; } S8120;

void func_002C8120(u8 *p)
{
    s8 *r;
    s8 *q;
    u32 t;
    func_00175700(p);
    r = ((S8120 *)p)->b;
    q = r + 1;
    if (r[1] != 0) {
        t = p[7];
        p[7] = t + 1;
        *q = 0;
        *(f32 *)(p + 0x5C) = (p[0x1E6] != 0) ? D_00459EA0[p[0x1B7]].a : -D_00459EA0[p[0x1B7]].a;
        *(f32 *)(p + 0x68) = (p[0x1E6] != 0) ? D_00459EA0[p[0x1B7]].b : -D_00459EA0[p[0x1B7]].b;
        *(f32 *)(p + 0x60) = D_00459EA0[p[0x1B7]].c;
        *(f32 *)(p + 0x6C) = D_00459EA0[p[0x1B7]].d;
    }
}

void func_00271820(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        p[7]++;
        func_00186A20(p);
        *(f32 *)(p + 0x5C) = (p[0x1E6] != 0) ? data_u32_00454930[p[0x1B7]].a : -data_u32_00454930[p[0x1B7]].a;
        *(f32 *)(p + 0x68) = (p[0x1E6] != 0) ? data_u32_00454930[p[0x1B7]].b : -data_u32_00454930[p[0x1B7]].b;
        *(f32 *)(p + 0x60) = data_u32_00454930[p[0x1B7]].c;
        *(f32 *)(p + 0x6C) = data_u32_00454930[p[0x1B7]].d;
    }
}
