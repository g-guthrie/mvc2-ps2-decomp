typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x1C]; s32 *p1C; } W152;

extern void func_00152400();
extern void func_003DF850(s32, s32);
extern void func_001538B0(u8 *, s32, f32 *);

void func_00152180(u8 *o, u8 id)
{
    W152 *w;
    f32 m[16];

    func_00152400();
    if (*(u32 *)(o + 0xD0) & 0x2000) return;
    w = *(W152 **)(o + 0x84);
    if (*(u32 *)(o + 0xD0) & 0x200000) func_003DF850(0x6C, 7);
    if (*(u32 *)(o + 0xD0) & 0x800000) func_003DF850(0x6B, 0);
    if (*(u32 *)(o + 0xD0) & 0x400000) func_003DF850(0x63, 0x20000);
    if (id == 0xD || id == 0xE || id == 0x12 || id == 0x10) {
        if (w->p1C != 0) {
            m[0] = *(f32 *)(o + 0x88);
            m[1] = *(f32 *)(o + 0x8C);
            m[2] = *(f32 *)(o + 0x90);
            m[3] = *(f32 *)(o + 0x94);
            m[4] = *(f32 *)(o + 0x98);
            m[5] = *(f32 *)(o + 0x9C);
            m[6] = *(f32 *)(o + 0xA0);
            m[7] = *(f32 *)(o + 0xA4);
            m[8] = *(f32 *)(o + 0xA8);
            m[9] = *(f32 *)(o + 0xAC);
            m[10] = *(f32 *)(o + 0xB0);
            m[11] = *(f32 *)(o + 0xB4);
            m[12] = *(f32 *)(o + 0xB8);
            m[13] = *(f32 *)(o + 0xBC);
            m[14] = *(f32 *)(o + 0xC0);
            m[15] = *(f32 *)(o + 0xC4);
            func_001538B0(o, w->p1C[*(s16 *)(o + 0xCC)], m);
        }
    } else {
        if (w->p1C != 0) {
            m[0] = *(f32 *)(o + 0x88);
            m[1] = *(f32 *)(o + 0x8C);
            m[2] = *(f32 *)(o + 0x90);
            m[3] = *(f32 *)(o + 0x94);
            m[4] = *(f32 *)(o + 0x98);
            m[5] = *(f32 *)(o + 0x9C);
            m[6] = *(f32 *)(o + 0xA0);
            m[7] = *(f32 *)(o + 0xA4);
            m[8] = *(f32 *)(o + 0xA8);
            m[9] = *(f32 *)(o + 0xAC);
            m[10] = *(f32 *)(o + 0xB0);
            m[11] = *(f32 *)(o + 0xB4);
            m[12] = *(f32 *)(o + 0xB8);
            m[13] = *(f32 *)(o + 0xBC);
            m[14] = *(f32 *)(o + 0xC0);
            m[15] = *(f32 *)(o + 0xC4);
            func_001538B0(o, w->p1C[*(s16 *)(o + 0xCC)], m);
        }
    }
    if (*(u32 *)(o + 0xD0) & 0x200000) func_003DF850(0x6C, 1);
    if (*(u32 *)(o + 0xD0) & 0x800000) func_003DF850(0x6B, 1);
    if (*(u32 *)(o + 0xD0) & 0x400000) func_003DF850(0x63, 0);
}
