typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long u64;

typedef struct {
    s16 h0;
    s16 h2;
    s16 h4;
    u16 h6;
    s32 w8;
    s32 wC;
} GsCtx116;

extern GsCtx116 *func_00100468(void);
extern s32 func_00104120(s32);
extern void func_001048C0(s32);
extern void func_00103AE0(s32, s32);
extern void func_001039E0(s32, s32, s32);

void func_001002D8(s16 mode, s16 b, s16 c, s16 d)
{
    GsCtx116 *o;

    switch (mode) {
    case 0:
        o = func_00100468();
        *(volatile u64 *)0x12001000 = 0x200;
        o->h0 = b;
        o->h2 = c;
        o->h6 = (u16)((*(volatile u64 *)0x12001000 >> 16) & 0xFF);
        func_00104120(0xFF00);
        o->h4 = d != 0;
        if (o->w8 != 0) {
            func_001048C0(2);
            func_00103AE0(2, o->wC);
            o->w8 = 0;
            o->wC = 0;
        }
        func_001039E0(b & 1, c & 0xFF, d & 1);
        break;
    case 1:
        *(volatile u64 *)0x12001000 = 0x100;
        break;
    case 5:
        o = func_00100468();
        o->h4 = d != 0;
        o->h0 = b;
        o->h2 = c;
        o->h6 = (u16)((*(volatile u64 *)0x12001000 >> 16) & 0xFF);
        func_001039E0(b & 1, c & 0xFF, d & 1);
        break;
    }
}
