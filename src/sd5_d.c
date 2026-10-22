typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { s32 w0; s32 w1; s32 w2; s32 w3; } T004895C0;
extern T004895C0 D_004895C0;
extern s32 D_004895D0;
extern s32 D_004895D4;
extern u8 D_004BE130[];
extern u8 D_004BE158[];
extern u8 D_004BE178[];
extern u8 D_004BE190[];

s32 func_0040C3B0(u8 *buf, s32 n) {
    extern void func_0011D8F8(u8 *, s32, s32);
    extern void func_0040BF58(u8 *, u8 *);
    extern s32 func_00107E90(u8 *, s32);
    extern long func_0040B618(s32);
    extern void func_00108118(s32);
    extern void func_0040B110(s32);
    extern void func_0011EB60(u8 *, s32);
    u8 name[0x100];
    s32 i;
    s32 bad = 0;
    s32 ok = 0;
    s32 *dst;
    u8 *rec;
    s32 h;
    func_0011D8F8(name, 0, 0x100);
    i = 0;
    if (n > 13) n = 13;
    if (n > 0) {
        dst = (s32 *)buf;
        do {
            rec = buf + (D_004895C0.w2 * 8 + i * (D_004895C0.w3 + 1));
            i++;
            func_0040BF58(rec, name);
            if (*(s8 *)rec != 0) {
                h = func_00107E90(name, 1);
                if (h < 0) {
                    if (D_004895D4 == 0) func_0011EB60(D_004BE130, (s32)name);
                    bad++;
                } else {
                    dst[0] = h;
                    ok++;
                    dst[1] = func_0040B618(h);
                    if (D_004895D4 == 0) func_0011EB60(D_004BE158, (s32)rec);
                    func_00108118(h);
                    func_0040B110(func_00107E90(name, D_004895D0));
                }
            }
            dst += 2;
        } while (i < n);
    }
    if (D_004895D4 == 0) func_0011EB60(D_004BE178, ok);
    if (bad > 0) {
        if (D_004895D4 != 2) func_0011EB60(D_004BE190, 10);
    }
    return ok;
}
