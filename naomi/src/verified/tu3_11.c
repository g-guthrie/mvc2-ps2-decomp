/* One function with the literal pool at 0x0c0b1e78. Every compared byte
 * (266/266) matches. Not creditable yet: the retail pool runs to 0x0c0b1ea8 but
 * config/mapping.json leaves the 2-byte alignment pad at 0x0c0b1e82 unmapped,
 * so the tool sizes the section at 266 bytes while the compiled unit is 304. */
struct Obj_tu3_11 {
    unsigned char pad0[7];
    unsigned char b7;
    unsigned char pad1[52 - 8];
    float f52, f56;
    unsigned char pad2[92 - 60];
    float f92, f96;
    unsigned char pad3[104 - 100];
    float f104, f108;
    unsigned char pad4[0x19e - 112];
    unsigned char b19e;
    unsigned char pad5[0x1b0 - 0x19f];
    int l1b0;
    unsigned char pad6[0x1f7 - 0x1b4];
    unsigned char b1f7;
    unsigned char pad7[1];
    unsigned char b1f9;
    unsigned char pad8[0x41c - 0x1fa];
    float f41c;
};

extern void func_0c02a026(struct Obj_tu3_11 *);
extern int func_0c0447bc(struct Obj_tu3_11 *);
extern void func_0c044450(struct Obj_tu3_11 *, int);
extern void func_0c1a4c60(struct Obj_tu3_11 *);
extern void func_0c02a0c4(struct Obj_tu3_11 *, int, int);
extern void func_0c043324(struct Obj_tu3_11 *);

void func_0c0b1d78(struct Obj_tu3_11 *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->b19e) {
        if (func_0c0447bc(a)) {
            a->b7++;
            a->b1f7 = 0xc2;
            func_0c044450(a, a->l1b0);
            func_0c1a4c60(a);
        } else {
            a->b7++;
            a->f92 = -(a->f92 / 8.0f);
            a->f104 = 0.0f;
            a->f96 = 8.5714283f;
            a->f108 = -0.66964281f;
            func_0c02a0c4(a, 21, 22);
        }
    } else {
        if (a->f56 > a->f41c)
            return;
        a->b7 += 2;
        a->f56 = a->f41c;
        a->b1f9 = 0;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        func_0c02a0c4(a, 1, 3);
        func_0c043324(a);
    }
}
