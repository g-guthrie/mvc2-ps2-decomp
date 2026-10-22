typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks: ./try.sh src/sa3_d.c "-O3 -sdatathreshold 8" */
typedef struct { u8 pad[0x35E]; u16 h35E; u16 h360; } P_d;
extern u8 func_0018A380(P_d *);
extern u8 func_0018A460(P_d *);

u8 func_00189500(P_d *p, u8 *q, u8 *r) {
    s8 v = r[1] - 1;
    u16 m, t;
    u16 w;
    r[1] = v;
    if (v <= 0) {
        return r[0] = 0;
    }
    t = *(u16 *)((r[2] << 1) + (u32)q + 8);
    m = (p->h35E ^ p->h360) & t;
    if (m != 0) {
        w = *(u16 *)(q + 2);
        if ((w & 0x8000) == 0x8000) {
            if ((m & 0xFFFF) == t) return func_0018A380(p);
            r[0]++;
        } else {
            if ((w & 0x40) == 0x40) return func_0018A460(p);
            return func_0018A380(p);
        }
    }
    return 0;
}
