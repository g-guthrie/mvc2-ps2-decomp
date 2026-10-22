typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004D18A0;
extern u8 D_00457260[];

typedef struct { u8 pad0[0x34]; f32 f34; } O_0028A490;
typedef struct { u8 pad0[0x34]; f32 f34; u8 pad1[0x1E6-0x38]; u8 b1e6; u8 pad2[0x220-0x1E7]; O_0028A490 *o; } P_0028A490;
static s32 func_00291800(P_0028A490 *p) {
  u8 b = p->b1e6;
  O_0028A490 *o = p->o;
  if ((b == 0 && p->f34 < o->f34) || (b != 0 && p->f34 > o->f34)) return 1;
  return 0;
}

void func_00292960(u8 *p) {
    extern void func_00294BC0(u8 *);
    extern void func_00294B20(u8 *, u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern s8 func_00175700(u8 *);
    extern u8 func_00292D30(u8 *);
    extern void func_00174A40(u8 *, s32);
    u8 *q;
    u8 r;
    u32 t;
    p[0x40C] = 2;
    q = p + 0x2B8;
    p[0x33C] = 5;
    func_00294BC0(p);
    if (D_004D18A0 >= 5) *(s16 *)(q + 0x1E) = 0;
    if (*(s16 *)(q + 0x1E) == 0) {
        t = p[6];
        p[6] = t + 1;
        p[7] = 0;
        q[0x19] = 0;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        func_00294B20(p, D_00457260);
        func_001757E0(p, 0x16, 0x21);
        return;
    }
    if (q[0x1C] == 0 && func_00291800((P_0028A490 *)p) != 0) {
        q[0x18] = 1;
        p[0x1E6] ^= 1;
        *(s16 *)(p + 0x140) = p[0x1E6];
        q[0x19] = 1;
        func_001757E0(p, 0x16, 0x14);
    }
    if (q[0x18] != 0) {
        if (func_00175700(p) < 0) {
            q[0x18] = 0;
            q[0x19] = 0;
            func_001757E0(p, 0x16, 0x12);
        }
    }
    r = func_00292D30(p);
    if (r != 0xFF) {
        p[0x22] = r;
        func_00174A40(p, 0x2BC);
        { f32 *pf = (f32 *)p; if (pf[0xE] < pf[0x10C]) pf[0xE] = pf[0x10C]; }
    }
}
