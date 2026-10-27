typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

s32 func_003FFFC0(void *object) {
    extern s32 func_003F81A0(void *);
    return func_003F81A0(*(void **)((u8 *)object + 4));
}
