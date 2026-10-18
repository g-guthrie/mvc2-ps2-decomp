typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s32 func_00189660(u8 *, void *, u8 *);
extern void func_0018A990(u8 *, u8 *);
extern void func_00186A60(u8 *, s32);
extern u8 D_00458008[];
s32 func_0029B590(u8 *p) {
    if (func_00189660(p, D_00458008, p + 0x3B0) == 0) return 0;
    if (*(s32 *)(p + 0x30C) != 0) return 0;
    func_0018A990(p, p + 0x3B0);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 6;
    func_00186A60(p, 0x15);
    return 1;
}
typedef struct { u8 pad0[0xA]; u8 b0A; u8 b0B; u8 pad1[0x12]; s16 f; } Q28D940;
s32 func_0028D940(u8 *p) {
    Q28D940 *q = (Q28D940 *)(p + 0x2B8);
    s16 t = q->f;
    if (t != 0) {
        if (p[0x1FD] == 5) {
            q->f = 0;
            q->b0B = 0;
            q->b0A = 0xFF;
            p[0x215] = 0;
        } else {
            s16 v = t - 8;
            q->f = v;
            if (v <= 0) q->f = 1;
            return 1;
        }
    }
    return 0;
}
