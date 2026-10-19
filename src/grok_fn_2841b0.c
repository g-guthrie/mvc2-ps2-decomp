typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

typedef struct G { u8 pad[0x7C]; s16 t[2]; } G;
extern G *D_004C2794;
extern s32 func_00175700(u8 *);
extern s32 func_0018AB10(u8 *);
extern void func_001757E0(u8 *, s32, s32);

void func_002841B0(u8 *p, u8 *q)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0)
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (p[0x15B]) {
        p[0x1B5] = p[0x15B];
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->t[p[2]]++;
        *(s16 *)(p + 0x1C0) = 0x40;
        p[0x15B] = 0;
    }
    if (q[4] && func_0018AB10(p))
        q[4]--;
    else if ((s16)(--*(s16 *)(p + 0x1C)) == 0) {
        p[6]++;
        p[0x1B5] = 0x46;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->t[p[2]]++;
        func_001757E0(p, 0x16, 7);
    }
}
