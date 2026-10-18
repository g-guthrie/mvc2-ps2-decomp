typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_001757E0(void *, s32, s32);
extern s32 func_00189950(void *, void *, void *);
extern s32 func_0018A580(void *);
extern void func_0018A990(void *, void *);
extern s32 func_00186A60(void *, s32);
extern void func_0011D8F8(void *, s32, s32);
extern void func_0018E6C0(void *);
extern void func_0015D010(void *, f32 *);
extern void func_0018C6E0(void *);
extern void func_001D91E0(void *, s32, s32);
extern void func_002D5590(void *);
extern void func_0011F938(void *, void *, s32);
extern u8 D_0045B740[];
extern u8 D_004D18EC;
extern u8 D_004B1130[];
extern u8 D_0043E3D0[];
extern u8 D_00455480[];
extern void (*D_00455470[])(void *);
extern s32 func_00280750(void *);
extern u8 *func_00280AE0(void *, u8 *);



void func_002D5670(u8 *a)
{
    f32 v[3];
    func_002D5590(a);
    if (a[0x22] & 1) {
        u8 *p;
        *(s16 *)(a + 0x140) ^= 1;
        a[0x1E6] = *(s8 *)(a + 0x140);
        p = *(u8 **)(a + 0x1DC);
        *(s16 *)(p + 0x140) ^= 1;
        p = *(u8 **)(a + 0x1DC);
        p[0x1E6] = *(s8 *)(p + 0x140);
    }
    a[0x1B4] = 0xA;
    a[0x1E8] = 1;
    v[0] = -93.33332825f;
    v[2] = 0.0f;
    v[1] = 137.1428528f;
    func_0015D010(a, v);
    func_001757E0(a, 0xF, 1);
}

void func_002FF4D0(u8 *a)
{
    f32 v[3];
    if (a[0x22] & 1) {
        a[0x1E6] ^= 1;
        *(s16 *)(a + 0x140) = a[0x1E6];
    }
    a[0x1B4] = 0xA;
    func_001757E0(a, 0xF, 3);
    *(s32 *)(a + 0x5C) = 0;
    *(s32 *)(a + 0x60) = 0;
    *(s32 *)(a + 0x68) = 0;
    *(s32 *)(a + 0x6C) = 0;
    v[0] = -166.6666565f;
    v[1] = 32.1428566f;
    v[2] = 0.0f;
    func_0015D010(a, v);
    func_0018C6E0(a);
    func_001D91E0(a, 4, 0);
}

void func_00181730(f32 x, u8 *a, u8 *b, f32 *c)
{
    s32 m;
    if (x > 26.66666603f) x = 26.66666603f;
    m = (s8)a[0x211];
    if (m & (1 << a[0x1E6])) {
        if (m & 2) x = -x;
    } else if (c[0] < c[1]) {
        x = -x;
    }
    *(f32 *)(b + 0x34) -= x;
    D_004D18EC |= (u8)((1 << (s8)a[0x1B8]) | (1 << (s8)b[0x1B8]));
}

