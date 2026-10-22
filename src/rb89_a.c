typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { s8 f0; u8 pad[3]; s32 f4; s32 **f8; s32 fC; s32 f10; s32 f14; } E89;

extern s32 D_004C247C;
extern s32 D_004C2480;
extern s32 D_004C2484;
extern s32 D_004C2488;
extern s8 D_004C248C;
extern E89 D_0048EB38[];
extern u8 D_0048ECB8[];
extern char D_004BE518[];
extern char D_004BE560[];
extern char D_004BE590[];
extern char D_004BE5C0[];
extern char D_004BE5F8[];
extern char D_004BE628[];
extern char D_004BE660[];

void func_0040DBB0(void)
{
    extern s32 func_0010ACD0(s32);
    extern void func_0011EB60(char *, ...);
    extern void func_0011D8F8(void *, s32, s32);
    extern s32 func_00410898(s32, s32, s32);
    extern s32 func_0040FDC0(s32, void *, s32);
    extern s32 func_00411130(s32, s32, s32);
    s32 i;
    s32 s1;
    s32 t;
    s32 **vt;
    E89 *e;
    void (*fp)(s32 **, s32, void *);

    if (D_004C2484 == 0) {
        D_004C2484 = func_0010ACD0(D_004C2480 + 0x40);
        if (D_004C2484 == 0) {
            func_0011EB60(D_004BE518, D_004C2480 + 0x40);
            for (;;) __asm__ volatile("nop");
        }
        func_0011EB60(D_004BE560, D_004C2480 + 0x40, D_004C2484);
        { register s32 q __asm__("$3"); q = D_004C2484; q += 0x40; D_004C248C = 1; q &= -0x40; D_004C2488 = q; }
    }
    func_0011D8F8(D_0048EB38, 0, 0x180);
    s1 = D_004C2488;
    for (i = 0; i < D_004C247C; i++) {
        e = &D_0048EB38[i];
        e->f0 = 0;
        if (s1 & 0x3F) {
            func_0011EB60(D_004BE590);
            for (;;) __asm__ volatile("nop");
        }
        e->f4 = func_00410898(1, s1, 0x100);
        s1 += 0x100;
        if (e->f4 == 0) {
            func_0011EB60(D_004BE5C0);
            for (;;) __asm__ volatile("nop");
        }
        if (s1 & 0x3F) {
            func_0011EB60(D_004BE5F8);
            for (;;) __asm__ volatile("nop");
        }
        e->f8 = (s32 **)func_0040FDC0(1, &D_0048ECB8[i << 8], 0x100);
        if (e->f8 == 0) {
            func_0011EB60(D_004BE628);
            for (;;) __asm__ volatile("nop");
        }
        e->f14 = 0x4000;
        vt = (s32 **)*e->f8;
        e->f10 = s1;
        fp = (void (*)(s32 **, s32, void *))vt[8];
        s1 += 0x4000;
        fp(e->f8, 0, &e->f10);
        e->fC = func_00411130((s32)e->f8, e->f4, 1);
        if (e->fC == 0) {
            func_0011EB60(D_004BE660);
            for (;;) __asm__ volatile("nop");
        }
    }
}
