typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef float f32;

typedef struct { s32 n0; s32 n1; u8 *d0; u8 *d1; u8 b0[0x40]; u8 b1[0x40]; } S110;
void func_00110428(void *argument)
{
    S110 *p = (S110 *)((u32)argument | 0x20000000);
    s32 i;
    u8 *d;
    if (p->n0 != 0) {
        d = p->d0;
        for (i = 0; i < p->n0; i++) {
            *d++ = p->b0[i];
        }
    }
    if (p->n1 != 0) {
        d = p->d1;
        for (i = 0; i < p->n1; i++) {
            *d++ = p->b1[i];
        }
    }
}
