typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G19a;
extern G19a *D_004C2794;

static void func_0026DF70(u8 *p) {
    s32 a = *(s8 *)(p + 0x2BD);
    u8 *q = p + 0x2B8;
    if (a >= 0) {
        u32 b = *(u16 *)(p + 0x35C);
        if (b & 0x300) {
            if (p[0x1B7]) {
                if (b & 0x100) q[5] = a + 1;
            } else {
                if (b & 0x200) q[5] = a + 1;
            }
            if (*(s8 *)(q + 5) >= 5) q[5] = 5;
        }
    }
}

void func_0026E2A0(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_001757E0();
    u8 *q;
    s32 t;
    q = p + 0x2B8;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    p[0x209] = 3;
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) - 1;
    t = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = t;
    if ((s16)t < 0) {
        p[7] = 3;
        return;
    }
    func_0026DF70(p);
    if (*(s8 *)(q + 5) >= 2 && *(s8 *)(q + 6) == 0) {
        q[6] = 1;
        func_001757E0(p, 0x15, (u8)(p[0x1B7] + 0x12));
    } else if (p[0x15B] != 0) {
        p[0x1B5] = *(s8 *)(p + 0x1B7) + 0x32;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        p[0x15B] = 0;
    }
    if (*(f32 *)(p + 0x60) < 0.0f) {
        p[7] = 2;
        func_001757E0(p, 0x15, 2);
        p[0x1B5] = *(s8 *)(p + 0x1B7) + 0x42;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
    }
}
