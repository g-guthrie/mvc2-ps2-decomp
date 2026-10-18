typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s16 v; s16 x; s16 y; } T6;
typedef struct {
    u8 pad[0x10];
    s16 z;
    s16 pad2;
    s16 a[4];
    T6 b[4];
} S0;
extern u8 D_004D179A;

void func_0012BDC0(S0 *p, s32 i) {
    p->z = 0;
    if (D_004D179A >= 7) {
        p->a[i] = -1;
    } else {
        p->a[i] = D_004D179A + 1;
        p->b[i].v = D_004D179A * 500 + 1000;
    }
}

extern u8 *D_004D36CC;
extern void func_00123090(void);
extern void func_00151A20(s32 a);
extern void func_001520E0(s32 a);
extern void func_00148B20(void *p);
extern void func_0012ACD0(void);

void func_00152840(void) {
    u8 *p;
    func_00123090();
    func_00151A20(0xD);
    func_001520E0(0xD);
    for (p = D_004D36CC; p != 0; p = *(u8 **)(p + 0xC)) {
        if (*(s8 *)(p + 0x13C) != 0) {
            func_00148B20(p);
        }
    }
    func_0012ACD0();
}
