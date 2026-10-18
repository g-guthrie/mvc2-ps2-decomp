typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct VT { u8 pad[0x24]; s32 (*fn)(void *, s32); } VT;
typedef struct Obj { VT *vt; } Obj;

extern u8 D_004BC368[];
extern void func_003FB128(u8 *);
extern s32 func_00401920(u8 *);
extern s32 func_00401F38(u8 *);
extern s32 func_00401EE8(u8 *);

f32 func_00402300(u8 *p) {
    f32 r = 0.0f;
    s32 a, b;
    Obj *o;
    if (p == 0) {
        func_003FB128(D_004BC368);
        return -1.0f;
    }
    if (func_00401920(p) >= 2) {
        o = *(Obj **)(p + 0x14);
        if (o != 0) {
            a = o->vt->fn(o, 1);
            b = func_00401F38(p);
            r = (f32)((a / (b * 18)) << 5) / (f32)func_00401EE8(p);
        }
    }
    return r;
}
