typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u16 * volatile D_004C29AC;
typedef struct { u8 pad[0x18]; u8 * volatile p18; } O84;
void func_00384ED0(O84 *o) {
    void func_003859F0(); void func_00175700();
    u16 *g = D_004C29AC;
    u8 *a = o->p18;
    s32 s;
    if (*g != *(u16*)(a + 0x168)) {
        func_003859F0(o);
        return;
    }
    s = (s8)(*(s8*)(a + 0x161) & -2);
    if (s < 0) {
        func_003859F0(o);
        return;
    }
    if (s == 0) {
        ((u8*)o)[0x13C] = 0;
        return;
    }
    ((u8*)o)[0x13C] = 1;
    *(f32*)((u8*)o + 0x34) = *(f32*)(o->p18 + 0x34);
    *(f32*)((u8*)o + 0x38) = *(f32*)(o->p18 + 0x38);
    while (*(s8*)((u8*)o + 0x161) != (s8)s) func_00175700(o);
}
