typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct SA37_R {
    u8 *buf;
    u16 pos;
    u8 pad6;
    u8 b7;
} SA37_R;

typedef struct SA37_J0 {
    u8 pad0[0x454];
    u8 b454;
    u8 pad455[0x4C8 - 0x455];
    s32 w4c8;
} SA37_J0;

void func_0016B0C0(SA37_J0 *p, SA37_R *r, s32 op) {
    extern void func_0016B0B0(SA37_J0 *);
    u8 *b;
    u32 t;
    b = r->buf;
    b += r->pos;
    switch (op) {
    case 0:
        func_0016B0B0(p);
        p->b454 = *b;
        t = r->pos;
        r->pos = t + 1;
        t = r->b7;
        r->b7 = t + 1;
        break;
    case 1:
        p->w4c8 = b[0];
        t = r->pos;
        r->pos = t + 1;
        break;
    case 2:
        p->w4c8 = (u16)(s16)((b[0] << 8) | b[1]);
        t = r->pos;
        r->pos = t + 2;
        break;
    case 3:
        p->w4c8 = (s16)(((b[0] << 8) | b[1]) & 0xFFFF);
        *(f32 *)&p->w4c8 = 1.6666666269302368f * (f32)p->w4c8;
        t = r->pos;
        r->pos = t + 2;
        break;
    case 4:
        p->w4c8 = (s16)(((b[0] << 8) | b[1]) & 0xFFFF);
        *(f32 *)&p->w4c8 = 2.142857074737549f * (f32)p->w4c8;
        t = r->pos;
        r->pos = t + 2;
        break;
    default:
        break;
    }
}
