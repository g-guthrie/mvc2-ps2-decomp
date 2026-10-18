typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0xE]; s16 h0E; } G14;
extern G14 *D_004C2840;
typedef struct { u8 p0[4]; u8 b4; u8 p5[0x19]; s16 h1E; u8 p20[0x20]; s32 w40; u8 p44[0xC]; f32 f50, f54, f58; u8 p5c[0x10]; f32 f6C, f70; u8 p74[4]; f32 f78, f7C, f80; } O14;
void func_00145CD0(O14 *p) {
    if (p->h1E > 0) {
        p->h1E--;
    } else {
        p->b4++;
        p->f6C = (f32)(0.5 / (double)(D_004C2840->h0E / 3));
        p->f70 = (f32)(0.5 / (double)(D_004C2840->h0E / 3));
        p->h1E = D_004C2840->h0E / 3;
        return;
    }
    p->f50 += p->f6C;
    p->f54 += p->f6C;
    p->f58 += p->f6C;
    p->f78 -= p->f70;
    p->f7C -= p->f70;
    p->f80 -= p->f70;
    p->w40 += 0xE39;
}
