typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

static u32 *func_003F1F90(u32 *p, u32 key)
{
    u32 *e = p;
    u32 i;
    if (p[0] & key) {
        e += 3;
        for (i = 0; i < p[1]; i++) {
            if (e[0] == key) return e;
            e = (u32 *)((u8 *)e + e[2]);
        }
    }
    return 0;
}

u8 *func_003F2550(u32 *p, s32 i) {
    u8 *r = (u8 *)func_003F1F90(p, 0x4000);
    if (r == 0) {
        return 0;
    }
    return (u8 *)((s32)r + 0xC) + i * 8;
}
