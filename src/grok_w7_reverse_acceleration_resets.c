typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_002F1DF0(u8 *);

void func_002F0330(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        func_002F1DF0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) == 0) return;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (!(*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) < 0.0f)) {
        *(f32 *)(p + 0x68) = 0.0f;
        *(f32 *)(p + 0x5C) = 0.0f;
    }
}

void func_002F0790(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        func_002F1DF0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) == 0) return;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (!(*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) < 0.0f)) {
        *(f32 *)(p + 0x68) = 0.0f;
        *(f32 *)(p + 0x5C) = 0.0f;
    }
}
