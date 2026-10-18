typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x7C]; s16 v[1]; } G0;
extern G0 *D_004C2794;
typedef struct P {
    u8 p0[2]; u8 b2; u8 p3[0x31]; f32 f34; u8 p38[0x24]; f32 f5c; u8 p60[8]; f32 f68; u8 p6c[0xE4]; s8 b150; s8 b151;
    u8 p152[0x60]; u8 b1b2; u8 p1b3[2]; u8 b1b5; u8 p1b6[0xA]; u16 h1c0; u8 p1c2[0x16]; u32 w1d8; u8 p1dc[0xDC];
    u16 h2b8; u8 p2ba[0x9A]; u16 h354; u8 p356[0x1E3]; s8 b539;
} P;
void func_001F0540(P *p) {
    extern void func_00183D90(P *);
    extern s32 func_00175700(P *);
    extern void func_001843A0(P *);
    u16 *s;
    u16 h;
    s8 k;
    s = &p->h2b8;
    func_00183D90(p);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    k = p->b150;
    if (k != 0) {
        p->b1b5 = k;
        p->b1b2 = p->h1c0 = 0;
        p->w1d8 = 0;
        D_004C2794->v[p->b2]++;
        p->b150 = 0;
    }
    if (p->b151 == 0) {
        *(u32 *)&p->f5c = 0;
    } else if (p->b539 != 0) {
        h = *s;
        if (h & 0x800) *(u32 *)&p->f5c = 0xC0555555;
        else if (h & 0x400) *(u32 *)&p->f5c = 0x40555555;
        else *(u32 *)&p->f5c = 0;
    } else {
        h = p->h354;
        if (h & 0xC00) {
            if (h & 0x800) *(u32 *)&p->f5c = 0xC0555555;
            else if (h & 0x400) *(u32 *)&p->f5c = 0x40555555;
        } else {
            *(u32 *)&p->f5c = 0;
        }
    }
}
