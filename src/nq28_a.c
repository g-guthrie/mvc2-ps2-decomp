typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef struct { u8 pad0[2]; u8 f2; } PA;
typedef struct { u8 pad0[3]; u8 f3; u8 pad4[0x156]; u8 f15A; u8 pad15B[0x29]; u8 *f184; u8 pad188[0x2D]; u8 f1B5; } OA;
extern s8 D_004C2798[2];
extern OA *D_004D3170[];
s32 func_0016A320(PA *p) {
OA *o; s32 r; s32 i; s32 n; s32 t; t = p->f2 ^ 1; r = 0; n = D_004C2798[t];
    for (i = 0; i < n; i++) {
        o = ((OA **)((u8 *)D_004D3170 + t * 0x178))[i];
        if (o->f3 == 0 || o->f3 == 1 || o->f3 == 3) {
            if ((o->f15A & 0xE0) >= 0x80) { u8 *e = o->f184; r |= 1; e += (o->f1B5 & 0x7F) * 28; r |= e[2] & 0xF; }
        }
    }
    return r;
}
