typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_0016D130();
extern void (*D_00454310[])(void *, void *);
typedef struct { u8 b0; } G266;
extern G266 *D_004C2794;
typedef struct { u8 pad0[0xa]; s16 fA; } S266;
typedef struct { u8 pad[6]; u8 f6; u8 f7; u8 pad2[0x2B8-8]; S266 s; } X266;
void func_00266950(X266 *p) {
    S266 *s = &p->s;
    if (D_004C2794->b0 >= 5 && func_0016D130() == 0) s->fA = 0;
    {
        s16 v = s->fA - 1;
        s->fA = v;
        if (v <= 0 && p->f6 != 4) {
            p->f6 = 4;
            p->f7 = 0;
        }
    }
    D_00454310[p->f6](p, &p->s);
}
