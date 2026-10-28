typedef unsigned char u8; typedef signed int s32;
typedef void (*Fn36)(u8 *, u8 *, u8 *);
extern Fn36 D_00463DB0[];
void func_0036ED90(u8 *p) {
    extern void func_00372260(u8 *);
    u8 *o = *(u8 **)(p + 0x18);
    D_00463DB0[p[5]](p, o, p + 0x88);
    if (p[1] != (*(u8 **)(p + 0x18))[1]) {
        func_00372260(p);
        return;
    }
    if (o[0x1E4] != 0x15 || o[0x1FD] != 6) {
        p[4]++;
        p[0x13C] = 0;
        return;
    }
}
