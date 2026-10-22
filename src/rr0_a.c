typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 *p; s32 z; s32 a; s32 b; s32 c; } R0S;
extern u8 *D_004C283C;
extern void func_00341DF0();
extern void func_00170E60(s32 a, s32 b, s32 c, s32 d, void *e, s32 f);

typedef struct { u8 pad0[0x1C]; s16 h1C; s16 h1E; u8 b20; u8 pad21[0xCC - 0x21]; s16 hCC; u8 padCE[0xD4 - 0xCE]; s32 w1; s32 w2; s32 w3; } R0P;

void func_00341CC0(R0P *p) {
    R0S st;
    s32 a, b, c;
    u8 *q;
    u8 *t;
    p->h1C += p->b20 + 1;
    if (p->h1C >= 0x5A0) p->h1C = p->h1C % 0x5A0;
    {
        s16 v = p->h1E + 1;
        p->h1E = v;
        if (v >= 0x168) p->h1E = 0;
    }
    p->w1 += 0x100;
    p->w2 += 0x80;
    p->w3 += 0x40;
    p->w1 = (u32)p->w1 & 0xFFFF;
    p->w2 = (u32)p->w2 & 0xFFFF;
    p->w3 = (u32)p->w3 & 0xFFFF;
    a = *(volatile s32 *)&p->w1;
    b = p->w2;
    c = p->w3;
    q = *(u8 **)((u8 *)p + 0x84);
    st.a = a;
    st.b = b;
    st.c = c;
    st.p = (u8 *)p;
    st.z = 0;
    t = *(u8 **)(q + 0x1C);
    func_00170E60(*(s32 *)(D_004C283C + 0x14), *(s32 *)(((p->b20 << 3) + (u32)t) + 0x24) + 0x190,
                  *(s32 *)(q + 0x14), *(s32 *)(t + p->hCC * 4), func_00341DF0, (s32)&st);
}
