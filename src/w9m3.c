typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 a; s32 b; s32 c; s32 d; } Slot;
typedef struct { s16 w; s16 cnt; } Cell;
extern Slot D_00632610[16];
extern s32 func_003DD030(s32);
void func_004121B0(void)
{
    Slot *s = D_00632610;
    s32 i;
    for (i = 0; i < 16; i++, s++) {
        if (s->a != 0 && s->b != 0) {
            s32 j;
            Cell *q = (Cell *)(u32)func_003DD030(s->b);
            for (j = 0; j < 0x1D0; j++, q++) {
                s32 t = q->cnt;
                if (t != 0) {
                    t--;
                    if (t == 0) {
                        *(s32 *)q = 0;
                    } else {
                        q->cnt = t;
                    }
                }
            }
        }
    }
}
