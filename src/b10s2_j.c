typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x18]; s16 w; s16 h; s32 fmt; } R;
s32 func_003EA990(R *p) {
    s32 r;
    switch (p->fmt) {
    case 0:
        r = p->w * p->h * 4;
        break;
    case 1:
        r = p->w * p->h * 3;
        break;
    case 2:
        r = p->w * p->h * 2;
        break;
    case 0x13:
        r = p->w * p->h;
        break;
    case 0x14:
        r = (p->w * p->h) >> 1;
        break;
    }
    return r;
}
