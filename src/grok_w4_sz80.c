typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[16];
    void *callback;
    void *arg;
    u8 pad18[0x60];
    f32 f78;
    f32 f7c;
    f32 f80;
    u32 field84;
    u8 pad88[0x40];
    void *fieldc8;
    u16 fieldcc;
    u8 padce[2];
    u32 fieldd0;
    u8 padd4[0x68];
    u8 field13c;
} Event80;

extern s32 func_0016B250(u8 *, s32);
extern s32 func_0016B0C0(u8 *, u8 *, s32);
extern s32 func_00165C90(u8 *, u8 *);
extern Event80 *func_003DA750(int, int, int);
extern void func_00140C70(void);
extern void func_00140DC0(void);
extern u32 D_004C2818;

s32 func_00165B80(u8 *p, u8 *q)
{
    if (!func_0016B250(p, 4))
        return 0;
    func_0016B0C0(p, q, 0);
    func_0016B0C0(p, q, 1);
    p[0x451]++;
    *(s32 *)(p + 0x460) = *(s32 *)(p + 0x4c8);
    return func_00165C90(p, q);
}

s32 func_00165CD0(u8 *p, u8 *q)
{
    if (!func_0016B250(p, 5))
        return 0;
    func_0016B0C0(p, q, 0);
    func_0016B0C0(p, q, 1);
    p[0x451]++;
    *(s32 *)(p + 0x460) = *(s32 *)(p + 0x4c8);
    return func_00165C90(p, q);
}

void func_00140BF0(u8 *p)
{
    Event80 *e = func_003DA750(0, 13, 1);
    if (e) {
        e->field13c = 1;
        e->callback = func_00140C70;
        e->fieldcc = 0x20;
        e->field84 = D_004C2818;
        e->fieldd0 = 0x808C00;
        e->arg = p;
        e->fieldc8 = p + 0x88;
        e->f78 = 1.0f;
        e->f7c = 1.0f;
        e->f80 = 1.0f;
    }
}

void func_00140D40(u8 *p)
{
    Event80 *e = func_003DA750(0, 13, 1);
    if (e) {
        e->field13c = 1;
        e->callback = func_00140DC0;
        e->fieldcc = 0x21;
        e->field84 = D_004C2818;
        e->fieldd0 = 0x800C00;
        e->arg = p;
        e->fieldc8 = p + 0x88;
        e->f78 = 1.0f;
        e->f7c = 1.0f;
        e->f80 = 1.0f;
    }
}
