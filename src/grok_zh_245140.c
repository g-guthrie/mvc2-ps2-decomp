typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_001861B0(u8 *);
extern void func_0018C4B0(u8 *, int);
extern void func_001757E0(u8 *, int, int);
extern void func_001E3710(u8 *, int);
extern void func_00183D90(u8 *);
extern void func_001863F0(u8 *);
extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);

void residual_00245140(u8 *p)
{
    unsigned int offset;

    if (p[6] == 0) {
        func_001861B0(p);
        p[6]++;
        func_0018C4B0(p, 5);
        if (p[0x212] == 0) {
            p[0x20D] = 0;
            func_001757E0(p, 20, 6);
            {
                u8 cmd = 26;
                p[0x1B5] = cmd;
                p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                *(int *)(p + 0x1D8) = 0;
            }
            offset = p[2] * 2;
            offset += (unsigned int)D_004C2794;
            ++*(short *)(offset + 0x7C);
            func_001E3710(p, 22);
        } else {
            p[0x20D] = 0;
            func_001757E0(p, 20, 7);
            {
                u8 cmd = 27;
                p[0x1B5] = cmd;
                p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                *(int *)(p + 0x1D8) = 0;
            }
            offset = p[2] * 2;
            offset += (unsigned int)D_004C2794;
            ++*(short *)(offset + 0x7C);
            func_001E3710(p, 21);
        }
    }
    if (p[0x213] == 3)
        func_00183D90(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_001863F0(p);
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
}
