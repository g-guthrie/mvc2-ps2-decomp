typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_001266A0(void *, s32, s32);
extern void func_0018C6E0(void *);
extern void func_0015D010(void *, f32 *);
extern void func_00182C30(void *, s32);
extern void func_00182DB0(void *, s32);
extern void func_001757E0(void *, s32, s32);
typedef struct { u8 p0[0x1C]; s16 h1C; s16 h1E; u8 p1[0x194]; u8 b1B4; u8 p2[0x27]; void *w1DC; } S_002C4800;
void func_002C4800(S_002C4800 *p) {
    f32 v[3];
    func_001266A0(p, 5, 5);
    func_0018C6E0(p);
    v[0] = -90.0f;
    v[1] = 162.857131958f;
    func_0015D010(p, v);
    p->b1B4 = 10;
    p->h1C = 0x88;
    p->h1E = 0;
    func_00182C30(p->w1DC, 0x14);
    func_00182DB0(p, 3);
    func_001757E0(p, 0xF, 0);
}

extern s8 D_00475E00[];
extern void func_00175700(void *);
extern void func_001757E0(void *, s32, s32);
typedef struct { u8 p0[0x34]; f32 f34; u8 p1[0x293]; u8 b2CB; } Q_003C45B0;
typedef struct { u8 p0[5]; u8 b5; u8 p1[0x16]; s16 h1C; u8 p2[0x14]; f32 f34; } S_003C45B0;
void func_003C45B0(S_003C45B0 *p, Q_003C45B0 *q) {
    func_00175700(p);
    p->h1C = p->h1C - 1;
    p->h1C = p->h1C & 0x7F;
    p->f34 = q->f34;
    p->f34 += 1.66666662693f * D_00475E00[p->h1C];
    if (q->b2CB != 0) {
        u32 t;
        func_001757E0(p, 0x17, 6);
        t = p->b5;
        p->b5 = t + 1;
    }
}

extern void func_001754A0(void *, s32, s32);
typedef struct { f32 x, y, z; } V3_0019A650;
typedef struct { u8 p0[0x34]; V3_0019A650 v34; u8 p1[0x100]; s16 h140; } Q_0019A650;
typedef struct { u8 p0[0x20]; u8 b20; u8 p1[0x10]; s8 b31; u8 p2[2]; V3_0019A650 v34; u8 p3[0xFC]; u8 b13C; } S_0019A650;
void func_0019A650(S_0019A650 *p, Q_0019A650 *q) {
    p->b13C = 1;
    p->v34 = q->v34;
    if (q->h140 != 0) {
        p->v34.x += 65.0f;
    } else {
        p->v34.x -= 65.0f;
    }
    if (p->b20 == 0) {
        p->v34.y += 190.714279175f;
    } else {
        p->v34.y += 135.0f;
    }
    p->b31 = -1;
    func_001754A0(p, 0x1B, 2);
}

extern int func_00174470(const void *);
extern void func_003CAB00(void *, void *);
typedef struct { u8 p0[0x430]; f32 f430; } Q_003CC4E0;
typedef struct { u8 p0[0x34]; f32 f34; f32 f38; u8 p1[0x20]; f32 f5c; f32 f60; u8 p2[4]; f32 f68; f32 f6c; } S_003CC4E0;
void func_003CC4E0(S_003CC4E0 *p, Q_003CC4E0 *q) {
    f32 lim;
    if (func_00174470(p) == 0) {
        func_003CAB00(p, q);
        return;
    }
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    lim = q->f430;
    if (p->f38 < lim) {
        p->f38 = lim;
        p->f60 = -p->f60 / 4.0f;
    }
}
