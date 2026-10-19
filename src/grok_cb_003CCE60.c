typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern s32 func_00174470(u8 *);
extern void func_003CAB00(u8 *, u8 *);
extern s32 func_00175700(u8 *);
extern void func_003CAB20(u8 *, u8 *, s32);

void func_003CCE60(u8 *p, u8 *q)
{
    s16 v;
    u8 *r;
    s32 mode;
    if (q[5] != 0) {
        func_003CAB20(p, q, 0xF);
        return;
    }
    if (func_00174470(p) == 0) {
        func_003CAB00(p, q);
        return;
    }
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v < 0) {
        func_003CAB20(p, q, 0xF);
        return;
    }
    r = *(u8 **)(p + 0xD8);
    if (r == 0 || r[5] == 9 || r[5] == 0xD) {
        func_003CAB20(p, q, 0xF);
        return;
    }
    if (*(s8 *)(r + 0x1B2) == 0)
        return;
    mode = 0xF;
    if ((*(s8 *)(r + 0x1B2) & 0x11) == 0)
        mode = 0xE;
    func_003CAB20(p, q, mode);
}
