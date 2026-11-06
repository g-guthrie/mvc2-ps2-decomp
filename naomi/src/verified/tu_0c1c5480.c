/* Selection cursor glow: spawner, fade states, scrolling texture and cursor clamping (0x0c1c5480-0x0c1c5878). */
#include "objects.h"

struct V3_0c1c5480 { float x, y, z; };

struct Player_0c1c5480 {
    unsigned char pad0[0x524];
    unsigned char b524;
    unsigned char pad525[0x52c - 0x525];
    signed char b52c;
};

struct Slot_0c1c5480 {
    struct Player_0c1c5480 *player;
    unsigned char pad4[0x5a4 - 4];
};

struct Cursor_0c1c5480 {
    unsigned char pad0[24];
    struct Player_0c1c5480 *p24;
    unsigned char pad28[0x524 - 28];
    signed char b524;
};

struct Obj_0c1c5480;
typedef void (*fn_0c1c5480)(struct Obj_0c1c5480 *);

struct Obj_0c1c5480 {
    unsigned char pad0[1];
    unsigned char b1;
    unsigned char pad2[2];
    unsigned char b4;
    unsigned char pad5[16 - 5];
    fn_0c1c5480 p16;
    unsigned char pad20[28 - 20];
    short w28;
    unsigned char pad30[32 - 30];
    unsigned char b32;
    unsigned char b33;
    unsigned char pad34[52 - 34];
    struct V3_0c1c5480 v52;
    int arr64[1];
    int d68;
    int d72;
    unsigned char pad76[80 - 76];
    float f80;
    float f84;
    float f88;
    unsigned char pad92[116 - 92];
    float f116;
    unsigned char pad120[0x84 - 120];
    int d84;
    unsigned char x88[0xc8 - 0x88];
    void *pc8;
    int dcc;
    unsigned char padd0[0x12c - 0xd0];
    unsigned char b12c;
};

struct Glob_0c2d9658 { int (*p0)[1]; };

extern struct Glob_0c2d9658 *dat_0c2d9658;
extern struct Obj_0c1c5480 *dat_0c2fb1b0;
extern struct SelectionFlags59e8 dat_0c2fb158;
extern struct Slot_0c1c5480 dat_0c2d70a0[];
extern unsigned char dat_0c22ff28[][2];
extern unsigned char dat_0c25e074[][8];
extern struct V3_0c1c5480 dat_0c25db44[];
extern fn_0c1c5480 dat_0c25e0b4[];
extern struct Obj_0c1c5480 *func_0c0374da(int, int, int);
extern void func_0c037688(struct Obj_0c1c5480 *);
extern void func_0c1c7960(struct Obj_0c1c5480 *);
extern void func_0c1d91a8(int);
extern void func_0c1d8ff8(int, int);
extern int func_0c1d901e(void);
extern void func_0c1d912a(float *, float *);
extern void func_0c1d917e(float *, float *);
extern void func_0c1ee3b0(int);
extern void func_0c1edc40(void *);
extern void func_0c1eeb60(void);
extern void func_0c1eeb40(struct V3_0c1c5480 *);
extern void func_0c023612(struct V3_0c1c5480 *, struct V3_0c1c5480 *, int);
extern void func_0c1ed4e0(void *);
extern void func_0c1ee360(int);

void func_0c1c553c(struct Obj_0c1c5480 *a);
void func_0c1c559a(struct Obj_0c1c5480 *a);
void func_0c1c5688(struct Obj_0c1c5480 *a);
void func_0c1c56d8(struct Obj_0c1c5480 *a);

void func_0c1c5480(unsigned char side, unsigned char slot)
{
    struct Obj_0c1c5480 *r;

    if ((r = func_0c0374da(0, 5, 1)) != 0) {
        r->b12c = 1;
        r->b32 = side;
        r->b33 = slot;
        r->p16 = func_0c1c553c;
        r->pc8 = dat_0c2fb1b0->x88;
        r->d84 = (*dat_0c2d9658->p0)[side * 2 + 151];
        r->arr64[0] = 0;
        r->d68 = 0;
        r->d72 = 0;
        r->dcc = 0x4830;
        r->f80 = 1.20000005f;
        r->f84 = 1.20000005f;
        r->f88 = 1.20000005f;
        r->f116 = 1.0f;
        r->b1 = 0xff;
        func_0c1d91a8(r->d84);
        if (r->b32)
            r->d72 = -0x2000;
        else
            r->d72 = 0x2000;
        func_0c1c7960(r);
    }
}

