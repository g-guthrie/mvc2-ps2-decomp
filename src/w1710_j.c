typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x7C]; s16 h7c[1]; } G12;
typedef struct { u8 pad0[2]; u8 b2; u8 pad3[0x1B]; s16 h1e; u8 pad20[0x14]; f32 f34, f38; u8 pad3c[0x20]; f32 f5c, f60, pad64, f68, f6c; u8 pad70[0xF0]; s8 b160[8]; u8 pad168[0x4A]; s8 b1b2; } S10;
extern G12 *D_004C2794;
void func_0039B670(S10 *p) {
    extern s8 func_00175700();
    extern void func_0039B7D0();
    extern void func_001E7F60();
    s8 *b = p->b160;
    s8 f = b[1];
    s8 *q = b + 1;
    if (f == 2) {
        *q = 0;
        p->f5c = 0;
        p->f68 = 0;
    }
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (func_00175700(p) < 0) {
        func_0039B7D0(p);
        return;
    }
    {
        s16 v = p->h1e - 1;
        p->h1e = v;
        if (v == 0 && p->b1b2 != 0) {
            *(u8 *)((u8 *)p + 0x1B5) = 0x3E;
            ((u8 *)p)[0x1B2] = *(u16 *)((u8 *)p + 0x1C0) = 0;
            *(s32 *)((u8 *)p + 0x1D8) = 0;
            D_004C2794->h7c[p->b2]++;
        }
    }
    func_001E7F60(p);
}

typedef struct { f32 f0; u8 pad4[2]; u8 b6, b7; } GA;
typedef struct { u8 pad0[2]; u8 b2; u8 pad3[2]; u8 b5; u8 pad6[0x18]; s16 h1e; u8 pad20[0x14]; f32 f34, f38; u8 pad3c[0x20]; f32 f5c, f60, pad64, f68, f6c; u8 pad70[0xA8]; u32 f118; u8 pad11c[0x24]; s16 h140; } S11;
extern GA *D_004C2974;
void func_00366B80(S11 *p) {
    extern void func_001757E0();
    if (p->h1e != 0) {
        s16 v = p->h1e - 1;
        p->h1e = v;
        if (v != 0) return;
    }
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (p->f38 <= D_004C2974->f0) {
        if (D_004C2974->b6 != 0) {
            p->b5 = 8;
            p->f118 = 0x3F800000;
        } else {
            p->b5 = 5;
            p->h1e = 0x78;
            *(u8 *)((u8 *)p + 0x1B5) = 0x4E;
            ((u8 *)p)[0x1B2] = *(u16 *)((u8 *)p + 0x1C0) = 0;
            *(s32 *)((u8 *)p + 0x1D8) = 0;
            D_004C2794->h7c[p->b2]++;
            *(u8 *)((u8 *)p + 0x168) = ((p->h140 ^ D_004C2974->b7) != 0) ? 0x10 : 0x11;
            func_001757E0(p, 0x17, *(u8 *)((u8 *)p + 0x168));
        }
    }
}
