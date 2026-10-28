typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

typedef struct Bone {
    u8 pad0[0x8];
    struct Bone *next;
    u8 pad1[0x1E - 0xC];
    s16 n;
    u8 pad2[0x22 - 0x20];
    u8 id;
    u8 pad3[0x34 - 0x23];
    f32 x;
    f32 y;
    u8 pad4[0x140 - 0x3C];
    s16 flip;
} Bone;

typedef struct { s16 a, b, c, d; } BEnt;
extern BEnt D_0044AE00[];

void func_001A1A90(Bone *b, u8 *q)
{
    u8 *r = q + 0x2B8;
    Bone *c;
    BEnt *e;
    f32 oy;
    f32 ay, ax, ox, dx, dy, ex, ey;
    s32 n, i;
    Bone *cur;

    b = *(Bone **)((u8 *)b + 0x14);
    c = b->next;
    ox = 0.0f;
    oy = 8.571428298950195f;
    e = &D_0044AE00[c->id];
    dx = 1.6666666269302368f * (f32)e->a;
    dy = 2.142857074737549f * (f32)e->b;
    if (b->flip != 0) {
        ox = -ox;
        dx = -dx;
    }
    c->x = b->x + ox - dx;
    c->y = b->y + oy - dy;
    n = b->n - 1;
    i = 1;
    if (n > 1) {
        do {
            e = (BEnt *)((s16 *)D_0044AE00 + (c->id * 4 + 2));
            cur = c;
            c = c->next;
            ax = 1.6666666269302368f * (f32)e->a;
            ay = 2.142857074737549f * (f32)e->b;
            e = &D_0044AE00[c->id];
            ex = 1.6666666269302368f * (f32)e->a;
            ey = 2.142857074737549f * (f32)e->b;
            if (cur->flip != 0) {
                ax = -ax;
                ex = -ex;
            }
            i++;
            c->x = cur->x + ax - ex;
            c->y = cur->y + ay - ey;
        } while (i < n);
    }
    if (r[5] == 1) {
        *(f32 *)(q + 0x34) = c->x - *(f32 *)(r + 0x24);
        *(f32 *)(q + 0x38) = c->y - *(f32 *)(r + 0x28);
    }
}
