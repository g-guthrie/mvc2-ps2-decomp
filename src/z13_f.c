typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u16 *D_004C26DC;

void func_001B8610(u8 *p)
{
    extern void func_001B87B0(u8 *);
    extern int func_00175670(u8 *);
    f32 c, d;
    if (*D_004C26DC != *(u16 *)(*(u8 **)(p + 0x18) + 0x168)) {
        func_001B87B0(p);
        return;
    }
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    if (p[0x1B7] != 0) {
        if (*(s16 *)(p + 0x140) != 0)
            c = 41.666664123535156f;
        else
            c = -41.666664123535156f;
        d = 62.14285659790039f;
        *(f32 *)(p + 0x34) += c;
        *(f32 *)(p + 0x38) += d;
    } else {
        if (*(s16 *)(p + 0x140) != 0)
            c = 60.0f;
        else
            c = -60.0f;
        d = 49.28571319580078f;
        *(f32 *)(p + 0x34) += c;
        *(f32 *)(p + 0x38) += d;
    }
    func_00175670(p);
}

extern s8 D_004C1F80[8];

void func_003B0F10(u8 *p)
{
    extern void func_00175910(u8 *, s32, s32, s32);
    if (p[7] == 0) {
        s32 v;
        p[7]++;
        if (*(s16 *)(p + 0x140) != 0)
            v = 0x10 - p[0x22] / 2;
        else
            v = p[0x22] / 2;
        func_00175910(p, 0x17, 4, v & 0xF);
        *(s16 *)(p + 0x1C) = 0x14;
        *(s16 *)(p + 0x1E) = 7;
    } else {
        s16 h;
        s32 i;
        *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x1C4) + 0x34);
        i = *(s16 *)(p + 0x1E);
        if (i != 0) {
            *(f32 *)(p + 0x34) += (f32)D_004C1F80[(s16)i];
            *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) - 1;
        }
        h = *(s16 *)(p + 0x1C);
        *(s16 *)(p + 0x1C) = h - 1;
        if (h == 0) {
            p[0x13C] = 0;
            p[4] = 3;
        }
    }
}

extern s8 D_004C1F70[8];

void func_003B06C0(u8 *p)
{
    extern void func_00175910(u8 *, s32, s32, s32);
    if (p[7] == 0) {
        s32 v;
        p[7]++;
        if (*(s16 *)(p + 0x140) != 0)
            v = 0x10 - p[0x22] / 2;
        else
            v = p[0x22] / 2;
        func_00175910(p, 0x17, 4, v & 0xF);
        *(s16 *)(p + 0x1C) = 0x14;
        *(s16 *)(p + 0x1E) = 7;
    } else {
        s16 h;
        s32 i;
        *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x1C4) + 0x34);
        i = *(s16 *)(p + 0x1E);
        if (i != 0) {
            *(f32 *)(p + 0x34) += (f32)D_004C1F70[(s16)i];
            *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) - 1;
        }
        h = *(s16 *)(p + 0x1C);
        *(s16 *)(p + 0x1C) = h - 1;
        if (h == 0) {
            p[0x13C] = 0;
            p[4] = 3;
        }
    }
}
