typedef signed int s32;
typedef unsigned int u32;

typedef struct {
    s32 f00;
    s32 pad;
    s32 *slots;
    s32 f0c;
    s32 f10;
    s32 pad2;
    s32 f18;
    s32 f1c;
} Pool;

extern s32 func_003F0B20(Pool *);

s32 func_003F0C60(Pool *p, s32 n, s32 m)
{
    s32 i;
    s32 *slot;
    s32 off;

    if ((u32)(n + m) >= (u32)func_003F0B20(p))
        return 0;
    i = 0;
    off = 0;
    while (i < p->f00) {
        if (*(s32 *)((char *)p->slots + off + 4) == 0)
            break;
        off += 16;
        i++;
    }
    if (i == p->f00) {
        return 0;
    }
    off = i << 4;
    slot = (s32 *)((char *)p->slots + off);
    slot[3] = 0;
    slot = (s32 *)((char *)p->slots + off);
    slot[1] = n;
    slot = (s32 *)((char *)p->slots + off);
    slot[2] = p->f18;
    if (p->f0c != 0) {
        slot = (s32 *)((char *)p->slots + off);
        slot[0] = (p->f10 + m - 1) & ~(m - 1);
        p->f10 = ((s32 *)((char *)p->slots + off))[0] + n;
    } else {
        slot = (s32 *)((char *)p->slots + off);
        slot[0] = ~(m - 1) & (p->f10 - n);
        p->f10 = ((s32 *)((char *)p->slots + off))[0];
    }
    p->f1c += n;
    return i + 1;
}
