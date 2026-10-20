typedef unsigned char u8;
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


char *func_003F24D0(char *a, s32 idx, s32 c) {
    char *r = (char *)func_003F1F90((u32 *)a, 0x800);
    char *q = r + 0xC;
    if (r == 0) return 0;
    return q + idx * 12;
}

char *func_003F2590(char *a, s32 idx, s32 c) {
    char *r = (char *)func_003F1F90((u32 *)a, 0x8000);
    s32 off = idx << 4;
    if (r == 0) return 0;
    return (char *)((s32)(r + 0xC) + off);
}
