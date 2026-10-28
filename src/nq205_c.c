/* MW 3.0 -O3 -sdatathreshold 0. The trailing alignment nop at 0x179BFC is padding (gap_00179BFC). */
typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef struct { u8 pad0[0x1E4]; u8 f1E4; u8 pad1[0x1F5 - 0x1E5]; u8 f1F5; s8 f1F6; u8 pad2[0x23C - 0x1F7]; u8 f23C; u8 pad3[0x24E - 0x23D]; u8 f24E; } A9;
extern s8 D_00448AB0[];
extern void (*jtbl_00448A20[])(A9 *);

void func_00179B90(A9 *p) {
    if (p->f1F6 != 0) {
        if (--p->f1F6 == 0) {
            p->f1F5 = 0x50;
        }
    }
    p->f23C = 0;
    if (D_00448AB0[p->f1E4] == 0) p->f24E = 0;
    jtbl_00448A20[p->f1E4](p);
}
