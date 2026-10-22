typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 p0[0x1C]; s16 h; u8 p1[0x1E]; f32 f3c; u8 p2[8]; s32 w48; } S160;

void func_00160990(S160 *p)
{
    extern void func_003DAA40(S160 *);
    s32 v = p->h;
    s16 h = v;
    if (v != 0) {
        if (h < 11) {
            p->h += 1;
        } else if (h < 0x24) {
            p->f3c += 400.0f;
            p->w48 += 0x1B5;
            p->h += 1;
        } else if (h < 0x3D) {
            p->w48 += 0x2D8;
            p->h += 1;
        } else if (h < 0x56) {
            p->f3c += -600.0f;
            p->w48 += 0x765;
            p->h += 1;
        } else if (h < 0x6F) {
            p->f3c += 600.0f;
            p->w48 += 0x36A;
            p->h += 1;
        } else if (h < 0x88) {
            p->f3c += -600.0f;
            p->h += 1;
        } else {
            func_003DAA40(p);
            return;
        }
    } else {
        p->h += 1;
    }
}
