struct Object;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_003DAA40(struct Object *);
typedef struct { s8 p0[2]; s8 b2; s8 b3; u8 p1[0x8D]; s8 b91; } G;
extern G *D_004C2840;
typedef struct { u8 p0[0x78]; f32 f78; f32 f7c; f32 f80; u8 p1[0xB8]; u8 b13C; } S_0013F350;
void func_0013F350(S_0013F350 *p) {
    f32 v;
    if (D_004C2840->b2 >= 3) {
        v = p->f78;
        if (!(v < 0.5f)) {
            f32 w = v - 0.0099999998f;
            p->f78 = w;
            p->f7c = w;
            p->f80 = p->f78;
        }
    } else if (D_004C2840->b91 != 0) {
        func_003DAA40((struct Object *)p);
        return;
    }
    if (D_004C2840->b2 >= 5 && D_004C2840->b3 > 0) p->b13C = 0;
}
