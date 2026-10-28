typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 func_003F1F90();
extern void func_0010CFD0();
extern void func_00103A20();
extern void func_00102F20();

extern void func_00401868();
extern void func_003F9630();
extern void func_00401640(void *, void *);
extern void func_003F9660();
extern void func_003FB128();
extern char D_004BBFF8[];
void func_00401760(u8 *p, void *b) {
    if (p == 0 || b == 0) {
        func_003FB128(D_004BBFF8);
        return;
    }
    func_00401868();
    func_003F9630();
    func_00401640(p, b);
    p[2] = 3;
    p[0x98] = 1;
    func_003F9660();
}

extern void func_0040D5A0(const char *, ...);
extern char D_004BE2F8[];
extern char D_004BE368[];
s32 func_0040D300(u8 *p, s32 v) {
    s32 i;
    s32 *q;
    if (p == 0) {
        func_0040D5A0(D_004BE2F8);
    } else {
        q = (s32 *)(p + 0x38);
        for (i = 0; i < 16; i++) {
            if (*q == v) break;
            q += 16;
        }
        if (i == 16)
            func_0040D5A0(D_004BE368);
        else
            return *(s32 *)(p + i * 64 + 0x70);
    }
    return -1;
}
