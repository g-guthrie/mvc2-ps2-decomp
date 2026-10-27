typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern s32 func_003F81D0(void *);
s32 func_00400050(void *object) {
    return func_003F81D0(*(void **)((u8 *)object + 4));
}
