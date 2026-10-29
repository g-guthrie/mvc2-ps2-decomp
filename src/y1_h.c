typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
/* Load an IOP module, retrying with a short busy-wait (n == 0: until it
   succeeds) or up to n times, then report failure. */
void func_003DCAD0(const char *a, int b, const void *c, s32 n)
{
    extern int func_0010BB98(const char *, int, const void *);
    extern void func_0011EB60(const char *, ...);
    extern const char D_004BA4F0[];
    s32 i;
    if (n == 0) {
        goto test;
    body:
        __asm__("nop;nop;nop;nop;nop;nop");
    test:
        __asm__("nop;nop");
        if (func_0010BB98(a, b, c) < 0) goto body;
        return;
    }
    for (i = 0; i < n; i++) {
        if (func_0010BB98(a, b, c) > 0) return;
    }
    func_0011EB60(D_004BA4F0, a);
}
