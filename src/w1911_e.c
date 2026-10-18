typedef unsigned char u8;
typedef signed int s32;
typedef struct { u8 *cur; u8 b4; u8 b5; } CS;
typedef struct { u8 b0, b1, b2, b3; s32 w4; } Rec;
void func_001C3DC0(u8 *a, u8 *c, Rec *r) {
    CS *s = (CS *)(a + 0xD0);
    extern void func_00176160(u8 *, s32, s32, s32);
    do {
        s->b4 = r->b0;
        func_00176160(c, r->b1, r->b2 + c[0x25] * 0x57, r->b3);
        if (r->w4 == 1) s->b5 = 0; else s->b5 = 1;
        r = (Rec *)((u8 *)r + (r->w4 << 3));
    } while (s->b4 == 0);
    s->cur = (u8 *)r;
}
