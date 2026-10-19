typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern int func_001757E0(u8 *, int, int);

void func_002B4650(u8 *p)
{
    p[6]++;
    p[0x13C] = 1;
    if (*(s16 *)(p + 0x140) != 0) {
        *(u32 *)(p + 0x5C) = 0x41200000;
        *(u32 *)(p + 0x68) = 0xBDD55555;
        *(f32 *)(p + 0x34) += -126.66666412353516f;
    } else {
        *(u32 *)(p + 0x5C) = 0xC1200000;
        *(u32 *)(p + 0x68) = 0x3DD55555;
        *(f32 *)(p + 0x34) += 126.66666412353516f;
    }
    *(u32 *)(p + 0x60) = 0xC1092492;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    *(f32 *)(p + 0x38) += 514.2857055664062f;
    func_001757E0(p, 23, 2);
}
