typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 f[16]; } M16;
typedef struct { s8 type; s8 flag; u16 idx; f32 t; } E148;
typedef struct { u8 pad0[0x14]; u8 *p14; u8 pad18[4]; u8 *p1C; } G148;
typedef struct { u8 pad0[0x4C]; u32 f4c; u8 padx[0x84 - 0x50]; G148 *g; u8 pad88[0xCC - 0x88]; s16 h; u8 padCE[0xE4 - 0xCE]; s32 zero; u8 pad[0x1E4 - 0xE8]; } S148;

typedef struct {
    u8 pad0[0x34];
    u8 b34[0x54];
    u8 b88[0x4C];
    f32 f74, f78, f7c, f80;
} X;

extern G148 *D_004C2804[1];
extern u8 D_00442AA0[];

void func_00148B20(u8 *obj)
{
    extern void func_00416AE0();
    extern void func_004171E0();
    extern void func_00417200();
    extern void func_00416D40();
    extern void func_00416CC0();
    extern void func_00123090();
    extern void func_00416F80();
    extern void func_0011D8F8();
    extern void func_004173C0(f32, f32, f32);
    extern void func_00417170(void *);
    extern f32 func_001519E0(void *);
    extern void func_00417FC0(f32);
    extern void func_00417A50(f32, f32, f32);
    extern void func_00417FD0(f32, void *);
    extern void func_001538B0(void *, s32, void *);
    E148 *e;
    f32 acc;
    M16 m;
    S148 s;
    M16 cur;
    f32 z;

    if (*(s8 *)(obj + 0x13C) != 0 && (e = *(E148 **)(obj + 0xD8)) != 0) {
        func_00416AE0(0);
        func_004171E0();
        func_00417200(obj + 0x34);
        func_00416D40(obj + 0x88);
        func_00416CC0(1);
        func_00123090();
        func_00416AE0(0);
        func_00416F80(obj + 0x88);
        acc = 0.0f;
        for (; e->type >= 0; e++) {
            if (e->type != 0) {
                func_0011D8F8(&s, 0, 0x1E4);
                func_004173C0(acc + e->t, 0.0f, 0.0f);
                if (e->flag != 0) {
                    func_00417170(D_00442AA0);
                    func_00417FC0(func_001519E0(D_00442AA0));
                }
                func_00417A50(*(f32 *)(obj + 0x78), *(f32 *)(obj + 0x7C), *(f32 *)(obj + 0x80));
                func_00417FD0(*(f32 *)(obj + 0x74), D_004C2804[0]->p14 + e->idx * 180);
                func_00416D40(&cur);
                m.f[0] = cur.f[0];
                m.f[1] = cur.f[1];
                m.f[2] = cur.f[2];
                m.f[3] = cur.f[3];
                m.f[4] = cur.f[4];
                m.f[5] = cur.f[5];
                m.f[6] = cur.f[6];
                m.f[7] = cur.f[7];
                m.f[8] = cur.f[8];
                m.f[9] = cur.f[9];
                m.f[10] = cur.f[10];
                m.f[11] = cur.f[11];
                m.f[12] = cur.f[12];
                m.f[13] = cur.f[13];
                m.f[14] = cur.f[14];
                m.f[15] = cur.f[15];
                s.g = D_004C2804[0];
                s.zero = 0;
                s.h = e->idx;
                func_001538B0(&s, *(s32 *)(D_004C2804[0]->p1C + s.h * 4), &m);
                acc = 0.0f;
            } else {
                acc = e->t;
            }
        }
        func_00416CC0(1);
    }
}
