typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_0044AE00[];

void func_001A2F20(u8 *a, u8 *b) {
    extern s32 func_001748C0(u8 *, u8 *);
    f32 v[4];
    u8 *c;
    u8 *nxt;
    s32 i;
    s32 n;
    u32 k;
    s16 *e;
    f32 px, py, cx, cy;

    a = *(u8 **)(a + 0x14);
    c = b + 0x2B8;
    v[0] = *(f32 *)(b + 0x34) + *(f32 *)(b + 0x2DC);
    v[1] = *(f32 *)(b + 0x38) + *(f32 *)(b + 0x2E0);
    k = (u8)func_001748C0((u8 *)v, a + 0x34);
    if (b[0x1E6] != 0) {
        k = (u8)(0x100 - (s8)k);
    }
    a[0x22] = (u8)((u8)k + 4) >> 3;
    n = *(s16 *)(a + 0x1E);
    i = 1;
    if (n > 1) {
        do {
            nxt = *(u8 **)(a + 8);
            k = (u8)func_001748C0((u8 *)v, a + 0x34);
            if (b[0x1E6] != 0) {
                k = (u8)(0x100 - (s8)k);
            }
            nxt[0x22] = (u8)((u8)k + 4) >> 3;
            if (i == 1) {
                px = 0.0f;
                py = -4.285714149475098f;
            } else {
                e = &D_0044AE00[a[0x22] * 4 + 2];
                px = 1.6666666269302368f * (f32)e[0];
                py = 2.142857074737549f * (f32)e[1];
            }
            cx = 1.6666666269302368f * (f32)D_0044AE00[nxt[0x22] * 4];
            cy = 2.142857074737549f * (f32)D_0044AE00[nxt[0x22] * 4 + 1];
            if (*(s16 *)(nxt + 0x140) != 0) {
                px = -px;
                cx = -cx;
            }
            i++;
            *(f32 *)(nxt + 0x34) = *(f32 *)(a + 0x34) + px - cx;
            *(f32 *)(nxt + 0x38) = *(f32 *)(a + 0x38) + py - cy;
            a = nxt;
        } while (i < n);
    }
    e = &D_0044AE00[a[0x22] * 4 + 2];
    cx = 1.6666666269302368f * (f32)e[0];
    cy = 2.142857074737549f * (f32)e[1];
    if (*(s16 *)(a + 0x140) != 0) {
        cx = -cx;
    }
    *(f32 *)(b + 0x34) = *(f32 *)(a + 0x34) + cx - *(f32 *)(c + 0x24);
    *(f32 *)(b + 0x38) = *(f32 *)(a + 0x38) + cy - *(f32 *)(c + 0x28);
    b[0x22] = a[0x22];
}

void func_001A1C50(u8 *a, u8 *b) {
    extern s32 func_001748C0(u8 *, u8 *);
    f32 v[4];
    u8 *c;
    u8 *nxt;
    s32 i;
    s32 n;
    u32 k;
    s16 *e;
    f32 px, py, cx, cy;

    a = *(u8 **)(a + 0x14);
    c = b + 0x2B8;
    v[0] = *(f32 *)(b + 0x34) + *(f32 *)(b + 0x2DC);
    v[1] = *(f32 *)(b + 0x38) + *(f32 *)(b + 0x2E0);
    k = (u8)func_001748C0((u8 *)v, a + 0x34);
    if (b[0x1E6] != 0) {
        k = (u8)(0x100 - (s8)k);
    }
    a[0x22] = (u8)((u8)k + 4) >> 3;
    n = *(s16 *)(a + 0x1E);
    i = 1;
    if (n > 1) {
        do {
            nxt = *(u8 **)(a + 8);
            k = (u8)func_001748C0((u8 *)v, a + 0x34);
            if (b[0x1E6] != 0) {
                k = (u8)(0x100 - (s8)k);
            }
            nxt[0x22] = (u8)((u8)k + 4) >> 3;
            if (i == 1) {
                px = 0.0f;
                py = 8.571428298950195f;
            } else {
                e = &D_0044AE00[a[0x22] * 4 + 2];
                px = 1.6666666269302368f * (f32)e[0];
                py = 2.142857074737549f * (f32)e[1];
            }
            cx = 1.6666666269302368f * (f32)D_0044AE00[nxt[0x22] * 4];
            cy = 2.142857074737549f * (f32)D_0044AE00[nxt[0x22] * 4 + 1];
            if (*(s16 *)(nxt + 0x140) != 0) {
                px = -px;
                cx = -cx;
            }
            i++;
            *(f32 *)(nxt + 0x34) = *(f32 *)(a + 0x34) + px - cx;
            *(f32 *)(nxt + 0x38) = *(f32 *)(a + 0x38) + py - cy;
            a = nxt;
        } while (i < n);
    }
    e = &D_0044AE00[a[0x22] * 4 + 2];
    cx = 1.6666666269302368f * (f32)e[0];
    cy = 2.142857074737549f * (f32)e[1];
    if (*(s16 *)(a + 0x140) != 0) {
        cx = -cx;
    }
    *(f32 *)(b + 0x34) = *(f32 *)(a + 0x34) + cx - *(f32 *)(c + 0x24);
    *(f32 *)(b + 0x38) = *(f32 *)(a + 0x38) + cy - *(f32 *)(c + 0x28);
    b[0x22] = a[0x22];
}
