typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G3b;
typedef struct { u8 pad[0x1C]; s16 f1c; s16 f1e; u8 pad2[0x1B2-0x20]; s8 b1b2; } PBb;
extern G3b *D_004C2794;
extern u8 D_004F1F45[];
extern u8 D_004F1F46[];

void func_00371070(u8 *p, u8 *q)
{
    extern void func_00175700(u8 *, u8 *);

    extern void func_001E7F60(u8 *);
    u8 *o = *(u8 **)(p + 0x18);
    u8 *r;
    s16 h;
    s32 v;
    if (o[0x1E4] != 0x1D || o[0x1FD] != 5) {
        p[5] = 1;
        o[0x23] = 0;
    }
    if ((*(u8 **)(p + 0x14))[5] == 3) {
        v = p[5]; p[5] = v + 1;
        o[0x23] = 0;
    }
    if (*(s16 *)(p + 0x1E) != 0) {
        o[0x23] = 1;
        ((PBb *)p)->f1e -= 1;
        return;
    }
    o[0x23] = 0;
    if ((*(u8 **)(p + 0x14))[5] == 1) func_00175700(p, q);
    if ((h = *(s16 *)(p + 0x1C)) != 0) {
        ((PBb *)p)->f1c = h - 1;
    } else {
        if (*(s8 *)(p + 0x1B2) != 0) {
            ((PBb *)p)->f1c = 3;
            *(s16 *)(p + 0x1E) = 6;
            r = *(u8 **)(p + 0x1C4);
            if (*(s16 *)(o + 0x1E) == 0) {
                if (((PBb *)p)->b1b2 & 1) {
                    *(u32 *)(p + 0x5C) = 0;
                } else if (r[0x425] == 0) {
                    *(u32 *)(p + 0x5C) = 0x3F800000;
                }
            }
            *(s16 *)(o + 0x1E) = (u32)*(f32 *)(p + 0x5C);
            v = p[0x21];
            if (v < 6) {
                if (v == 5) {
                    p[0x1B5] = 0x42;
                    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                    *(s32 *)(p + 0x1D8) = 0;
                    D_004C2794->f7c[p[2]]++;
                    D_004F1F45[0] = 2;
                    D_004F1F46[0] = 1;
                    p[0x21] = 6;
                } else if (*(s8 *)(p + 0x151) == 2) {
                    p[0x1B5] = 0x42;
                    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                    *(s32 *)(p + 0x1D8) = 0;
                    D_004C2794->f7c[p[2]]++;
                    D_004F1F45[0] = 2;
                    D_004F1F46[0] = 1;
                    p[0x21] = 6;
                } else {
                    p[0x1B5] = 0x41;
                    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                    *(s32 *)(p + 0x1D8) = 0;
                    D_004C2794->f7c[p[2]]++;
                    v = p[0x21]; p[0x21] = v + 1;
                }
            }
        }
        func_001E7F60(p);
    }
    *(s16 *)(p + 0x140) = *(s16 *)(*(u8 **)(p + 0x14) + 0x140);
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x14) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x14) + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x14) + 0x3C);
}
