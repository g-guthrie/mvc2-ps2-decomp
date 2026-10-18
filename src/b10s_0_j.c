typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef long long s64;
typedef struct { u8 pad[0x1C]; s16 cnt; } O;
static s64 *func_00420A00(O *o, s64 a) { return (s64 *)(o->pad + (s32)a); }
static s32 func_00420A20(O *o, s32 a) { s32 x = o->pad[a]; s32 y = o->pad[a+1]; return x + y; }
s32 func_00420AB0(O *o, s64 a, s64 b) {
    s64 *p = func_00420A00(o, a);
    if (func_00420A20(o, 2) == 0) return 0;
    p[0] = b;
    p[1] = a;
    o->cnt++;
    return 1;
}
