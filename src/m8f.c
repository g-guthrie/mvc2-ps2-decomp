typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00175670(void *a);
extern void func_001C1330(void *a, void *b);

void func_001C0D90(u8 *a, u8 *b) {
    if (*(s8 *)(b + 0x151) == 0 || b[0x1E4] != 0x15 || b[0x1FD] != 2) {
        u32 t = a[4];
        a[4] = t + 1;
        a[0x13C] = 0;
    } else {
        func_00175670(a);
        func_001C1330(a, b);
        *(s8 *)(a + 0x24) = *(s8 *)(b + 0x24);
    }
}
