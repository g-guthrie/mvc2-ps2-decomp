typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    s32 pad;
    s32 f04;
    s32 f08;
    u16 f0c;
    u8 pad2[3];
    u8 f11;
} Hdr;

extern Hdr *func_003F51F0(u8 *, s32);
extern s32 func_003F5180(u8 *, s32);

s32 func_003F5440(u8 *obj)
{
    Hdr *h;
    s32 total;
    s32 aligned;
    s32 n;
    s32 i;
    s32 extra;

    h = func_003F51F0(obj, 0);
    total = (s32)h;
    aligned = func_003F5180(obj, 0x30);
    total += aligned;
    n = h->f11;
    if (n >= 2) {
        for (i = 0; i < n; i++)
            ;
        extra = (n >= 5) ? 0x30 : 0x20;
        extra = func_003F5180(obj, extra);
        total += extra;
        aligned += extra;
    }
    if (aligned < (s32)h->f0c)
        total += func_003F5180(obj, 0x10);
    if (h->f04 == 0)
        return 0;
    return total + h->f08;
}
