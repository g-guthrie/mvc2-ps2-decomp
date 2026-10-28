typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

/* Real callee (verbatim from src/z2_a.c), so MW sees its register footprint. */
typedef struct { f32 value[3]; } F32Vector3;
typedef struct { F32Vector3 endpoints[2]; } F32VectorPair;
extern F32VectorPair data_f32pair_004B16A0[6];
typedef struct { u8 pad0[0x1C]; s16 s1c; u8 pad1[2]; u8 i20; u8 pad2[0x13]; f32 f34, f38, f3c; } P13D8;
static void func_0013D8E0(P13D8 *p)
{
    F32Vector3 *a = (F32Vector3 *)((u8 *)&data_f32pair_004B16A0 + (p->i20 * 2) * 12);
    F32Vector3 *b = (F32Vector3 *)((u8 *)&data_f32pair_004B16A0 + (p->i20 * 2 + 1) * 12);
    p->f34 = a->value[0] + (f32)p->s1c * ((b->value[0] - a->value[0]) / 30.0f);
    p->f38 = a->value[1] + (f32)p->s1c * ((b->value[1] - a->value[1]) / 30.0f);
    p->f3c = a->value[2] + (f32)p->s1c * ((b->value[2] - a->value[2]) / 30.0f);
}

extern u8 *D_004C2840;
void func_0013DAA0(u8 *p) {
    extern void func_003DAA40();
    u8 *d = D_004C2840;
    s16 v;
    if (*(signed char *)(d + 3) != 2 || *(s16 *)(d + 0xE) == 3) {
        func_003DAA40();
        return;
    }
    v = *(s16 *)(p + 0x1C);
    if (v != 0x1E) {
        *(s16 *)(p + 0x1C) = v + 1;
        func_0013D8E0((P13D8 *)p);
    }
}
