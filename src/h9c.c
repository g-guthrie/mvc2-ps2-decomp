typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
#pragma padloop on
extern void func_003DAA40(void *);
extern void func_003AF760(void *, void *);
void func_003AF6D0(u8 *p, u8 *q) {
    u8 *c; u8 *next; s32 i; s32 n;
    n = *(s8 *)(q + 0x28) + 3;
    c = *(u8 **)(q + 0x24);
    for (i = 0; i < n; i++) {
        next = *(u8 **)(c + 8);
        func_003DAA40(c);
        c = next;
    }
    func_003AF760(p, q);
}
