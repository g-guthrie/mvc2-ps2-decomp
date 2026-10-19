typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern int func_00175700(u8 *);
extern void func_00183D50(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_002A3A90(u8 *p)
{
    unsigned int offset;
    u8 cmd;

    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (p[0x1E6] == 0) {
        if (*(f32 *)(p + 0x5C) <= 0.0f)
            goto chk2;
        goto dozero;
    }
chk2:
    if (p[0x1E6] != 0) {
        if (*(f32 *)(p + 0x5C) < 0.0f)
            goto dozero;
        goto skipz;
    }
    goto skipz;
dozero:
    *(int *)(p + 0x68) = 0;
    *(int *)(p + 0x5C) = 0;
skipz:
    if (*(s8 *)(p + 0x151)) {
        p[0x151] = 0;
        cmd = p[0x1B7] ? 0x3D : 0x3C;
        p[0x1B5] = cmd;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(int *)(p + 0x1D8) = 0;
        offset = p[2] * 2;
        offset += (unsigned int)D_004C2794;
        ++*(short *)(offset + 0x7C);
    }
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        p[6] += 2;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        func_00183D50(p);
        func_001757E0(p, 21, (unsigned char)(p[0x1B7] ? 15 : 14));
    }
}
