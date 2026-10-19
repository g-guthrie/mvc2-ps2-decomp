typedef unsigned char u8;
typedef float f32;

extern void func_001E3CE0(int);
extern u8 D_00583B90[];

void func_001389A0(u8 *p)
{
    *(f32 *)(p + 0x50) += 0.1f;
    if (*(f32 *)(p + 0x50) >= 1.0f) {
        p[4]++;
        if (p[0x21] == 0) {
            D_00583B90[p[0x20]] = 0;
            func_001E3CE0(0x39);
        }
    }
}
