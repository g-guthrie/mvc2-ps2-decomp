typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 *func_003DA750(void *p, s32 b, s32 c);
extern void func_0032E740();
extern void func_0032EB80(void *p, s32 i);

#pragma padloop on
void func_0032E6C0(void) {
    u8 *o;
    s32 i;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_0032E740;
        *(s32 *)(o + 0xD0) = 0x80F;
        *(s16 *)(o + 0x1E) = 1;
        i = 0;
        do {
            func_0032EB80(o, i);
            i++;
        } while (i < 2);
    }
}
