typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { s16 a, b; } Ej;
extern Ej D_00456BE0[];
typedef struct { u8 pad[0xC]; u8 c; } Sj;
s32 func_0028CD30(u8 *p) {
    extern s32 func_0018AB10();
    extern void func_00419FE0();
    s32 r = 0;
    s16 v = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = v;
    if (v != 0) {
        u32 t;
        Sj *q;
        if (func_0018AB10() == 0) {
            goto end;
        }
        t = p[0x2C4];
        p[0x2C4] = t + 1;
        q = (Sj *)(p + 0x2B8);
        if ((s32)p[0x2C4] <= 0) {
            goto end;
        }
        q->c = 0;
        *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) - 4;
        if (*(s16 *)(p + 0x1E) > 0) {
            goto end;
        }
    }
    do {
        r = D_00456BE0[p[7]].a;
        if (r == -1) {
            break;
        }
        func_00419FE0(p, r & 0xFF);
        *(s16 *)(p + 0x1E) = D_00456BE0[p[7]].b;
        {
            u32 k = p[7];
            p[7] = k + 1;
        }
    } while (*(s16 *)(p + 0x1E) == 0);
end:
    return r;
}

