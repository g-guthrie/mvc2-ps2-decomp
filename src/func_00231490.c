typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } EffectPosition;

extern int func_00175700(u8 *);
extern void func_001E3210(u8 *, s32);
extern void func_0018FDB0(u8 *);
extern void func_00190D50(u8 *, u8 *);
extern void func_0015B660(u8 *, s32);
extern void func_001E3710(u8 *, s32);
extern void func_001E3A40(u8 *);
extern u8 D_004F1F45;
extern u8 D_004F1F46;

void func_00231490(u8 *p, u8 *q)
{
    EffectPosition values;
    f32 height;
    f32 limit;
    f32 top;
    u8 *owner;

    func_00175700(p);
    if ((s8)p[0x151] == 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    }

    height = *(f32 *)(p + 0x38);
    limit = *(f32 *)(p + 0x430);
    if (height > limit) {
        if (p[0x20] == 0) {
            top = 274.28570556640625f + limit;
            if (top >= height) {
                p[0x20]++;
                func_001E3210(p, 5);
                return;
            }
            goto done;
        }
        goto done;
    }

    *(f32 *)(p + 0x38) = limit;
    p[7]++;
    *(s16 *)(p + 0x1C) = 0x10;
    {
        owner = *(u8 **)(p + 0x1DC);
        *(u8 **)(owner + 0x1C8) = p;
        *(s8 *)(owner + 0x1B5) = 0x25;
        func_0018FDB0(p);
        func_00190D50(owner, p);
        D_004F1F45 = 3;
        D_004F1F46 = 1;
        values.x = *(f32 *)(owner + 0x34);
        values.y = *(f32 *)(owner + 0x430);
        func_0015B660((u8 *)&values, 1);
    }
    func_001E3710(p, 0x4A);
    func_001E3A40(p);
done:
    return;
}
