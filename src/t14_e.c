typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_001748C0(void *, void *);
typedef struct { u8 p0[0x220]; u8 *w220; } Q_0037E970;
typedef struct { u8 p0[0x1C]; s16 h1C; s16 h1E; u8 p1[2]; u8 b22; u8 p2[0x11]; u8 f34[1]; } S_0037E970;
void func_0037E970(S_0037E970 *p, Q_0037E970 *q) {
    s16 h = p->h1C - 1;
    s32 r, d; u8 t;
    p->h1C = h;
    if (h == 0) {
        q = (Q_0037E970 *)q->w220;
        r = func_001748C0(p->f34, (u8 *)q + 0x34);
        d = p->b22;
        t = (r & 0xFF) >> 3;
        if (t != d) {
            if (((t - d) & 0x1F) < 0x10) p->b22 = d + 1;
            else p->b22 = d - 1;
            { u32 x = p->b22; p->b22 = x & 0x1F; }
        }
        h = p->h1E - 1;
        p->h1E = h;
        if (h == 0) p->h1C = -1;
        else p->h1C = 5;
    }
}
