typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G197h;
typedef struct { u8 pad[0x160]; s8 b[8]; } S197h;
extern G197h *D_004C2794;

void func_001EF690(u8 *p) {
    extern s8 func_00175700(u8 *);
    extern void func_001843A0(u8 *);
    extern void func_001E3210(u8 *, s32);
    u8 *q = p + 0x2B8;
    s8 *r, *z;
    s8 f;
    switch (p[0x1FC]) {
    case 0:
    case 1:
        if (func_00175700(p) < 0) {
            func_001843A0(p);
        }
        break;
    case 2:
        if (func_00175700(p) < 0) {
            func_001843A0(p);
        }
        if (q[4] == 0 && *(s8 *)(p + 0x1B2) != 0) {
            q[4] = 1;
            func_001E3210(p, 4);
        }
        {
            r = ((S197h *)p)->b;
            f = r[1];
            z = r + 1;
            if (f != 0) {
                *z = 0;
                p[0x1B5] = 0x19;
                p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                *(s32 *)(p + 0x1D8) = 0;
                D_004C2794->f7c[p[2]]++;
            }
        }
        break;
    default:
        break;
    }
}
