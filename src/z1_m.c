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
    u8 pad3c[0x5C - 0x3C];
    f32 f5c, f60, f64, f68, f6c;
    u8 pad70[0x215 - 0x70];
    u8 b215;
} S17A;

void func_0017A790(S17A *p) {
    extern s32 func_00184B30(S17A *);
    extern s32 func_00184720(S17A *);
    extern s32 func_00185A90(S17A *);
    extern s32 func_001884C0(S17A *);
    extern s32 func_00187D70(S17A *);
    extern s32 func_00184C60(S17A *);
    extern s32 func_00186120(S17A *);
    extern void func_001863F0(S17A *);
    extern void func_00175700(S17A *);
    extern s32 func_001853E0(S17A *);
    extern void func_001860D0(S17A *);
    if (func_00184B30(p) != 0) return;
    if (func_00184720(p) != 0) return;
    if (func_00185A90(p) != 0) return;
    if (p->b215 == 0) {
        if (func_001884C0(p) != 0) return;
        if (func_00187D70(p) != 0) return;
        if (func_00184C60(p) != 0) return;
    }
    if (func_00186120(p) != 0) return;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_001863F0(p);
    func_00175700(p);
    if (func_001853E0(p) != 0) return;
    func_001860D0(p);
}

s32 func_0012A990(u16 a, s32 pos, s32 max, u32 fl) {
    extern void func_001E3CE0(s32);
    u32 m = a & 0x3C00;
    if (m == 0x800) {
        pos--;
        if (fl & 1) {
            if (pos < 0) {
                pos = 0;
                goto after;
            }
        } else if (pos < 0) {
            pos = max;
        }
        if (fl & 2) func_001E3CE0(4); else func_001E3CE0(1);
    }
after:
    if (m == 0x400) {
        pos++;
        if (fl & 1) {
            if (max < pos) {
                pos = max;
                goto ret;
            }
        } else if (max < pos) {
            pos = 0;
        }
        if (fl & 2) func_001E3CE0(4); else func_001E3CE0(1);
    }
ret:
    return pos;
}
