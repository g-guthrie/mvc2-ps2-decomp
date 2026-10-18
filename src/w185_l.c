typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_00477290[];
extern u8 D_004F7D10[];
extern u8 D_004B91D0[];
extern f32 D_004F7FD0;
extern f32 D_004F7FD4;

void func_003D4950(void)
{
    extern void func_00417AE0();
    f32 *q;
    s32 i, off, k;
    u8 *r;
    u8 *e;
    f32 x;
    q = D_00477290;
    off = 0;
    k = 0;
    for (i = 0; i < 2; i++) {
        r = D_004F7D10 + off;
        e = D_004B91D0 + *(s8 *)(r + 0xC) * 8;
        x = D_004F7FD0 + 4.0f * (f32)(e[0] + k) - 4.0f;
        q[0] = q[8] = x;
        x = 8.0f + (D_004F7FD0 + 4.0f * (f32)(e[2] + k));
        q[4] = q[12] = x;
        x = D_004F7FD4 + 16.0f * (f32)(*(s8 *)r + 11) - 2.0f - 16.0f;
        q[1] = q[5] = x;
        x = 1.0f + (16.0f + (D_004F7FD4 + 16.0f * (f32)(*(s8 *)r + 11))) - 16.0f;
        q[9] = q[13] = x;
        func_00417AE0(4, q);
        off += 16;
        k += 0x35;
    }
}
