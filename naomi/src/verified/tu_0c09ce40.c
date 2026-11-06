/* Assembled by tools/clone.py from verified twins. */
struct Obj_ud0_01 {
    unsigned char pad0[6];
    unsigned char b6;
    unsigned char pad1[0x38 - 7];
    float f38;
    unsigned char pad2[0x60 - 0x3c];
    float f60;
    unsigned char pad3[0x6c - 0x64];
    float f6c;
    unsigned char pad4[0x141 - 0x70];
    unsigned char b141;
    unsigned char pad5[0x1a1 - 0x142];
    unsigned char b1a1;
    unsigned char pad6[0x1b4 - 0x1a2];
    struct Obj_ud0_01 *p1b4;
    unsigned char pad7[0x1c8 - 0x1b8];
    struct Obj_ud0_01 *p1c8;
    unsigned char pad8[0x1d2 - 0x1cc];
    unsigned char b1d2;
    unsigned char pad9[0x1ea - 0x1d3];
    unsigned char b1ea;
    unsigned char pad10[0x1f6 - 0x1eb];
    unsigned char b1f6;
    unsigned char b1f7;
    unsigned char pad11[0x41c - 0x1f8];
    float f41c;
};
typedef void (*handler_ud0_01)(struct Obj_ud0_01 *);
extern handler_ud0_01 dat_0c24c0c8[];
extern handler_ud0_01 dat_0c243654[];
extern handler_ud0_01 dat_0c24c0e4[];
extern char func_0c02a026(void *);
extern void func_0c0438de(struct Obj_ud0_01 *);
extern void func_0c03489c(struct Obj_ud0_01 *);
extern void func_0c03f004(struct Obj_ud0_01 *, struct Obj_ud0_01 *);
extern void func_0c03edcc(void *, void *);
struct Rec_ub3_05 { unsigned char pad[28]; int l28; };
struct Obj_ub3_05 {
    unsigned char pad0[5];
    unsigned char b5;
    unsigned char b6;
    unsigned char b7;
    unsigned char pad1[20];
    short s28;
    unsigned char pad2[2];
    unsigned char b32;
    unsigned char pad3[19];
    float f52;
    float f56;
    unsigned char pad4[32];
    float f92;
    float f96;
    unsigned char pad5[4];
    float f104;
    float f108;
    unsigned char pad6[209];
    unsigned char b141;
    unsigned char pad7[144];
    unsigned char b1d2;
    unsigned char pad8[36];
    unsigned char b1f7;
    unsigned char pad9[10];
    unsigned char b202;
};
typedef void (*handler_ub3_05)(struct Obj_ub3_05 *);
extern int func_0c037d54(struct Obj_ub3_05 *);
extern void func_0c044450(struct Obj_ub3_05 *, int);
extern void func_0c02a0c4(void *, int, int);
extern void func_0c0437b8(struct Obj_ub3_05 *);
extern struct Rec_ub3_05 *dat_0c2d6f84;
extern handler_ub3_05 table_0c243668[];
extern handler_ub3_05 table_0c23f694[];
extern handler_ub3_05 table_0c23f69c[];
extern handler_ub3_05 table_0c23f6a4[];
extern handler_ub3_05 table_0c23f6ac[];
extern int func_0c03916c(struct Obj_ub3_05 *);

struct Vec3_ud0_12 { float x, y, z; };
struct Obj_ud0_12 {
    unsigned char pad0[0x34];
    struct Vec3_ud0_12 v34;
    unsigned char pad1[0x1a0 - 0x40];
    unsigned char b1a0;
    unsigned char pad2[0x1c8 - 0x1a1];
    struct Obj_ud0_12 *p1c8;
};
extern void func_0c025900(struct Obj_ud0_12 *, int, int);
extern void func_0c048ce6(struct Obj_ud0_12 *);
extern void func_0c1d4610(struct Obj_ud0_12 *, struct Vec3_ud0_12 *);

void func_0c09ce40(struct Obj_ud0_12 *a)
{
    struct Vec3_ud0_12 position;
    struct Vec3_ud0_12 saved[2];

    func_0c025900(a, 5, 5);
    func_0c048ce6(a);
    a->b1a0 = 10;
    position.x = -126.666664124f;
    position.y = 132.857132f;
    position.z = 0.0f;
    func_0c1d4610(a, &position);
    func_0c02a0c4(a, 15, 1);
    saved[0] = a->v34;
    saved[1] = a->p1c8->v34;
    func_0c03edcc(a, a->p1c8);
    a->v34 = saved[0];
    a->p1c8->v34 = saved[1];
}

void func_0c09ced6(struct Obj_ud0_01 *a)
{
    a->b1ea = 1;
    dat_0c243654[a->b1f7 & 0x3f](a);
}

void func_0c09cef4(struct Obj_ub3_05 *a)
{
    table_0c243668[a->b6](a);
}
