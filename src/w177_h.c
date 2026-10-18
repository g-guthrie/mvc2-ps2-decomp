typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x7C]; s16 h7c[1]; } GH3;
extern GH3 *D_004C2794;
void func_002215E0(u8 *p) {
    extern void func_00221440(u8 *);
    extern void func_00175700(u8 *);
    f32 c;
    u16 m;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x209] = 1;
    func_00221440(p);
    if (*(s8 *)(p + 0x1B2) != 0) {
        m = (*(u16 *)(p + 0x362) | *(u16 *)(p + 0x366)) & 0x360;
        if (m != 0) {
            *(u16 *)(p + 0x364) = 0;
            *(u16 *)(p + 0x366) = 0;
            p[0x152] = 1;
        }
    }
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        c = 4.285714149475098f;
        if (!(c < *(f32 *)(p + 0x60))) {
            p[0x1B5] = 0x4F;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->h7c[p[2]]++;
            p[6]++;
        } else {
            p[0x1B5] = 0x4E;
        }
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->h7c[p[2]]++;
    }
}
