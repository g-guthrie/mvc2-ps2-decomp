typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } Gc;
extern Gc *D_004C2794;
extern u8 D_004F1F45[];
extern u8 D_004F1F46[];

void func_00227290(u8 *p)
{
    extern s8 func_00175700(u8 *);
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0022C5D0(u8 *);
    s16 v;
    if (p[6] == 0) {
        func_00175700(p);
        if (p[0x15B] != 0) {
            p[0x1B5] = p[0x15B];
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
            p[0x15B] = 0;
        }
        if (*(s8 *)(p + 0x150) > 0) {
            p[0x150] = 0;
            D_004F1F45[0] = 1;
            D_004F1F46[0] = 1;
            func_001E3710(p, 0x30);
        }
        v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v <= 0) {
            p[6]++;
            func_001757E0(p, 7, 4);
        }
    } else {
        if (func_00175700(p) < 0) func_0022C5D0(p);
    }
}
