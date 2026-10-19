/* MWCCPS2 3.0.3: -O3 -sdatathreshold 0 */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_001AFCB0(void *, u8);
extern int func_001757E0(u8 *, int, int);

void func_00258850(u8 *p)
{
    s32 offset;

    p[7]++;
    *(f32 *)(p + 0x5c) = *(f32 *)(p + 0x34);
    offset = *(s16 *)(p + 0x140) ? -324 : 324;
    *(f32 *)(p + 0x34) += (f32)offset;
    *(s16 *)(p + 0x1c) = 18;
    *(f32 *)(p + 0x38) = 72.0f;
    func_001AFCB0(p, 2);
    func_001AFCB0(p, 3);
    func_001AFCB0(p, 4);
    func_001757E0(p, 18, 0);
}
