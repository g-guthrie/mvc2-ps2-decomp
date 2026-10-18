typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x160]; s8 b[8]; } S;
extern s32 func_00175700(u8 *);
extern void func_001843A0(u8 *);
void func_002CA610(S *a) {
    if ((s8)func_00175700((u8 *)a) >= 0) {
        s8 *p = a->b; s8 f = p[1]; s8 *q = p + 1;
        if (f) { ((u8 *)a)[0x20D] = 0; *q = 0; }
    } else {
        *(s32 *)((u8 *)a + 0x5C) = 0; *(s32 *)((u8 *)a + 0x60) = 0;
        *(s32 *)((u8 *)a + 0x68) = 0; *(s32 *)((u8 *)a + 0x6C) = 0;
        func_001843A0((u8 *)a);
    }
}
