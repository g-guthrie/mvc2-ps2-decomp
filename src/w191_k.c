typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[5];
    u8 b5;
    u8 b6;
    u8 pad7[0x1C - 7];
    s16 h1C;
    u8 pad1E[0x34 - 0x1E];
    f32 f34;
    f32 f38;
    u8 pad3c[0x5C - 0x3C];
    f32 f5c;
    f32 f60;
    u8 pad64[0x68 - 0x64];
    f32 f68;
    f32 f6c;
    u8 pad70[0x1B2 - 0x70];
    s8 b1B2;
    s8 b1B3;
} P380;

typedef struct {
    u8 pad0[5];
    u8 b5;
    u8 pad6[0x2F8 - 6];
    s32 w2F8;
} Q380;

void func_00380650(P380 *a, Q380 *b)
{
    extern s32 func_00185980(void);
    extern void func_00380A40(P380 *, Q380 *);
    extern void func_00380B40(void);
    extern void func_00380A90(P380 *);
    extern void func_001E7F60(P380 *);
    u32 t;

    if (b->b5 != 0 || a->b1B3 != 0 || b->w2F8 != 0) {
        goto fail;
    }
    if (a->b1B2 != 0) {
        if (func_00185980() == 0) {
            goto fail;
        }
        t = a->b5;
        a->b5 = t + 1;
        b->w2F8 = b->w2F8 + 1;
        func_00380A40(a, b);
    } else {
        a->f34 += a->f5c;
        a->f5c += a->f68;
        a->f38 += a->f60;
        a->f60 += a->f6c;
        if (--a->h1C == 0) {
            goto fail;
        }
        func_00380B40();
        func_00380A90(a);
        func_001E7F60(a);
    }
    return;
fail:
    a->b5 = 4;
    a->b6 = 0;
}
