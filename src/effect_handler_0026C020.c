typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct G { u8 pad[0x7C]; s16 t[2]; } G;
extern G *D_004C2794;

void func_0026C020(u8 *p) {
    extern s32 func_00175700();
    extern void func_001843A0();
    switch (p[0x1FC]) {
    case 2:
        if ((s8)func_00175700(p) < 0) {
            func_001843A0(p);
        } else if (p[0x15B] != 0) {
            p[0x1B5] = 2;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->t[p[2]] += 1;
            p[0x15B] = 0;
        }
        break;
    case 0:
    case 1:
        if ((s8)func_00175700(p) < 0) func_001843A0(p);
        break;
    }
}
