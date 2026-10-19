typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794;
extern void func_00183D90(u8 *);
extern void func_001863F0(u8 *);
extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_00182380(u8 *);
extern void func_001821D0(u8 *);
extern void func_001820A0(u8 *);
extern void func_00182300(u8 *);
extern void func_00184540(u8 *);
extern int func_001864A0(u8 *);
extern void func_001865B0(u8 *);

void func_002AC9E0(u8 *p)
{
    switch (p[0x213]) {
    case 3:
        func_00183D90(p);
        /* fallthrough */
    case 0:
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        func_001863F0(p);
        if ((s8)func_00175700(p) < 0) {
            func_001843A0(p);
            return;
        }
        if (p[0x15B]) {
            p[0x1B5] = p[0x15B];
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            ((s16 *)(D_004C2794 + 124))[p[2]]++;
            p[0x15B] = 0;
        }
        break;
    case 2:
        func_00182380(p);
        func_001821D0(p);
        /* fallthrough */
    case 1:
        func_001820A0(p);
        func_00182300(p);
        if ((s8)func_00175700(p) < 0)
            func_00184540(p);
        if (func_001864A0(p))
            func_001865B0(p);
        break;
    }
}
