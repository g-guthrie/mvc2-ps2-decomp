typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794;
extern void func_001861B0(u8 *);
extern void func_0018C4B0(u8 *, int);
extern int func_001757E0(u8 *, int, int);
extern void func_00183D90(u8 *);
extern void func_001863F0(u8 *);
extern int func_00175700(u8 *);
extern void func_0022C5D0(u8 *);

void func_002273E0(u8 *p)
{
    if (p[6] == 0) {
        p[6]++;
        func_001861B0(p);
        func_0018C4B0(p, 5);
        p[0x20D] = 0;
        p[0x1B5] = 0x78;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        {
            u32 off = p[2] * 2;
            off += (u32)D_004C2794;
            ++*(s16 *)(off + 0x7C);
        }
        func_001757E0(p, 0x14, 0x17);
    }
    if (p[0x213] == 3)
        func_00183D90(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_001863F0(p);
    if ((s8)func_00175700(p) < 0)
        func_0022C5D0(p);
    else if (*(s8 *)(p + 0x150) > 0) {
        f32 f1 = (5.0f / 3.0f) * (f32)*(s8 *)(p + 0x150);
        if (*(s16 *)(p + 0x140))
            f1 = -f1;
        *(f32 *)(p + 0x34) += f1;
        p[0x150] = 0;
    }
}
