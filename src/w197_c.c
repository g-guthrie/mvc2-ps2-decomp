typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct { s32 f0; void *f4; s32 **f8; void *fC; s32 f10; s32 f14; } E197c;
extern s32 D_004C247C;
extern s32 D_004C2484;
extern s8 D_004C248C;
extern E197c D_0048EB38[];
extern void func_004108F0(void *);
extern void func_00411228(void *);
extern void func_0011D8F8(void *, s32, s32);
extern void func_0010AE38(s32);
void func_0040DE60(void) {
    s32 i;
    register s32 n __asm__("$3");
    i = 0;
    if (D_004C247C > 0) do {
        E197c *e = &D_0048EB38[i];
        if (e->f4 != 0) {
            func_004108F0(e->f4);
        }
        if (e->f8 != 0) {
            ((void (*)(void *))(*e->f8)[3])(e->f8);
        }
        if (e->fC != 0) {
            func_00411228(e->fC);
        }
        func_0011D8F8(e, 0, 0x18);
        i++;
        n = D_004C247C;
    } while (i < n);
    if (D_004C248C == 1) {
        func_0010AE38(D_004C2484);
        D_004C2484 = 0;
        D_004C248C = 0;
    }
}
