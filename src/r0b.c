typedef unsigned char u8;
typedef signed int s32;

/* EE GCC 2.96, -O2 -G0, SN assembler -G0: ./tryee.sh src/r0b.c sn */

void func_00405320(u8 *base, s32 idx, s32 *o1, s32 *o2) {
    if (o1) *o1 = *(s32 *)(base + idx * 16 + 0x2BC);
    if (o2) *o2 = *(s32 *)(base + idx * 16 + 0x2C0);
}

extern s32 D_00438270;
extern void func_001061D8(void);
void func_001067C8(void) {
    func_001061D8();
    do { D_00438270 = 0; } while (0);
}

extern s32 *func_0011B370(void);
s32 func_001044A0(const char *path, int flags, int mode) {
    s32 *p;
    do { p = func_0011B370(); } while (0);
    *p = 5;
    return -1;
}

extern int func_0010B970(const char *, int, const void *, int *, int);
void func_0010BBB8(const char *a, int b, const void *c, int *d) { do { func_0010B970(a, b, c, d, 0); } while (0); }
