typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
typedef struct Obj { struct VT *vt; } Obj;
typedef struct VT { u8 pad[0x20]; void (*fn)(Obj *, s32, s32 *); } VT;
typedef struct {
    u8 b0; u8 b1; s8 b2; u8 b3;
    Obj *o4; Obj *o8;
    s32 c; s32 d10; s32 e14; volatile s32 f18;
    u8 pad1c[0x2C - 0x1C];
    s32 h2c;
    u8 pad30[0x3C - 0x30];
    volatile s32 t3c;
} St;
void func_00408ED8(St *p)
{
    extern s32 func_00104180(s32);
    p->b1 = 0;
    if (p->b2 == 1) {
        while (func_00104180(p->h2c) >= 0) {
        }
        p->o4->vt->fn(p->o4, 0, &p->c);
        p->c = 0;
        p->d10 = 0;
        p->o8->vt->fn(p->o8, 1, &p->e14);
        p->e14 = 0;
        {
            s32 n = p->t3c + p->d10;
            *(volatile s8 *)&p->b2 = 0;
            p->f18 = 0;
            p->t3c = n;
        }
    }
}
