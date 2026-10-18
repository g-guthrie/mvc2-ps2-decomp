typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
typedef struct {
    u8 pad0[0x34];
    f32 f34, f38;
    u8 pad1[0x5C - 0x3C];
    f32 f5c, f60;
    u8 pad2[4];
    f32 f68, f6c;
} S8;
extern s32 func_00175700(void *);
extern void func_001843A0(void *);
void func_00217AD0(S8 *p) {
    u8 *q = (u8 *)p;
    s16 timer;
    func_00175700(p);
    if (*(s8 *)(q + 0x151) == 0) {
        if (q[0x20] != 0 && q[0x214] == 0) {
            q[0x20] = 0;
            *(u32 *)(q + 0x5C) = 0xC1855555;
            if (q[0x1E6] != 0)
                p->f5c = -p->f5c;
        }
        p->f34 += p->f5c;
        p->f5c += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6c;
        timer = *(s16 *)(q + 0x1C) - 1;
        *(s16 *)(q + 0x1C) = timer;
        if (timer <= 0)
            func_001843A0(p);
    }
}
