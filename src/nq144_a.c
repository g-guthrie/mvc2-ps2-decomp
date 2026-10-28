typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

#define W(o) (*(s32 *)(p + (o)))
typedef struct {
    u8 pad0[0x152]; s8 b152; u8 pad153[0x2DC - 0x153];
    s32 w2DC; s32 pad2E0; s32 w2E4; s32 w2E8; s32 w2EC; s32 w2F0; s32 w2F4; s32 w2F8; s32 w2FC; s32 w300; s32 w304;
} A2267;
#define WS(o) (((A2267 *)p)->w##o)

void func_002267E0(u8 *p)
{
    extern void func_0018FAA0(u8 *, s32);
    extern void func_0022C220(u8 *, u8 *);
    extern void func_001757E0(u8 *, s32, u8);
    s32 t;
    s32 s;
    u8 c;

    if (*(s8 *)(p + 0x1B4) == 0) {
    if ((t = W(0x2DC)) != 0) {
        WS(2DC) = t - 1;
    }
    if ((t = W(0x304)) > 0) {
        WS(304) = t - 1;
        return;
    }
    if ((t = W(0x2E4)) > 0) {
        WS(2E4) = --t;
        if (t <= 0) goto hit;
    }
    if ((t = W(0x2E8)) > 0) {
        WS(2E8) = --t;
        if (t <= 0) goto hit;
    }
    if ((t = W(0x2EC)) > 0) {
        WS(2EC) = t - 1;
        *(s16 *)(p + 0x3FE) = 3;
    }
    if ((t = W(0x2FC)) > 0 && p[0x1F0] == 0) {
        A2267 *sa = (A2267 *)p;
        sa->w2FC = t - 1;
        if ((sa->w2FC & 7) == 0) {
            func_0018FAA0(p, 1);
        }
    }
    if ((t = W(0x2F4)) > 0) {
        WS(2F4) = t - 1;
        *(s16 *)(p + 0x3F8) = 3;
    }
    if ((t = W(0x300)) > 0) {
        WS(300) = t - 1;
        *(s16 *)(p + 0x3F8) = 3;
    }
    if ((t = W(0x2F0)) > 0) {
        WS(2F0) = --t;
        if (t <= 0) goto hit;
    }
    if ((t = W(0x2F8)) <= 0) return;
    WS(2F8) = --t;
    if (t > 0) return;
hit:
    W(0x2BC) = p[1];
    func_0022C220(p, p);
    if (p[0x169] != 0) return;
    c = p[0x168];
    if (c == 8 || c == 9 || c == 1) {
        t = *(s8 *)(p + 0x161) - 0x40;
        if (t < 0) t = 0;
        s = *(s8 *)(p + 0x152);
        func_001757E0(p, 0, t);
        if (s < *(s8 *)(p + 0x152)) {
            ((A2267 *)p)->b152 = s;
        }
    }
    } else {
        if (W(0x304) == 0 && W(0x2F4) > 0) {
            *(s16 *)(p + 0x3F8) = 3;
        }
    }
}
