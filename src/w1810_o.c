typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
extern s8 D_004ACD08[];
#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define S8(p, o) (*(s8 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define V(p, o) (*(V3 *)((u8 *)(p) + (o)))
typedef struct { u8 pad[0x2B8]; s8 b[8]; } PB;
void func_001BFD10(u8 *p, V3 *q, s32 a) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_001BFE80();
    u8 *o;
    s8 *c;
    s32 i;
    s32 *d;
    s32 *s;
    s8 *bb = ((PB *)p)->b;
    s8 f = bb[2];
    c = bb + 2;
    if (f < 6) {
        if ((o = func_003DA750(0, 4, 0)) != 0) {
            *(void **)(o + 0x10) = func_001BFE80;
            *(u8 **)(o + 0x18) = p;
            s = (s32 *)(p + 0xEC);
            d = (s32 *)(o + 0xEC);
            i = 0x31;
            do {
                *d = *s;
                i--;
                s++;
                d++;
            } while (i > 0);
            U8(o, 0x13C) = 1;
            U8(o, 2) = U8(p, 2);
            U8(o, 1) = U8(p, 1);
            F32(o, 0x50) = F32(p, 0x50);
            F32(o, 0x54) = F32(p, 0x54);
            U8(o, 0x1B7) = U8(p, 0x1B7);
            U8(o, 0x1B8) = U8(p, 0x1B8);
            S8(o, 0x30) = S8(p, 0x30);
            V(o, 0x50) = V(p, 0x50);
            S8(o, 0x24) = S8(p, 0x24);
            *(u32 *)(o + 0x118) = 0x3F800000;
            S8(o, 0x13D) = -1;
            *(s16 *)(o + 0x13E) = D_004ACD08[U8(p, 0x1B8)];
            U8(o, 0x13C) = 0;
            U8(o, 0x20) = 1;
            U8(o, 0x21) = a;
            V(o, 0x34) = *q;
            *(s16 *)(o + 0x26) = 0x1A00;
            *c += 1;
        }
    }
}