void func_0c1c553c(struct Obj_0c1c5480 *a)
{
    dat_0c25e0b4[a->b4](a);
}

void func_0c1c554e(struct Obj_0c1c5480 *a)
{
    a->f80 -= 0.04f;
    a->f84 -= 0.04f;
    a->f88 -= 0.04f;
    if (a->f80 <= 1.0f) {
        a->b4++;
        a->f80 = 1.0f;
        a->f84 = 1.0f;
        a->f88 = 1.0f;
    }
    func_0c1c559a(a);
    func_0c1c5688(a);
}

void func_0c1c559a(struct Obj_0c1c5480 *a)
{
    struct Player_0c1c5480 *p;

    func_0c1c56d8(a);
    if (dat_0c2fb158.flags[a->b32] & (1 << a->b33)) {
        a->b4 = 2;
    } else {
        p = dat_0c2d70a0[a->b32].player;
        if (p->b52c != a->b1) {
            a->b1 = p->b52c;
            dat_0c2fb158.choice[a->b32] = a->b1 + 1;
        }
    }
    func_0c1c5688(a);
}

void func_0c1c5640(struct Obj_0c1c5480 *a)
{
    a->f80 += 0.01f;
    a->f84 += 0.01f;
    a->f116 -= 0.050000001f;
    if (a->f116 <= 0.0f) {
        a->f116 = 0.0f;
        a->b4++;
        a->b12c = 0;
    } else {
        func_0c1c5688(a);
    }
}

void func_0c1c5682(struct Obj_0c1c5480 *a)
{
    func_0c037688(a);
}

void func_0c1c5688(struct Obj_0c1c5480 *a)
{
    func_0c1ee3b0(0);
    func_0c1edc40(a->x88);
    func_0c1eeb60();
    func_0c1eeb40(&a->v52);
    func_0c023612(&a->v52, &dat_0c25db44[a->b1], a->d72);
    func_0c1ed4e0(a->x88);
    func_0c1ee360(1);
}

void func_0c1c56d8(struct Obj_0c1c5480 *a)
{
    float y, x;

    a->w28++;
    if (a->w28 >= 50)
        a->w28 = 0;
    func_0c1d8ff8((&(*dat_0c2d9658->p0)[a->b32 * 2U + 151])[1], a->d84);
    while (!func_0c1d901e()) {
        func_0c1d912a(&x, &y);
        y += a->w28 * 0.02f;
        func_0c1d917e(&x, &y);
    }
}

void func_0c1c57b4(struct Cursor_0c1c5480 *a)
{
    struct Player_0c1c5480 *p = a->p24;

    dat_0c2fb158.cursor_x[a->b524] = dat_0c22ff28[p->b52c][0];
    dat_0c2fb158.cursor_y[a->b524] = dat_0c22ff28[p->b52c][1];
}

void func_0c1c57e8(unsigned char side)
{
    if (dat_0c2fb158.cursor_y[side] >= 8)
        dat_0c2fb158.cursor_y[side] = 0;
    if (dat_0c2fb158.cursor_y[side] < 0)
        dat_0c2fb158.cursor_y[side] = 7;
    if (dat_0c2fb158.cursor_x[side] >= 8)
        dat_0c2fb158.cursor_x[side] = 0;
    if (dat_0c2fb158.cursor_x[side] < 0)
        dat_0c2fb158.cursor_x[side] = 7;
}

unsigned char func_0c1c5848(unsigned char side)
{
    return dat_0c25e074[dat_0c2fb158.cursor_y[side]][dat_0c2fb158.cursor_x[side]];
}
