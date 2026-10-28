typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;

void func_003CCE60(u8 *p, u8 *q) {
    extern s32 func_00174470();
    extern void func_00175700();
    extern void func_003CAB00(u8 *, u8 *);
    extern void func_003CAB20(u8 *, u8 *, s32);
    s32 a2;
    u8 *d;
    s16 v;
    s32 c;
    if (q[5] == 0) {
        if (func_00174470() == 0) {
            func_003CAB00(p, q);
            return;
        }
        func_00175700(p);
        v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v >= 0) {
            d = *(u8 **)(p + 0xD8);
            if (d == 0 || d[5] == 9 || d[5] == 0xD) goto def;
            c = *(s8 *)(d + 0x1B2);
            if (c == 0) return;
            a2 = 0xE;
            if ((s8)c & 0x11) a2 = 0xF;
            goto call;
        }
    }
def:
    a2 = 0xF;
call:
    func_003CAB20(p, q, a2);
}
