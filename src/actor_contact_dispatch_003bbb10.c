#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
extern int func_003BD4C0(u8*);
extern void (*D_004C20A0[])(u8*) __attribute__((section(".sdata")));
static void func_003BB8F0(u8 *p) { p[4]++; p[5] = 0; p[6] = 0; p[316] = 1; }

void func_003BBB10(u8 *p)
{
 if(*(s8*)(p+0x1B3)||func_003BD4C0(p)){func_003BB8F0(p);return;}
 D_004C20A0[p[5]](p);
}
