typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

static void func_00141540(V3 *out, V3 *a, V3 *b, f32 s) {
    V3 t;
    t.x = (a->x - b->x) / s;
    t.y = (a->y - b->y) / s;
    t.z = (a->z - b->z) / s;
    *out = t;
}

typedef struct { s16 t; s16 pad; V3 pos; V3 rot; } KF;
typedef struct {
    u8 pad0[0x10]; KF *tbl; u8 pad14[8]; s16 h1C; u8 pad1E[0x32];
    V3 v50; V3 v5C; u8 pad68[0x68]; s32 iD0;
} OB;
typedef struct { u8 pad[0xA]; s16 id; } SC;

extern SC *D_004C2840;
extern OB *D_004C2650;
extern s32 D_004C2648;
extern KF *D_00441370[];
extern f32 D_004CAC90[];
extern f32 D_004CAC94[];
extern f32 D_004CAC98[];
extern f32 D_004CACA0[];
extern f32 D_004CACA4[];
extern f32 D_004CACA8[];

void func_001434A0(void) {
    OB *o = D_004C2650;
    s16 v;
    V3 tmp;
    KF *tbl;
    s32 idx;
    s32 off;
    KF *k;
    KF *e;

    switch (D_004C2840->id) {
    case 0:
        D_004CACA0[0] = 0.0f;
        D_004CAC98[0] = -150.0f;
        D_004CACA4[0] = 0.0f;
        D_004CACA8[0] = 0.0f;
        D_004CAC90[0] = 0.0f;
        D_004CAC94[0] = 0.0f;
        o->v5C.z = 0.0f; o->v5C.y = 0.0f; o->v5C.x = 0.0f;
        o->v50.z = 0.0f; o->v50.y = 0.0f; o->v50.x = 0.0f;
        o->h1C = 300;
        o->iD0 = 0;
        D_004C2648 = 0;
        return;
    case 0x346:
        o->iD0 = 0;
        o->h1C = 1;
        o->tbl = D_00441370[D_004C2648];
        D_004C2648++;
        break;
    case 0x233:
    case 0x41A:
    case 0x6E:
    case 0x1E3:
    case 0x3CA:
    case 0x5BB:
        o->iD0 = 0;
        o->h1C = 1;
        o->tbl = D_00441370[D_004C2648];
        D_004C2648++;
        break;
    case 0x52F:
        D_004CACA0[0] = 0.0f;
        D_004CACA4[0] = -30.0f;
        D_004CACA8[0] = -50.0f;
        D_004CAC94[0] = -30.0f;
        D_004CAC98[0] = -150.0f;
        D_004CAC90[0] = 0.0f;
        o->v5C.z = 0.0f; o->v5C.y = 0.0f; o->v5C.x = 0.0f;
        o->v50.z = 0.0f; o->v50.y = 0.0f; o->v50.x = 0.0f;
        o->h1C = 300;
        return;
    }
    v = o->h1C - 1;
    o->h1C = v;
    if (v == 0) {
        idx = o->iD0;
        e = (KF *)((off = idx * 0x1C) + (u32)(tbl = o->tbl));
        if (e[1].t != -1) {
            o->h1C = e[1].t - e[0].t;
            func_00141540(&tmp, &e[1].pos, &e[0].pos, (f32)o->h1C);
            o->v5C = tmp;
            func_00141540(&tmp, &e[1].rot, &e[0].rot, (f32)o->h1C);
            o->v50 = tmp;
            if (idx == 0) {
                k = (KF *)(off + (u32)tbl);
                D_004CACA0[0] = 10.0f * k->pos.x;
                D_004CACA4[0] = 10.0f * k->pos.y;
                D_004CACA8[0] = 10.0f * k->pos.z;
                D_004CAC90[0] = 10.0f * k->rot.x;
                D_004CAC94[0] = 10.0f * k->rot.y;
                D_004CAC98[0] = 10.0f * k->rot.z;
                o->iD0++;
                return;
            }
            o->iD0++;
        } else {
            o->v5C.z = 0.0f; o->v5C.y = 0.0f; o->v5C.x = 0.0f;
            o->v50.z = 0.0f; o->v50.y = 0.0f; o->v50.x = 0.0f;
            o->h1C = 0xF0;
        }
    }
    D_004CACA0[0] += 10.0f * o->v5C.x;
    D_004CACA4[0] += 10.0f * o->v5C.y;
    D_004CACA8[0] += 10.0f * o->v5C.z;
    D_004CAC90[0] += 10.0f * o->v50.x;
    D_004CAC94[0] += 10.0f * o->v50.y;
    D_004CAC98[0] += 10.0f * o->v50.z;
}
