typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef float f32;

extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern void func_00356B50(void);

void func_00356A10(u8 *p) {
    s8 i;
    u8 *o;
    for (i = 0; i <= 0x10; i++) {
        if ((o = func_003DA750(0, 1, 1)) != 0) {
            *(void **)(o + 0x10) = (void *)func_00356B50;
            o[0x20] = 1;
            o[0x21] = i;
            *(u32 *)(o + 0x18) = *(u32 *)(p + 0x18);
            *(u8 **)(o + 0x14) = p;
            o[1] = p[1];
            *(s16 *)(o + 0x26) = 0x901;
        }
    }
}

extern s32 func_00175700();
extern void func_001843A0();

void func_0021E0B0(u8 *p) {
    switch (p[0x1FC]) { case 2: case 1: case 0: if ((s8)func_00175700(p) < 0) func_001843A0(p); return; case 0xFF: if ((s8)func_00175700(p) < 0) func_001843A0(p); return; }
}


extern u8 D_00444F40[];
extern u8 D_00444F60[];
extern f32 func_00154710(void *a, void *b, s32 c);
extern void func_003DAA40();

void func_0015A020(u8 *p) {
    if (*(s16 *)(p + 0x1C) >= 13) {
        func_003DAA40(p);
        return;
    }
    *(u32 *)(p + 0x50) = 0x3F800000;
    *(f32 *)(p + 0x58) = *(f32 *)(p + 0x54) = func_00154710(D_00444F40, p + 4, *(s16 *)(p + 0x1C));
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x3C) += *(f32 *)(p + 0x64);
    *(f32 *)(p + 0x7C) = *(f32 *)(p + 0x78) = func_00154710(D_00444F60, p + 6, *(s16 *)(p + 0x1C));
    *(f32 *)(p + 0x80) = *(f32 *)(p + 0x78);
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
}
