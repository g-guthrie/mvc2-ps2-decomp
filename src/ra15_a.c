typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x194]; s32 f194; u8 pad2[0x5B8 - 0x198]; } S16FF20;

extern s32 D_004C28AC;
extern s32 D_004C28B8;
extern s32 D_004C282C;
extern s8 D_004BF4A0[8];
extern u8 D_004F20B0[];

void func_0016FF20(void) {
    extern void func_0016F4D0(s32, s32);
    extern s32 func_00416180(s32, s32);
    extern void func_0016F4B0(int, void *, void *);
    extern void func_0016F530(s32, s32, s32, s32, s32, s32);
    s32 i, off, x, y, z;
    func_0016F4D0(D_004C28AC, D_004C28B8);
    i = 0;
    off = 0;
    do {
        func_0016F4B0(D_004BF4A0[i] + 2, (void *)func_00416180(*(s32 *)(D_004F20B0 + off + 0x194), 1), (void *)D_004C28B8);
        i++;
        off += 0x5B8;
    } while (i < 6);
    x = *(volatile s32 *)&D_004C28AC;
    y = *(volatile s32 *)&D_004C28B8;
    z = *(volatile s32 *)&D_004C282C;
    func_0016F530(0x810, z, x, y, 6, 0);
}
