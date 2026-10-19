typedef unsigned char u8;
typedef float f32;

extern void func_00183D90(u8 *);
extern void func_001863F0(u8 *);
extern void func_0025D6D0(u8 *);
extern void func_0025D650(u8 *);
extern void func_0025D5C0(u8 *);
extern void func_0025D740(u8 *);

void func_0025D3B0(u8 *p)
{
    func_00183D90(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_001863F0(p);
    if (p[0x212] == 1) {
        if (p[0x20D] == 1) {
            func_0025D6D0(p);
        } else {
            func_0025D650(p);
        }
    } else if (p[0x20D] == 1) {
        func_0025D5C0(p);
    } else {
        func_0025D740(p);
    }
}
