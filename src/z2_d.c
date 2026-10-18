typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x34]; f32 f34; u8 pad1[0x24]; f32 f5c; u8 pad2[8]; f32 f68; u8 pad3[0xE5]; s8 b151; } P2772A0;
void func_002772A0(P2772A0 *p)
{
    extern s8 func_00175700();
    extern void func_001843A0();
    extern void func_0037CBB0();
    f32 *a, *b;
    f32 z = 0.0f;
    a = &p->f5c;
    b = &p->f68;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    if (!(p->f5c * p->f68 < z)) {
        *a = z;
        *b = z;
    }
    if (func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    switch (p->b151) {
    case 2:
        p->b151 = 0;
        func_0037CBB0(p);
        break;
    case 3:
        p->b151 = 0;
        break;
    case 4:
        p->b151 = 0;
        *(u32 *)a = 0;
        *(u32 *)b = 0;
        break;
    }
}

void func_0018DAC0(u8 *p)
{
    extern void func_0018C8A0();
    extern void func_001757E0(u8 *, s32, u8);
    u8 n;
    u8 x;
    p[0x247] = 0;
    p[0x248] = 0;
    func_0018C8A0(p);
    n = 0;
    x = (*(s8 *)(p + 0x245) & 0x70);
    if ((u8)x) {
        if ((u8)x == 0x30) {
            n += 2;
        } else if ((u8)x == 0x20) {
            n++;
        }
    } else {
        u8 t = p[0x243];
        if (t >= 5) n++;
        if (t >= 0xC) n++;
    }
    func_001757E0(p, 0xD, n);
}

