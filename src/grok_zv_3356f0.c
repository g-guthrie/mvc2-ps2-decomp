typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004B7F68[];
extern s16 D_004B7F70[];
extern int D_004C283C;
extern double func_00119058(f32);
extern void func_00335830(u8 *);

void residual_003356F0(u8 *p)
{
    f32 cur;
    f32 nxt;
    cur = D_004B7F68[p[5]];
    *(f32 *)(p + 0x60) = cur;
    *(u32 *)(p + 0x44) = (u16)(u32)(0.5 + 65536.0 * func_00119058(cur) / 360.0);
    p[5] = p[5] + 1;
    p[5] = p[5] & 1;
    nxt = D_004B7F68[p[5]];
    *(f32 *)(p + 0x6C) = nxt;
    *(f32 *)(p + 0x54) = (nxt - *(f32 *)(p + 0x60)) / 200.0f;
    {
        s16 t = *(s16 *)(p + 0x1E) + 1;
        *(s16 *)(p + 0x1E) = t;
        if (t >= 10) {
            *(s16 *)(p + 0x1E) = 0;
            p[6] = (p[6] + 1) & 3;
            *(s16 *)(p + 0xCC) = D_004B7F70[p[6]];
            *(int *)(p + 0x84) = D_004C283C;
        }
    }
    p[4] = 1;
    func_00335830(p);
}
