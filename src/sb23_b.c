typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G;
extern G *D_004C2794;

void func_00216EB0(u8 *p) {
    extern s32 func_00175700();
    extern void func_001843A0();
    extern s32 func_001853E0();
    extern void func_001855D0();
    extern void func_001E3210();
    extern void func_0019B110();
    extern void func_001757E0();
    switch (p[0x1FC]) {
    case 0:
        if ((s8)func_00175700(p) < 0) func_001843A0(p);
        break;
    case 1:
        if ((s8)func_00175700(p) < 0) {
            func_001843A0(p);
            break;
        }
        if (*(s8 *)(p + 0x151) != 0) {
            if (func_001853E0(p) == 0) {
                if (((*(u16 *)(p + 0x362) | *(u16 *)(p + 0x366)) & 0x200) != 0) {
                    *(u16 *)(p + 0x366) = 0;
                    p[0x1B5] = 0x1C;
                    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                    *(u32 *)(p + 0x1D8) = 0;
                    D_004C2794->f7c[p[2]]++;
                    func_001E3210(p, 0x1F);
                    func_001855D0(p);
                    func_001757E0(p, 7, 4);
                }
            }
        }
        break;
    case 2:
        if ((s8)func_00175700(p) < 0) {
            func_001843A0(p);
            break;
        }
        if (*(s8 *)(p + 0x151) != 0) {
            *(s8 *)(p + 0x151) = 0;
            func_0019B110(p, 1);
        }
        break;
    }
}
