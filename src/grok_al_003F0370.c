typedef unsigned char u8;
typedef signed int s32;
typedef unsigned int u32;

typedef struct {
    s32 pad[7];
    void *p1c;
    void *p20;
    void *p24;
    s32 pad2[6];
    struct { s32 pad[5]; s32 f14; } *p40;
} Obj;

extern u32 *func_003DD030(void *);
extern s32 D_00478DF0[];
extern void func_003DBA90(u32 *pkt, s32 a, void *b, s32 c, s32 d);

void func_003F0370(Obj *obj)
{
    u32 *s1;
    u32 *s2;
    u32 *s0;
    u32 word;
    u32 kind;
    s32 scale;
    u32 *base;
    s32 factor;

    s1 = func_003DD030(obj->p1c);
    if (s1 == 0)
        return;
    s2 = func_003DD030(obj->p24);
    if (s2 == 0)
        return;
    for (;;) {
        s0 = s1;
        for (;;) {
            word = s0[0];
            kind = word & 0x70000000;
            s1 += 4;
            if (kind == 0x70000000)
                return;
            if (kind == 0x30000000) {
                scale = *s2++;
                base = func_003DD030(obj->p20);
                factor = D_00478DF0[obj->p40->f14];
                func_003DBA90(s0, factor >> 4, (u8 *)base + factor * scale, 0, 0);
                s0 = s1;
            } else {
                s1 = (u32 *)((u8 *)s1 + ((word & 0xFFFF) << 4));
                break;
            }
        }
    }
}
