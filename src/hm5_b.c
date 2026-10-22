typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad0[0x48]; s32 f48; u8 pad1[4]; f32 f50; f32 f54; u8 pad2[0x84]; s32 fdc; } HM5A_S1;
extern void func_0037B400();

void func_0037B850(HM5A_S1 *p, u8 *a1) {
    f32 c;
    s32 r;
    if (a1[1] != ((u8 *)*(u8 **)(a1 + 0x18))[1]) {
        func_0037B400(p, 0, 0);
        return;
    }
    if (a1[4] == 4) {
        func_0037B400(p, 0, 0);
        return;
    }
    r = p->fdc & 1;
    if (p->fdc < 0 && r) r -= 2;
    p->fdc = r;
    if (p->fdc != 0) c = 0.9f; else c = 1.0f;
    p->f50 = c;
    if (p->fdc != 0) c = 0.9f; else c = 1.0f;
    p->f54 = c;
    p->fdc = p->fdc + 1;
    p->f48 = p->f48 + 0x1F4A;
}
