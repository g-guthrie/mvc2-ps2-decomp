typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
extern int func_001757E0(u8 *, s32, s32);
extern int func_00175700(u8 *);
/* The matched helper consumes only A0; native callsite forwards p there. */
extern void func_003BD7F0(void *);
/* The native callsite passes A0; the matched leaf ignores it and returns zero. */
extern s32 func_003BD7A0(u8 *unused);
extern void func_003BD810(u8 *);

void func_003BA9E0(u8 *p) {
    u32 t = p[6];
    u8 *q = p + 0xD0;
    if (t == 0) {
        p[6] = t + 1;
        if (*(s8 *)(q + 7) >= 0) {
            func_003BD7F0(p);
        }
        func_001757E0(p, 0x19, 3);
        func_003BD7A0(p);
    } else {
        if ((s8)func_00175700(p) < 0) {
            func_003BD810(p);
        } else {
            func_003BD7A0(p);
        }
    }
}
