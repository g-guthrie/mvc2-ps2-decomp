typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x160]; s8 b[8]; } SA;

void func_002CBA10(SA *a)
{
    extern s32 func_00175700(SA *);
    extern void func_001843A0(SA *);
    s8 *p = a->b;
    s8 f = p[1];
    s8 *q = p + 1;
    if (f != 0) {
        s16 v;
        *q = 0;
        v = ((u8 *)a)[0x1E6] ^ 1;
        *(s16 *)((u8 *)a + 0x140) = v;
        ((u8 *)a)[0x1E6] = v;
    }
    if ((s8)func_00175700(a) >= 0) {
        if (*(s8 *)((u8 *)a + 0x151) != 0) {
            u8 *r;
            *(u8 *)((s32)a + 0x151) = 0;
            r = *(u8 **)((u8 *)a + 0x1DC);
            *(u32 *)(r + 0x1C8) = (u32)a;
            r[0x20A] = 1;
            r[0x1B5] = 0x20;
        }
    } else {
        func_001843A0(a);
    }
}
