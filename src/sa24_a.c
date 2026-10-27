typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 f0;
    u8 pad[0x7B];
    s16 f7c[1];
} G24;
extern G24 *D_004C2794;

void func_002804E0(u8 *p)
{
    extern void func_00280E70(u8 *);
    extern void (*D_00455458[])(u8 *);
    if (D_004C2794->f0 == 4) {
        switch (*(s8 *)(p + 0x1B4)) {
        case 0:
            *(u16 *)(p + 0x4F0) = 0;
            p[0x471] = 0;
            func_00280E70(p);
            D_00455458[p[0x450]](p);
            break;
        default:
            break;
        }
    }
}

void func_002F9D60(u8 *p, void *context)
{
    u8 *q = (u8 *)context;
    extern s8 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x33C] = 5;
    p[0x1FE] = 1;
    p[0x201] = 2;
    p[0x209] = 2;
    if (func_00175700(p) < 0) {
        t = p[7];
        p[7] = t + 1;
        p[0x1FE] = 0;
        q[0xD] = 0;
        p[0x1B5] = 0x34;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        switch (p[0x20D]) {
        case 0:
        case 1:
            p[0x168] = 7;
            break;
        default:
            p[0x168] = 8;
            break;
        }
        func_001757E0(p, 0x16, p[0x168]);
        (*(u8 **)(p + 0x1DC))[0x20A] = 6;
    }
}
