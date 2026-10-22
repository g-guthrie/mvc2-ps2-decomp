typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad[0x34];
    f32 position;
} State;

static int func_001CB0A0(State *left, State *right) {
    f32 difference = left->position - right->position;
    u8 result = 0;
    if (difference < 0.0f)
        result = 1;
    return result;
}

void func_001CB1A0(u8 *p, u8 *q) {
    extern void func_001CB130(u8 *);
    extern f32 func_001CB150(u8 *);
    extern void func_001CB0D0();
    extern s32 func_001CB5D0(u8 *);
    extern void func_001CB5A0(u8 *, s32, u8);
    f32 x, z;
    s32 neg;
    u8 a2;
    s32 c;
    s16 h;

    z = 0.0f;
    c = p[5];
    if (c == 0) {
        if (*(s16 *)(p + 0x140) != func_001CB0A0((State *)p, (State *)q)) {
            func_001CB130(p);
            return;
        }
        if (*(s8 *)(p + 0x151) != 0) {
            x = func_001CB150(p);
            neg = 0;
            if (x < z) {
                x = -x;
                neg = 1;
            }
            if (x < 26.66666603088379f) {
                func_001CB0D0(p, q);
                goto done;
            }
            p[5] = 2;
            *(s16 *)(p + 0x1C) = 0x160;
            if (neg != 0) x = -x;
            if (*(s16 *)(p + 0x140) != 0) x = -x;
            if (x < z) {
                *(u32 *)(p + 0x5C) = 0xC0D55555;
                a2 = 0x52;
            } else {
                *(u32 *)(p + 0x5C) = 0x40A00000;
                a2 = 0x53;
            }
            if (*(s16 *)(p + 0x140) != 0) *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            func_001CB5A0(p, 0x1B, a2);
        }
        func_001CB5D0(p);
    } else if ((u8)c == 1) {
        if (func_001CB5D0(p) < 0) func_001CB0D0(p, q);
    } else {
        if (*(s16 *)(p + 0x140) != func_001CB0A0((State *)p, (State *)q)) {
            func_001CB130(p);
        } else {
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
            h = *(s16 *)(p + 0x1C) - 1;
            *(s16 *)(p + 0x1C) = h;
            if (h < 0) {
                func_001CB0D0();
            } else {
                x = func_001CB150(p);
                if (x < z) x = -x;
                if (x < 26.66666603088379f) {
                    func_001CB0D0(p, q);
                } else {
                    func_001CB5D0(p);
                }
            }
        }
    }
    done:;
}
