typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks 3.0: ./try30.sh src/w20b2_e.c "-O3 -Op -sdatathreshold 0" */
typedef struct { u8 pad[0x34]; f32 f34; f32 f38; } T_e;
typedef struct { s16 x; s16 z; } XZ_e;
extern XZ_e D_004B75C0[];
typedef struct {
    u8 pad0[7]; u8 b7; u8 pad8[0x1C - 8]; s16 h1c; s16 h1e;
    u8 pad20[0x34 - 0x20]; f32 f34; f32 f38;
    u8 pad3c[0x13C - 0x3C]; u8 b13c;
    u8 pad13d[0x220 - 0x13D]; T_e *p220;
    u8 pad224[0x354 - 0x224]; u16 u354;
    u8 pad356[0x539 - 0x356]; s8 b539;
} P_f;

void func_002F9330(P_f *p) {
    extern void func_00185490(P_f *);
    extern void func_001757E0(P_f *, s32, s32);
    s16 t = p->h1c;
    p->h1c = t - 1;
    if (t == 0) {
        if (p->b539 == 0) {
            if (((p->u354 & 0x300) | 0x60) != 0) {
                if (p->u354 & 0x200) p->h1e = 1;
                if (p->u354 & 0x100) p->h1e = 2;
                if (p->u354 & 0x40) p->h1e = 3;
                if (p->u354 & 0x20) p->h1e = 4;
                if (p->u354 & 0x1000) p->h1e = p->h1e + 5;
            }
        }
        { u32 u = p->b7; p->b7 = u + 1; }
        p->f34 = p->p220->f34 + 1.6666666f * D_004B75C0[p->h1e].x;
        p->f38 = p->p220->f38 + 2.142857f * D_004B75C0[p->h1e].z;
        func_00185490(p);
        p->b13c = 1;
        func_001757E0(p, 0x15, 3);
    }
}
