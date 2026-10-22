typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x60]; void (*f60)(u8 *); } VT21;

void func_0017B060(u8 *p) {
    extern s8 func_00175700(u8 *);
    extern s32 func_00184720(u8 *);
    extern s32 func_00185A90(u8 *);
    extern s32 func_001864A0(u8 *);
    extern void func_001865B0(u8 *);
    extern void func_00175C00(u8 *, s32);
    extern void func_00186CE0(u8 *, s32);
    extern void func_001845F0(u8 *);
    extern void func_0018F320(u8 *);
    if (p[1] == 0x25 && p[0x1E5] == 0x20) {
        if (*(u16 *)(p + 0x168) == 0xD1B) {
            if (func_00175700(p) < 0) goto L224;
            (*(VT21 **)(p + 0x43C))->f60(p);
            if (*(s8 *)(p + 0x151) == 0) return;
            p[0x20D] = 0;
            *(s32 *)(p + 0x5C) = 0;
            *(s32 *)(p + 0x60) = 0;
            *(s32 *)(p + 0x68) = 0;
            *(s32 *)(p + 0x6C) = 0;
            if (func_00184720(p) != 0) goto L220;
            if (func_00185A90(p) != 0) goto L220;
            goto L1FC;
        } else {
            if (func_00175700(p) < 0) goto L204;
            (*(VT21 **)(p + 0x43C))->f60(p);
            if (*(s8 *)(p + 0x151) == 0) return;
            p[0x20D] = 2;
            *(s32 *)(p + 0x5C) = 0;
            *(s32 *)(p + 0x60) = 0;
            *(s32 *)(p + 0x68) = 0;
            *(s32 *)(p + 0x6C) = 0;
            if (func_00184720(p) != 0) {
                func_00175C00(p, 1);
                return;
            }
            {
                if (func_00185A90(p) != 0) func_00175C00(p, 1);
            }
            return;
        }
    } else {
        func_0018F320(p);
        if (func_00175700(p) < 0) goto L204;
        if (func_00184720(p) != 0) return;
        if (func_00185A90(p) != 0) return;
        if (func_001864A0(p) == 0) return;
        func_001865B0(p);
    L1FC:
        return;
    }
L204:
    p[5] = 0;
    p[0x1E7] = 1;
    func_001845F0(p);
    return;
L220:
L224:
    func_00175C00(p, 1);
    func_00186CE0(p, 0);
}
