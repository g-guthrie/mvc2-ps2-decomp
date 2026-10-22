typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

static void func_00193180(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    f32 f;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
    switch (p[0x20]) {
    case 0:
        f = 0.0f;
        break;
    case 1:
        f = 80.0f;
        break;
    case 2: {
        s16 v = *(s16 *)(p + 0x140) ^ 1;
        f = 80.0f;
        *(s16 *)(p + 0x140) = v;
        break;
    }
    }
    if (*(s16 *)(p + 0x140)) f = -f;
    *(f32 *)(p + 0x34) += f;
}

void func_00193320(u8 *p) {
    extern void func_00193380(u8 *);
    extern void func_00175700(u8 *);
    u8 *q;
    func_00193180(p);
    q = *(u8 **)(p + 0x18);
    if (q[0x169] != 0x16 || q[0x168] != 1) {
        func_00193380(p);
    } else {
        func_00175700(p);
    }
}
