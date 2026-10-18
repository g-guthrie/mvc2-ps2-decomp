typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

/* Shared acceleration update; the owner argument belongs to the common
 * two-actor call interface and is unused by this helper. */
static void func_00195630(u8 *p, u8 *owner)
{
    *(f32 *)(p + 0x68) -= *(f32 *)(p + 0x98);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C) + *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x6C) -= *(f32 *)(p + 0x9C);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60) + *(f32 *)(p + 0x6C);
}

typedef struct { u8 pad0[5]; u8 b5; u8 b6; u8 pad7[0x15]; s16 h1c; u8 pad1e[3]; u8 b21; u8 pad22[0x12]; f32 f34, f38; u8 pad3c[0x20]; f32 f5c, f60, pad64, f68, f6c; } S13;
void func_00196120(S13 *p, S13 *q) {
    extern int func_00175670(u8 *);
    extern void func_001975C0(u8 *, u8 *);
    f32 *a3 = (f32 *)((u8 *)p + 0x88);
    s16 h = p->h1c;
    p->h1c = h - 1;
    if (h != 0) {
        func_00195630((u8 *)p, (u8 *)q);
        func_00175670((u8 *)p);
        func_001975C0((u8 *)p, (u8 *)q);
        return;
    }
    {
        u32 t = p->b5;
        p->b5 = t + 1;
    }
    a3[6] = p->f34 - q->f34;
    a3[7] = p->f38 - q->f38;
    a3[4] = p->f34;
    a3[5] = p->f38;
    *(u32 *)&p->f5c = 0x3FD55555;
    *(u32 *)&p->f68 = 0xBDD55555;
    *(u32 *)&p->f60 = 0xBFCDB6DB;
    *(u32 *)&p->f6c = 0x3D892492;
    if (p->b21 & 2) {
        p->f5c = -p->f5c;
        p->f68 = -p->f68;
    }
    if (p->b21 & 1) {
        p->f60 = -p->f60;
        p->f6c = -p->f6c;
    }
    func_00175670((u8 *)p);
    func_001975C0((u8 *)p, (u8 *)q);
}

void func_00197070(S13 *p, S13 *q) {
    extern int func_00175670(u8 *);
    extern void func_001975C0(u8 *, u8 *);
    f32 *a3 = (f32 *)((u8 *)p + 0x88);
    s16 h = p->h1c;
    p->h1c = h - 1;
    if (h != 0) {
        func_00195630((u8 *)p, (u8 *)q);
        func_00175670((u8 *)p);
        func_001975C0((u8 *)p, (u8 *)q);
        return;
    }
    {
        u32 t = p->b6;
        p->b6 = t + 1;
    }
    a3[6] = p->f34 - q->f34;
    a3[7] = p->f38 - q->f38;
    a3[4] = p->f34;
    a3[5] = p->f38;
    *(u32 *)&p->f5c = 0x3FD55555;
    *(u32 *)&p->f68 = 0xBDD55555;
    *(u32 *)&p->f60 = 0xBFCDB6DB;
    *(u32 *)&p->f6c = 0x3D892492;
    if (p->b21 & 2) {
        p->f5c = -p->f5c;
        p->f68 = -p->f68;
    }
    if (p->b21 & 1) {
        p->f60 = -p->f60;
        p->f6c = -p->f6c;
    }
    func_00175670((u8 *)p);
    func_001975C0((u8 *)p, (u8 *)q);
}

void func_001956E0(u8 *p, u8 *q)
{
    extern int func_00175670(u8 *);
    extern void func_001975C0(u8 *, u8 *);
    s16 timer = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = timer - 1;
    if (timer == 0) p[6]++;
    func_00195630(p, q);
    func_00175670(p);
    func_001975C0(p, q);
}
