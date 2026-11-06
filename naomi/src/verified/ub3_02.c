struct Obj_ub3_02 {
    unsigned char pad0[2];
    unsigned char b2;
    unsigned char pad1[3];
    unsigned char b6;
    unsigned char pad2[21];
    short s28;
    short s30;
    unsigned char pad3[24];
    float f56;
    unsigned char pad4[32];
    float f92;
    float f96;
    unsigned char pad5[4];
    float f104;
    float f108;
    unsigned char pad6[302];
    unsigned char b19e;
    unsigned char pad7[2];
    unsigned char b1a1;
    unsigned char pad8[10];
    unsigned short w1ac;
    unsigned char pad9[22];
    int i1c4;
    unsigned char pad10[49];
    unsigned char b1f9;
    unsigned char pad11[91];
    unsigned char b255;
    unsigned char pad12[210];
    unsigned char b328;
    unsigned char pad13[199];
    unsigned char b3f0;
    unsigned char b3f1;
    unsigned char pad14[6];
    unsigned char b3f8;
    unsigned char pad15[35];
    float f41c;
};

struct Tbl_ub3_02 { unsigned char pad[124]; short arr[100]; };

extern struct Tbl_ub3_02 *dat_0c2f83f8;
extern void func_0c0442fa(struct Obj_ub3_02 *);
extern void func_0c0432ca(struct Obj_ub3_02 *);
extern void func_0c02a0c4(struct Obj_ub3_02 *, int, int);
extern char func_0c02a026(struct Obj_ub3_02 *);
extern void func_0c0429a4(struct Obj_ub3_02 *, void *, int);

void func_0c1307d4(struct Obj_ub3_02 *a)
{
    if (a->b255 == 6) {
        a->b3f0 = 0xff;
        a->b3f1 = 16;
    }
    a->b6++;
    func_0c0442fa(a);
    func_0c0432ca(a);
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->s28 = 10;
    a->f56 = a->f41c;
    a->b1f9 = 0;
    a->b1a1 = 85;
    a->w1ac = 0;
    a->b19e = 0;
    a->i1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 22, 16);
}

void func_0c130858(struct Obj_ub3_02 *a)
{
    struct { float x, y, z; } local;

    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = (a->b255 == 6) ? 2 : 0;
    func_0c02a026(a);
    if (--a->s28 <= 0) {
        a->b3f0 = 0;
        a->b3f1 = 0;
        a->b6++;
        a->s28 = 120;
        a->s30 = 10;
        local.x = 0.0f;
        local.y = 55.714283f;
        func_0c0429a4(a, &local, 1);
    }
}
