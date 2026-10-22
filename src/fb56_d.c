typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u32 magic;
    volatile u32 w4;
    u8 pad8[0x50];
    u32 tag;
    u16 h5c;
    u16 h5e;
    f32 fv;
    u16 ver;
} PH;

#define BE32(p, o) (((u32)(p)[o] << 24) | ((u32)(p)[(o) + 1] << 16) | ((u32)(p)[(o) + 2] << 8) | (u32)(p)[(o) + 3])
#define BE16(p, o) (((u32)(p)[o] << 8) | (u32)(p)[(o) + 1])

u8 *func_003F4A00(u8 *p)
{
    PH h;
    u32 *d0 = &h.magic, *d58 = &h.tag, *d4 = (u32 *)&h.w4, *d60 = (u32 *)&h.fv;
    u16 *d64 = &h.ver;
    u8 *q;
    u32 w;

    *d0 = BE32(p, 0);
    *d58 = BE32(p, 0x58);
    h.h5c = BE16(p, 0x5C);
    h.h5e = BE16(p, 0x5E);
    *d64 = BE16(p, 0x64);
    *d4 = BE32(p, 4);
    *d60 = BE32(p, 0x60);
    if (h.magic != 0x5380F634) return 0;
    if (h.tag != 0x50494354) return 0;
    if (h.fv != 1.0f) return 0;
    if (h.ver != 3) return 0;
    q = p + 0x68;
    w = BE32(p, 0x68);
    q += 4;
    if (w != 0x802E0) {
        if (w != 0x10802E0) {
            q = 0;
        } else {
            w = BE32(q, 0);
            q += 4;
            if (w != 0x80210) q = 0;
        }
    }
    return q;
}
