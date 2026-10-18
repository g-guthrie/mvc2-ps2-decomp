typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef float f32;

extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern s32 D_004C2838[2];
extern void func_001610C0(void);
extern void func_00161240(void);
extern void func_00170DF0(s32 a);
extern void func_00152550(void *o, void *f);

void func_00161010(u8 *p) {
    u8 *o;
    u8 *q;
    if ((o = func_003DA750(0, 7, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_001610C0;
        *(s16 *)(o + 0xCC) = 0xA5;
        *(s32 *)(o + 0x84) = D_004C2838[0];
        *(u32 *)(o + 0xD0) = 0x220821;
        *(u8 **)(o + 0xC8) = p + 0x88;
        *(u8 **)(o + 0x18) = p;
        func_00170DF0(*(s32 *)(o + 0x84));
        q = *(u8 **)(o + 0x18);
        { u32 t = q[5]; q[5] = t + 1; }
        func_00152550(o, (void *)func_00161240);
    }
}

