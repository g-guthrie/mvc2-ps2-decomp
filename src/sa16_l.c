typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { s32 w0; s32 w1; s32 w2; s32 w3; } T00489000;
extern T00489000 D_00489000;
extern u8 D_00489128[];
extern s32 D_00489018;
extern u8 D_004BDC48[];
extern u8 D_004BDC60[];
extern u8 D_004BDC78[];
extern u8 D_004BDC90[];

s32 func_0040A838(u8 *buf, s32 n) {
    extern void func_0040A440(u8 *, u8 *);
    extern void func_0010F148(s32);
    extern s32 func_004098D8(void *, u8 *);
    extern void func_0011EB60(u8 *, s32);
    s32 i;
    s32 ok = 0;
    s32 bad = 0;
    u32 *dst;
    u32 tmp[12];
    u8 *rec;
    i = 0;
    if (n > 0) {
        dst = (u32 *)buf;
        do {
            rec = buf + (D_00489000.w2 * 8 + i * (D_00489000.w3 + 1));
            i++;
            if (*(s8 *)rec != 0) {
                func_0040A440(rec, D_00489128);
                func_0010F148(0);
                if (func_004098D8(tmp, D_00489128) == 1) {
                    dst[0] = tmp[0];
                    dst[1] = tmp[1];
                    ok++;
                    if (D_00489018 == 0) func_0011EB60(D_004BDC48, (s32)rec);
                } else {
                    if (D_00489018 == 0) func_0011EB60(D_004BDC60, (s32)rec);
                    bad++;
                }
            }
            dst += 2;
        } while (i < n);
    }
    if (D_00489018 == 0) func_0011EB60(D_004BDC78, ok);
    if (bad > 0) {
        if (D_00489018 != 2) func_0011EB60(D_004BDC90, 10);
    }
    return ok;
}
