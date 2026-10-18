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
extern void func_0018A990();
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

s32 func_002EDF90(u8 *a)
{
    if (func_00189950(a, D_0045B740, a + 0x388) == 0) return 0;
    if (a[0x20D] == 2) return 0;
    if (a[0x20D] == 3) return 0;
    if (func_0018A580(a) == 0) return 0;
    func_0018A990(a, a + 0x388);
    a[0x1FD] = 3;
    a[5] = 0;
    a[7] = 0;
    a[6] = 0;
    func_00186A60(a, 0x15);
    return 1;
}

void func_00280550(u8 *a)
{
    switch (a[0x451]) {
    case 0:
        a[0x451]++;
        *(u8 **)(a + 0x474) = D_00455480;
    case 1:
        a[0x451]++;
        if (func_00280750(a)) *(u8 **)(a + 0x474) = D_00455480;
        *(u8 **)(a + 0x474) = func_00280AE0(a, *(u8 **)(a + 0x474));
        break;
    case 2:
        D_00455470[a[0x454]](a);
        break;
    }
}
