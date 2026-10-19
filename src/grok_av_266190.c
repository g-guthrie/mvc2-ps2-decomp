typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_001B3E30(u8 *, int);
extern void func_001757E0(u8 *, int, int);

void func_00266190(u8 *p)
{
    u8 k;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if ((s16)(--*(s16 *)(p + 0x1C)) > 0)
        return;
    p[6]++;
    *(u32 *)(p + 0x48) = 0xE000;
    k = p[0x20];
    if (k == 0x10) {
        *(f32 *)(p + 0x38) -= 8.571428298950195f;
        func_001B3E30(p, 0x10);
    } else if (k == 0x14) {
        *(f32 *)(p + 0x38) -= 17.14285659790039f;
        func_001B3E30(p, 0x11);
    } else if (k == 0x18) {
        func_001B3E30(p, 0x12);
    }
    func_001757E0(p, 0x16, 9);
}
