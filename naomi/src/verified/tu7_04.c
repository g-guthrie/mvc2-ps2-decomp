/* Three functions sharing the literal pool at 0x0c1a9c96. All three match
 * retail byte for byte over the whole unit (404 bytes, verified with an
 * extended section), but config/mapping.json has no range for the alignment
 * pad word at 0x0c1a9ca2, so the diff tool's section stops at 0x0c1a9ca2
 * (358 bytes) and the linked size differs. Map that word and the unit is
 * exact. Imports: __slow_mvn=0x0c1fb838, __quick_odd_mvn=0x0c1fb7a0. */
struct V3_tu7_04 { float x, y, z; };
struct Copy_c0_tu7_04 { unsigned char raw[0xc0]; };

struct Obj_tu7_04 {
    unsigned char pad0[1];
    unsigned char b1, b2;
    unsigned char pad1[1];
    unsigned char b4;
    unsigned char pad2[24 - 5];
    struct Obj_tu7_04 *p24;
    short s28;
    unsigned char pad3[36 - 30];
    unsigned char b36;
    unsigned char pad4[48 - 37];
    unsigned char b48;
    unsigned char pad5[52 - 49];
    struct V3_tu7_04 v52;
    unsigned char pad6[80 - 64];
    struct V3_tu7_04 v80;
    float f92, f96, f100;
    struct V3_tu7_04 v104;
    unsigned char pad7[136 - 116];
    float f136;
    unsigned char pad8[0xdc - 140];
    union {
        struct Copy_c0_tu7_04 s0dc;
        struct {
            unsigned char pad9[0x108 - 0xdc];
            float f108;
            unsigned char pad10[0x12c - 0x10c];
            unsigned char b12c;
            unsigned char pad11[0x130 - 0x12d];
            short w130;
        } u;
    } v;
    unsigned char pad12[0x1a3 - 0x19c];
    unsigned char b1a3, b1a4;
};

extern void func_0c029e70(struct Obj_tu7_04 *, int, int);

void func_0c1a9c3a(struct Obj_tu7_04 *a);

void func_0c1a9b3c(struct Obj_tu7_04 *a)
{
    float k;
    a->b4 = a->b4 + 1;
    a->v.s0dc = a->p24->v.s0dc;
    a->v.u.b12c = 1;
    a->b2 = a->p24->b2;
    a->b1 = a->p24->b1;
    a->v80.x = a->p24->v80.x;
    a->v80.y = a->p24->v80.y;
    a->b1a3 = a->p24->b1a3;
    a->b1a4 = a->p24->b1a4;
    a->b48 = a->p24->b48;
    a->v80 = a->p24->v80;
    a->b36 = a->p24->b36;
    a->b36 = 0;
    func_0c029e70(a, 27, 4);
    a->v52 = a->p24->v52;
    k = -40.0f;
    if (a->v.u.w130)
        k = 40.0f;
    a->v52.x += k * a->v80.x;
    a->v52.y += 205.7142791748047f * a->v80.y;
    a->v104 = a->v80;
    a->v80.x *= 0.015f;
    a->v80.y *= 0.015f;
    a->s28 = 30;
    a->f136 = (a->v104.x * 10.0f - a->v80.x) / 30.0f;
    func_0c1a9c3a(a);
}

void func_0c1a9c3a(struct Obj_tu7_04 *a)
{
    a->v80.x += a->f136;
    a->v80.y *= 0.75f;
    a->v.u.f108 -= 0.03333333507180214f;
    if (--a->s28 < 0) {
        a->b4 = a->b4 + 1;
        a->v.u.b12c = 0;
    }
}

void func_0c1a9c82(struct Obj_tu7_04 *a)
{
    a->b4 = a->b4 + 1;
    a->v.u.b12c = 0;
    a->v.u.f108 = 1.0f;
}
