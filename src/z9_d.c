typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 p0; u8 b1; u8 pad2[0x10 - 2]; void (*fn10)(); u8 pad14[4]; u8 *p18; u8 pad1c[0x20 - 0x1C];
    u8 b20; u8 b21; u8 pad22[4]; s16 s26; u8 pad28[0x34 - 0x28]; f32 f34; f32 f38;
} O1;
typedef struct {
    u8 p0; u8 b1; u8 pad2[0x34 - 2]; f32 f34; u8 pad38[0x140 - 0x38]; s16 s140;
    u8 pad142[0x430 - 0x142]; f32 f430;
} P1;

extern void func_003A2540();

void func_003A2470(P1 *p) {
    extern O1 *func_003DA750();
    O1 *o;
    if ((o = func_003DA750(0, 1, 0)) != 0) {
        o->fn10 = func_003A2540;
        o->b20 = 3;
        o->b21 = 0;
        o->p18 = (u8 *)p;
        o->b1 = p->b1;
        o->s26 = 0x2C02;
        if (p->s140 != 0) o->f34 = p->f34 + 153.3333282470703f;
        else o->f34 = p->f34 - 153.3333282470703f;
        o->f38 = p->f430 - 8.571428298950195f;
    }
}
