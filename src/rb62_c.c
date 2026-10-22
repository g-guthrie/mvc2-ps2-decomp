typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

/* MW 3.0.3: ./try.sh src/rb62_c.c "-O3 -sdatathreshold 8" */
typedef struct { u8 pad[0x10]; void *fn; } RC;

extern s32 D_004C2B70;
extern s32 D_004C2B74;
extern RC *D_006338B4[];
extern u8 D_00633720[];
extern void D_0041D560();
extern void D_0041D640();

void func_0041D390(u8 *p)
{
    extern s32 func_0012ABC0(s32, s32);
    extern s32 func_003299E0();
    extern s32 func_0041D070(s32 *, s32 *, s32, s32, s32, s32);
    extern s32 func_0041CE80();
    extern void func_0041D1D0(s16);
    extern void func_0041D270(s16);
    s32 r;
    u32 pad;
    r = 0;
    pad = (u16)func_0012ABC0(3, 0);
    if (p[4] == 0) {
        p[4] = 1;
    } else {
        p[6] = p[5];
        if (func_003299E0() == 0) {
            pad = (u16)pad;
            if (pad & 0x2000) {
                func_0041D070(&D_004C2B70, &D_004C2B74, 0, -1, -1, 0);
            }
            if (pad & 0x1000) {
                func_0041D070(&D_004C2B70, &D_004C2B74, 0, 1, 1, 0);
            }
            if (pad & 0x800) {
                r |= func_0041D070(&D_004C2B70, &D_004C2B74, -1, 0, 0, -1);
            }
            if (pad & 0x400) {
                r |= func_0041D070(&D_004C2B70, &D_004C2B74, 1, 0, 0, 1);
            }
        }
        if (r != 0) {
            *(void **)(p + 0x10) = (void *)D_0041D560;
            D_006338B4[0]->fn = (void *)D_0041D640;
            func_0041D270(func_0041CE80(p[6]));
            p[5] = 0xFF;
            p[6] = 0xFF;
            return;
        }
        p[5] = *(s8 *)((u8 *)D_00633720 + D_004C2B70 * 16 + D_004C2B74 * 2);
    }
    if (p[5] != p[6]) {
        func_0041D1D0(func_0041CE80(p[5]));
        func_0041D270(func_0041CE80(p[6]));
        ((u8 *)D_006338B4[0])[6] = p[5];
    }
}
