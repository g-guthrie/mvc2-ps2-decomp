/* Provisional: scene pointer provenance and storage ownership require proof. */
typedef unsigned char u8; typedef signed char s8; typedef unsigned short u16; typedef unsigned int u32;
extern u8 *D_004C2840 __attribute__((section(".sdata")));
extern int D_004F1CDC;
extern void func_001266A0(u8 *, int, int);
extern void func_003D9440(void);
typedef struct { u8 active, state, step, misc; u32 reserved, w8, wc; u16 x10, timer; u8 padding[0x31]; u8 mode, padding2[2], character; } Scene;
void func_003D80E0(Scene *p) {
    D_004C2840[0x19] = 1;
    D_004C2840[0x9c] = 0;
    p->state = 10; p->step = 0; p->misc = 0; p->w8 = 0; ((u8 *)p)[7] = 0; p->wc = 0; p->timer = 1;
    if (p->mode == 0) {
        func_001266A0(0, 11, 11);
    } else {
        if (p->character == 8 && *(s8 *)(D_004C2840+0xaf) != 0) {
            D_004C2840[0x19] = 0;
            if (p->mode == 1) { p->timer = 420; D_004F1CDC = 1; }
            else { p->timer = 300; D_004F1CDC = 2; }
        }
        func_003D9440();
    }
    p->active = 1;
}
