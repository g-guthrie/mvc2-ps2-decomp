typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern int func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_00183D50(u8 *);

void func_002B53C0(u8 *p)
{
    unsigned int offset;
    u8 cmd;

    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (p[0x15B]) {
        if (p[0x269] == 3) {
            cmd = (u8)((s8)p[0x15B] + 0x1C);
            p[0x1B5] = cmd;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(int *)(p + 0x1D8) = 0;
            offset = p[2] * 2;
            offset += (unsigned int)D_004C2794;
            ++*(short *)(offset + 0x7C);
        } else {
            cmd = p[0x15B];
            p[0x1B5] = cmd;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(int *)(p + 0x1D8) = 0;
            offset = p[2] * 2;
            offset += (unsigned int)D_004C2794;
            ++*(short *)(offset + 0x7C);
        }
        p[0x15B] = 0;
    }
    if (*(f32 *)(p + 0x430) <= *(f32 *)(p + 0x38))
        return;
    p[6]++;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x20D] = 1;
    if (p[0x1B7] == 0)
        func_001757E0(p, 21, 40);
    else
        func_001757E0(p, 21, 42);
    func_00183D50(p);
}
