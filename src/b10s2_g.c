typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x34]; f32 f34; f32 f38; } A;
typedef struct { u8 pad[0x140]; s16 h; } B;
typedef struct { u8 pad[0x20]; u8 mode; u8 pad2[0x13]; f32 f34; f32 f38; } C;

void func_0041B200(A *a, B *b, C *c) {
    if (c->mode == 0) {
        if (b->h == 0) {
            a->f34 = c->f34 - 106.666664124f;
        } else {
            a->f34 = 106.666664124f + c->f34;
        }
        a->f38 = c->f38;
    } else {
        if (b->h == 0) {
            a->f34 = c->f34 - 53.333332062f;
        } else {
            a->f34 = 53.333332062f + c->f34;
        }
        a->f38 = c->f38;
    }
}
