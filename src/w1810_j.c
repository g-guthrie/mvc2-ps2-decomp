typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct {
    u8 p0[6]; u8 b6; u8 b7; u8 p8[0x52]; f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c; u8 p70[0x60];
    u32 wd0; u32 wd4; u8 pd8[0x68]; s16 h140; u8 p142[0xF]; s8 b151;
} P;
typedef struct { u8 p0[0x1E4]; u8 b1e4; u8 p1e5[2]; s8 b1e7; u8 p1e8[0x15]; u8 b1fd; } Q;
void func_001AC050(P *p, Q *q) {
    extern void func_00175700();
    s8 k;
    if (q->b1e4 == 0x1D) {
        switch (q->b1fd) {
        case 5:
            p->wd0 = p->b6;
            p->wd4 = p->b7;
            p->b6 = 0xF;
            p->b7 = 0;
            break;
        case 4:
            p->wd0 = p->b6;
            p->wd4 = p->b7;
            p->b6 = 0x11;
            p->b7 = 0;
            break;
        }
        return;
    }
    func_00175700(p);
    if (p->b151 == 0) {
        p->b7++;
        k = q->b1e7;
        if (k == 0) p->f5c = -5.0f;
        else if (k == 1) p->f5c = 5.0f;
        else p->f5c = 0.0f;
        if (p->h140 != 0) p->f5c = -p->f5c;
        *(u32 *)&p->f68 = 0;
        p->f60 = 34.28571319580078f;
        p->f6c = -0.8035714030265808f;
    }
}
