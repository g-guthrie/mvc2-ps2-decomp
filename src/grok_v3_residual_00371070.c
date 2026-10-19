typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern int func_00175700(u8 *);
extern s32 func_00119098(f32);
extern void func_001E7F60(u8 *);
extern u8 *D_004C2794;
extern u8 D_004F1F45[];
extern u8 D_004F1F46[];

void residual_00371070(u8 *p)
{
    u8 *parent = *(u8 **)(p + 0x18);
    u8 *other;
    unsigned int offset;

    if (!(parent[0x1E4] == 0x1D && parent[0x1FD] == 5)) {
        p[5] = 1;
        parent[0x23] = 0;
    }
    other = *(u8 **)(p + 0x14);
    if (other[5] == 3) {
        u32 n = p[5];
        p[5] = n + 1;
        parent[0x23] = 0;
    }
    if (*(s16 *)(p + 0x1E) != 0) {
        parent[0x23] = 1;
        *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) - 1;
        return;
    }
    parent[0x23] = 0;
    other = *(u8 **)(p + 0x14);
    if (other[5] == 1)
        func_00175700(p);
    if (*(s16 *)(p + 0x1C) != 0) {
        *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) - 1;
        goto copy;
    }
    if (*(s8 *)(p + 0x1B2) != 0) {
        *(s16 *)(p + 0x1C) = 3;
        *(s16 *)(p + 0x1E) = 6;
        if (*(s16 *)(parent + 0x1E) == 0) {
            if (*(s8 *)(p + 0x1B2) & 1)
                *(u32 *)(p + 0x5C) = 0;
            else if ((*(u8 **)(p + 0x1C4))[0x425] == 0)
                *(u32 *)(p + 0x5C) = 0x3F800000;
        }
        *(s16 *)(parent + 0x1E) = func_00119098(*(f32 *)(p + 0x5C));
        if (p[0x21] < 6) {
            if (p[0x21] == 5) {
                p[0x1B5] = 0x42;
                p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                *(s32 *)(p + 0x1D8) = 0;
                offset = p[2] * 2;
                offset += (unsigned int)D_004C2794;
                ++*(s16 *)(offset + 0x7C);
                D_004F1F45[0] = 2;
                D_004F1F46[0] = 1;
                p[0x21] = 6;
            } else if (*(s8 *)(p + 0x151) == 2) {
                p[0x1B5] = 0x42;
                p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                *(s32 *)(p + 0x1D8) = 0;
                offset = p[2] * 2;
                offset += (unsigned int)D_004C2794;
                ++*(s16 *)(offset + 0x7C);
                D_004F1F45[0] = 2;
                D_004F1F46[0] = 1;
                p[0x21] = 6;
            } else {
                p[0x1B5] = 0x41;
                p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                *(s32 *)(p + 0x1D8) = 0;
                offset = p[2] * 2;
                offset += (unsigned int)D_004C2794;
                ++*(s16 *)(offset + 0x7C);
                p[0x21] = p[0x21] + 1;
            }
        }
    }
    func_001E7F60(p);
copy:
    other = *(u8 **)(p + 0x14);
    *(s16 *)(p + 0x140) = *(s16 *)(other + 0x140);
    other = *(u8 **)(p + 0x14);
    *(f32 *)(p + 0x34) = *(f32 *)(other + 0x34);
    other = *(u8 **)(p + 0x14);
    *(f32 *)(p + 0x38) = *(f32 *)(other + 0x38);
    other = *(u8 **)(p + 0x14);
    *(f32 *)(p + 0x3C) = *(f32 *)(other + 0x3C);
}
