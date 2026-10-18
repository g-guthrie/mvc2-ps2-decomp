typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } GQ;
extern GQ *D_004C2794;

void func_002F7F30(u8 *p) {
    extern void func_002FA200();
    extern s32 func_00175700();
    extern void func_001843A0();
    s8 r;
    u8 m;
    if (p[0x2CE] != 0) {
        func_002FA200(p);
        return;
    }
    switch (p[0x1FC]) {
    case 0:
    case 1:
        r = func_00175700(p);
        if (r < 0) func_001843A0(p);
        break;
    case 2:
        r = func_00175700(p);
        if (r < 0) {
            func_001843A0(p);
        } else {
            if (*(s8 *)(p + 0x151) != 0) {
                p[0x151] = 0;
                p[0x1B5] = 0x1A;
                p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                *(u32 *)(p + 0x1D8) = 0;
                D_004C2794->f7c[p[2]]++;
            }
            if (*(s8 *)(p + 0x150) != 0) {
                p[0x150] = 0;
                p[0x1B5] = 2;
                p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                *(u32 *)(p + 0x1D8) = 0;
                D_004C2794->f7c[p[2]]++;
            }
        }
        break;
    default:
        break;
    }
}
