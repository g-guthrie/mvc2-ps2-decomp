typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct V3c { f32 x, y, z; } V3c;

typedef struct Gc {
    u8 pad0[0x3E];
    s8 b3E;
} Gc;

typedef struct Oc {
    u8 pad0[4];
    u8 b4;
    u8 pad5[0x1C - 5];
    s16 h1C;
    s16 h1E;
    u8 b20;
    u8 pad21[0x34 - 0x21];
    V3c v34;
    u8 pad40[0xD4 - 0x40];
    s32 iD4;
    u8 padD8[0x13C - 0xD8];
    u8 b13C;
} Oc;

extern Gc *D_004C2794;
extern V3c D_0043EA60[];
extern s32 D_0043EAE0[];

void func_001352A0(Oc *p)
{
    extern s32 func_0016D130();
    extern void func_00135DB0(s32);
    extern void func_003DAA40(Oc *);
    extern void func_001E3CE0(s32);
    extern void func_00135600(Oc *);
    extern void func_0016CE60();
    V3c *a;
    V3c *b;
    s32 k;
    s32 idx;
    s32 t;
    s16 h;
    s32 v;

    k = p->b20;
    idx = k * 3;
    idx = p->h1E + idx;
    a = &D_0043EA60[idx];
    b = &D_0043EA60[idx + 1];
    switch (p->b4) {
    case 0:
        if (func_0016D130() != 0) {
            break;
        }
        t = p->iD4 - 1;
        p->iD4 = t;
        if (t > 0) {
            break;
        }
        p->b13C = 1;
        p->b4++;
        if (p->b20 == 2) {
            if (D_004C2794->b3E < 0) {
                func_00135DB0(1);
                func_003DAA40(p);
                break;
            }
            func_001E3CE0(0x28);
        }
    case 1:
        if (p->b20 == 0 || p->b20 == 1) {
            func_00135600(p);
        }
        p->v34.x = a->x + (f32)p->h1C * ((b->x - a->x) / 15.0f);
        p->v34.z = a->z + (f32)p->h1C * ((b->z - a->z) / 15.0f);
        h = p->h1C + 1;
        p->h1C = h;
        if (h >= 15) {
            p->b4++;
            p->h1C = 0;
            p->h1E++;
            p->v34 = *b;
        }
        break;
    case 2:
        if (k < 2 && p->h1C < 15) {
            v = p->h1C % 2;
            p->v34.x = a->x + 0.2f * (f32)v;
        }
        h = p->h1C + 1;
        p->h1C = h;
        if (h >= D_0043EAE0[p->b20]) {
            p->b4++;
            p->h1C = 0;
            if (p->b20 == 1) {
                func_0016CE60();
            }
        }
        break;
    case 3:
        if (k == 0 || k == 1) {
            func_00135600(p);
        }
        p->v34.x = a->x + (f32)p->h1C * ((b->x - a->x) / 15.0f);
        p->v34.z = a->z + (f32)p->h1C * ((b->z - a->z) / 15.0f);
        h = p->h1C + 1;
        p->h1C = h;
        if (h >= 15) {
            func_003DAA40(p);
            return;
        }
        break;
    }
}
