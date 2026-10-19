typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700(void *);
extern void func_0037B930(void *);
extern void func_001757E0(void *, s32, s32);

typedef struct P {
    u8 pad0[6]; u8 b6; u8 pad7[0x34-7]; f32 f34; f32 f38;
    u8 pad3c[0x5C-0x3C]; f32 f5c; f32 f60; u8 pad64[4]; f32 f68; f32 f6c;
    u8 pad70[0x151-0x70]; s8 b151;
} P;

void func_002765D0(P *p)
{
    f32 *v5c = &p->f5c;
    f32 *v68 = &p->f68;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_00175700((u8 *)p);
    if (p->b151 == 3) {
        p->b151 = 0;
        func_0037B930((u8 *)p);
    }
    if (p->f60 - 8.0f < 0.0f) {
        p->b6++;
        func_001757E0((u8 *)p, 0x15, 0xD);
        *v5c = 0;
        *v68 = 0;
    }
}
