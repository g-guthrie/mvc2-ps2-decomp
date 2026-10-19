typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_002A33E0(u8 *);
extern int func_00175700(u8 *);
extern void func_00183D50(u8 *);
extern void func_001757E0(u8 *, int, int);

void func_002A3190(u8 *p)
{
    unsigned int offset;
    u8 cmd;

    func_002A33E0(p);
    func_00175700(p);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        p[7] += 2;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        func_00183D50(p);
        func_001757E0(p, 21, (unsigned char)(p[0x1B7] ? 7 : 6));
        return;
    }
    if ((s8)p[0x1B2] != 0) {
        p[7]++;
        if (p[6]) {
            cmd = p[0x1B7] ? 0x5B : 0x59;
            p[0x1B5] = cmd;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(int *)(p + 0x1D8) = 0;
            offset = p[2] * 2;
            offset += (unsigned int)D_004C2794;
            ++*(short *)(offset + 0x7C);
        } else {
            cmd = p[0x1B7] ? 0x37 : 0x35;
            p[0x1B5] = cmd;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(int *)(p + 0x1D8) = 0;
            offset = p[2] * 2;
            offset += (unsigned int)D_004C2794;
            ++*(short *)(offset + 0x7C);
        }
        func_001757E0(p, 21, (unsigned char)(p[0x1B7] ? 5 : 4));
    }
}
