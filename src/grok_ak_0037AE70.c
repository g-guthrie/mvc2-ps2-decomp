typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_0037B400(u8 *);
extern int func_0037B300(u8 *);
extern s8 func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_001E7F60(u8 *);
extern void func_0037B710(u8 *);
extern u8 *D_004C2794;

void func_0037AE70(u8 *p, u8 *unused, u32 *flag)
{
    u32 sc = 0x3F59999A;
    u32 one = 0x3F800000;
    *(u32 *)(p + 0x50) = sc;
    if (p[1] != (*(u8 **)(p + 0x18))[1]) {
        func_0037B400(p);
        return;
    }
    if (*flag) {
        if (!func_0037B300(p)) {
            p[4] = 4;
            *(s16 *)(p + 0x1E) = 0x14;
            *(u32 *)(p + 0x118) = one;
            p[0x13C] = 1;
            return;
        }
    }
    if (func_00175700(p) < 0) {
        if (*flag == 0) {
            {
                s16 t = 0x30;
                if (p[5])
                    *(u32 *)(p + 0x38) = 0x42CC0000;
                *(s16 *)(p + 0x1E) = t;
            }
            p[0x1B5] = 0x37;
            *(s16 *)(p + 0x1C0) = 0;
            p[0x1B2] = 0;
            *(u32 *)(p + 0x1D8) = 0;
            ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
        }
        p[4] = 3;
        func_001757E0(p, 0x17, 0xF);
        func_001E7F60(p);
        *(u32 *)(p + 0x50) = one;
        *(u32 *)(p + 0x54) = one;
        p[0x13C] = 0;
        func_0037B710(p);
    }
}
