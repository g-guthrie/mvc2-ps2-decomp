typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;

typedef struct { f32 x, y, z; } Float3;

extern u8 *func_003DA750(void *, int, int);
extern void func_00156750(u8 *);
extern void func_001567A0(u8 *, int);
extern void func_001568A0(u8 *, int);
extern void func_001569C0(u8 *, int);
extern void func_00156AD0(u8 *, int);
extern void func_001550D0(Float3 *, int, int, int);
extern s8 D_004D1900;
extern Float3 D_00444BA0;

void func_00156520(Float3 *pos, int a1, int mode, int a3, int kind)
{
    u8 *p = func_003DA750(0, kind, 1);
    if (p == 0) {
    } else {
        D_004D1900++;
        *(void (**)(u8 *))(p + 16) = func_00156750;
        p[316] = 0;
        *(Float3 *)(p + 52) = *pos;
        *(u32 *)(p + 208) = 0x800181;
        if (mode == 1) {
            *(u32 *)(p + 208) |= 0x10;
            *(Float3 *)(p + 80) = D_00444BA0;
        }
        func_001567A0(p, kind);
        func_001568A0(p, kind);
        func_001569C0(p, kind);
        func_00156AD0(p, kind);
        func_001550D0(pos, mode, a3, kind);
    }
}
