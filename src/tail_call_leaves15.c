typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern void func_00175700();
extern void func_00179160();
extern void func_00324130(u8 *);
extern void func_001757E0();
extern void func_001843A0();
extern void func_00176160();

void func_003123F0(u8 *p) { (*(s16 *)(p + 28))--; func_00175700(p); }

void func_00321990(void *p, u8 *q) { *(s16 *)(q + 28) ^= 1; func_00179160(p, q); }

void func_00324110(u8 *p) {
    p[6]++;
    p[32] = 0;
    *(s16 *)(p + 870) = 0;
    func_00324130(p);
}

void func_00324A30(u8 *p) {
    p[32] = 0;
    p[486] = *(s8 *)(p + 320);
    *(s32 *)(p + 92) = 0;
    func_001757E0(p, 22, 12);
}

void func_003266E0(u8 *p) {
    *(s32 *)(p + 208) = 0;
    p[534] = 0;
    *(s32 *)(p + 92) = 0;
    *(s32 *)(p + 96) = 0;
    *(s32 *)(p + 104) = 0;
    *(s32 *)(p + 108) = 0;
    func_001843A0(p);
}

void func_003182F0(u8 *p) {
    (*(s16 *)(p + 28))++;
    *(s16 *)(p + 28) &= 3;
    func_00176160(p, 1, *(s16 *)(p + 28), 1);
}
