typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

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

typedef struct { s32 a, b, c; } E12;
u8 *func_003F24D0(u8 *a, s32 n)
{
    u8 *r;
    E12 *q;
    r = (u8 *)func_003F1F90((u32 *)a, 0x800);
    q = (E12 *)(r + 12);
    if (r == 0) return 0;
    return (u8 *)&q[n];
}
