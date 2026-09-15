typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

extern u8 D_004C2668;
extern s32 D_004C28B8;
extern s32 D_00446BD8[4];
extern s32 D_004C2844;
extern u8 D_004C27D0;
extern s32 D_004C2618;

extern void func_00418080(void);
extern void func_00170170(u8 *, s32);

void func_0016C480(u8 *p) {
    if (D_004C2668 != 0) {
        p[4]++;
        *(s16 *)(p + 28) = 32;
    }
}

void func_00174B50(void) { D_00446BD8[0] = D_004C28B8; }

void func_001741C0(s32 v) {
    D_004C2844 = v;
    func_00418080();
}

void func_00170160(u8 *p) { func_00170170(p, D_004C27D0 & 31); }

void func_0012F040(s32 v) {
    if (v == 0) v = 0x400;
    D_004C2618 = v;
}
