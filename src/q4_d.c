typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_001B96C0(void *);
extern s8 func_00175670(void *);
typedef struct { u8 pad0[0x34]; f32 f34; } G1B9;
typedef struct { u8 pad0[0x18]; G1B9* f18; u8 pad1C[0x18]; f32 f34; f32 f38; u8 pad3C[0x24]; f32 f60; u8 pad64[0x8]; f32 f6C; u8 pad70[0xd0]; s16 f140; u8 pad142[0x71]; s8 f1B3; } P1B9;
void func_001B9610(P1B9 *p) {
    if (p->f1B3 != 0) {
        func_001B96C0(p);
        return;
    }
    p->f38 += p->f60;
    p->f60 += p->f6C;
    p->f34 = p->f18->f34;
    p->f34 += (p->f140 != 0) ? 65.0f : -65.0f;
    if (func_00175670(p) < 0) func_001B96C0(p);
}
