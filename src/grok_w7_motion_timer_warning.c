typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);

void func_003076B0(u8 *p)
{
    s16 timer;

    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);

    timer = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = timer - 1;
    if (timer == 0) {
        func_001843A0(p);
    } else if (*(s16 *)(p + 0x1C) < 9 && *(u16 *)(p + 0x362) != 0) {
        func_001843A0(p);
    }
}
