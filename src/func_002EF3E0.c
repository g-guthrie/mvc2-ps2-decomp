typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad0[0x7C]; s16 h7c[]; } G2EE;
extern G2EE *D_004C2794;
extern void func_00185490(u8 *);
extern void func_0018C4B0(u8 *, int);
extern int func_001757E0(u8 *, int, int);
extern void func_001E3210(u8 *, int);
extern int func_00175700(u8 *);
extern void func_00184540(void *);
extern void func_003A82E0(u8 *, u8 *);
extern void func_001D6B50(u8 *, u8);
void func_002EF3E0(u8 *p)
{
    if (p[6] == 0) {
        p[6]++;
        func_00185490(p);
        p[0x1B5] = 0x32;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->h7c[p[2]]++;
        p[0x20D] = 2;
        func_0018C4B0(p, 0xA);
        func_001757E0(p, 0x15, (u8)(*(u32 *)(p + 0x2D4) + 0x3C));
        *(f32 *)(p + 0x5C) /= 16.0f;
        *(f32 *)(p + 0x60) /= 8.0f;
        *(f32 *)(p + 0x6C) /= 64.0f;
        *(u32 *)(p + 0x68) = 0;
        func_001E3210(p, 4);
    }
    if (!(*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430) - 34.285713f)) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    }
    if ((s8)func_00175700(p) < 0) {
        *(f32 *)(p + 0x6C) = -0.803571403f;
        func_00184540(p);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        func_001E3210(p, 0x20);
        func_003A82E0(p, 0);
        func_001D6B50(p, 0);
        p[0x28F] = 0;
        p[0x28E] = 0x10;
    }
}
