typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[0x34];
    f32 f34, f38;
    u8 pad3c[0x20];
    f32 f5c, f60, pad64, f68, f6c;
} PA;

void func_002285E0(u8 *p)
{
    extern void func_00175700(u8 *);
    extern u8 *func_001E7FD0(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0022C220(u8 *, u8 *);
    extern void func_00185640(u8 *, u8 *);
    f32 *a, *b, *c, *d;
    s16 h;
    f32 k;
    u8 *o;
    u32 t;
    *(s32 *)(p + 0x2DC) = 4;
    a = (f32 *)(p + 0x5C);
    b = (f32 *)(p + 0x60);
    c = (f32 *)(p + 0x68);
    d = (f32 *)(p + 0x6C);
    ((PA *)p)->f34 += ((PA *)p)->f5c;
    ((PA *)p)->f5c += ((PA *)p)->f68;
    ((PA *)p)->f38 += ((PA *)p)->f60;
    ((PA *)p)->f60 += ((PA *)p)->f6c;
    func_00175700(p);
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h == 0) {
        k = 0.5208333f;
        if (p[0x1E6] != 0) k = -k;
        *(f32 *)((s32)p + 0x68) = k;
        t = p[6];
        p[6] = t + 1;
        if (p[0x20D] == 2) {
            p[6] = 4;
            *(s32 *)(p + 0x2DC) = 0;
            *a = 0;
            *b = 0;
            *c = 0;
            *d = 0;
            *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
            func_001757E0(p, 1, 9);
            return;
        }
        func_001757E0(p, 0x15, 0x17);
    } else {
        if ((o = func_001E7FD0(p)) != 0) {
            *(s32 *)(p + 0x2DC) = 0x10;
            if (p[0x425] == 0) {
                *(s32 *)(p + 0x2BC) = o[1];
                func_0022C220(p, o);
            } else {
                *(s32 *)(p + 0xD0) = 0;
            }
            p[0x20B] = 0xC0;
            func_00185640(p, o);
        }
    }
}
