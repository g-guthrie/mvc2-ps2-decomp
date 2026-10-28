typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[0x34];
    f32 f34;
    f32 f38;
    u8 pad3c[0x20];
    f32 f5c;
    f32 f60;
    u8 pad64[4];
    f32 f68;
    f32 f6c;
} OB;

void func_003BF900(u8 *p, u8 *q) {
    extern s32 func_00185980(u8 *);
    extern void func_003BFC90(u8 *, u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00175700(u8 *);
    extern void func_001DCDE0(u8 *, s32);
    extern s32 func_00174470(u8 *);
    extern void func_001E7F60(u8 *);
    extern void func_003BFC80(u8 *, u8 *);
    OB *o = (OB *)p;
    u32 t;
    if (q[5] == 0 && *(s8 *)(p + 0x1B3) == 0) {
        if (*(s8 *)(p + 0x1B2) != 0) {
            if (func_00185980(p) == 0) {
                goto fail;
            }
            p[5]++;
            p[0x24] = 8;
            func_003BFC90(p, q);
            func_001757E0(p, 0x17, 4);
        } else {
            func_00175700(p);
            o->f34 += o->f5c;
            o->f5c += o->f68;
            o->f38 += o->f60;
            o->f60 += o->f6c;
            t = p[0x21] + 0x40;
            p[0x21] = t;
            if ((u8)t == 0) {
                func_001DCDE0(p, 0);
            }
            if (func_00174470(p) == 0) {
                goto tail;
            }
            func_001E7F60(p);
        }
        return;
    }
fail:
    func_001DCDE0(p, 1);
tail:
    func_003BFC80(p, q);
}
