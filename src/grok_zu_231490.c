typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern u8 D_004F1F45;
extern u8 D_004F1F46;
extern void func_00175700(u8 *);
extern void func_001E3210(u8 *, s32);
extern void func_0018FDB0(u8 *);
extern void func_00190D50(u8 *, u8 *);
extern void func_0015B660(f32 *);
extern void func_001E3710(u8 *, s32);
extern void func_001E3A40(u8 *);

void func_00231490(u8 *p)
{
    f32 z;
    func_00175700(p);
    if ((s8)p[0x151] == 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (!(*(f32 *)(p + 0x430) <= *(f32 *)(p + 0x38))) {
            if (p[0x20] == 0) {
                z = *(f32 *)(p + 0x430) + 274.285736f;
                if (z < *(f32 *)(p + 0x38)) {
                    u32 t = p[0x20];
                    p[0x20] = t + 1;
                    func_001E3210(p, 5);
                }
            }
        } else {
            f32 v[2];
            u8 *q;
            u32 t = p[7];
            p[7] = t + 1;
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            *(s16 *)(p + 0x1C) = 0x10;
            p[0x1B5] = 0x25;
            q = *(u8 **)(p + 0x1DC);
            *(u8 **)(q + 0x1C8) = p;
            func_0018FDB0(p);
            func_00190D50(q, p);
            D_004F1F45 = 3;
            D_004F1F46 = 1;
            v[0] = *(f32 *)(p + 0x34);
            v[1] = *(f32 *)(p + 0x430);
            func_0015B660(v);
            func_001E3710(p, 0x4A);
            func_001E3A40(p);
        }
    }
}
