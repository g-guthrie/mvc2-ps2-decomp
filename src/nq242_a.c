typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    s32 f0;
    s32 x;
    s32 y;
    s32 n;
    s32 addr;
    s32 v[13];
} TX;

typedef struct {
    s32 f0;
    s32 f4;
    u32 f8;
    s32 fc;
    s16 f10;
    s16 f12;
    s32 f14;
    s16 f18;
    s16 f1a;
    s32 f1c;
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2c;
    s32 f30;
    s32 f34;
} E;

static inline void fmt_ov(TX *g, E *e, s32 addr)
{
    g->addr = addr;
    switch (e->f1c) {                                         
    case 0x14:                                                            
        g->v[0] = 0;                                                      
        g->n = g->x / 2;                                                  
        break;                                                            
    case 0x13:                                                            
        g->v[0] = 1;                                                      
        g->n = g->x * g->v[0];                                            
        break;                                                            
    case 2:                                                               
        g->v[0] = 2; g->v[1] = 5; g->v[2] = 10; g->v[3] = 31;             
        g->v[4] = 5; g->v[5] = 5; g->v[6] = 31; g->v[7] = 5;              
        g->v[8] = 0; g->v[9] = 31; g->v[10] = 1; g->v[11] = 15; g->v[12] = 1; 
        g->v[2] = 0; g->v[8] = 10; g->v[4] = 5; g->v[6] = 31;             
        g->n = g->x * g->v[0];                                            
        break;                                                            
    case 1:                                                               
        g->v[0] = 3; g->v[1] = 8; g->v[2] = 16; g->v[3] = 255;            
        g->v[4] = 8; g->v[5] = 8; g->v[6] = 255; g->v[7] = 8;             
        g->v[8] = 0; g->v[9] = 255; g->v[10] = 0; g->v[11] = 0; g->v[12] = 0; 
        g->v[2] = 0; g->v[8] = 16;                                        
        g->n = g->x * g->v[0];                                            
        break;                                                            
    case 0:                                                               
        g->v[0] = 4; g->v[1] = 8; g->v[2] = 16; g->v[3] = 255;            
        g->v[4] = 8; g->v[5] = 8; g->v[6] = 255; g->v[7] = 8;             
        g->v[8] = 0; g->v[9] = 255; g->v[10] = 8; g->v[11] = 24; g->v[12] = 255; 
        g->v[2] = 0; g->v[8] = 16;                                        
        g->n = g->x * g->v[0];                                            
        break;                                                            
    }
}

s32 func_003E96A0(s32 unused, E *e, TX *g, s32 mode)
{
    extern s32 func_003DD030(s32);
    extern u32 func_003DB9C0(u32);
    extern void func_003F5630(s32, s32, s32);
    extern s32 func_003F5E60(TX *, TX *);
    extern void func_003DC190(s32 a, u32 b, s16 c, s16 d, s32 e, s32 f, s32 g, s32 h, s16 i);
    TX a;
    s32 s0;
    s32 s1;
    s32 t;

    e->f34 = mode;
    g->f0 = e->f4;
    g->x = e->f18;
    g->y = e->f1a;
    switch (mode & 3) {
    case 0:
        if (e->f28 == 0) {
            s1 = func_003DB9C0(e->f8 << 1);
            s0 = s1 + e->f8;
            func_003DC190(s1, e->f8, e->f12, e->f18 / 64, *(s16 *)((s32)e + 0x1C), 0, 0, e->f18, e->f1a);
        } else {
            s0 = func_003DB9C0(e->f8);
            s1 = func_003DD030(e->f28);
        }
        e->f30 = s0;
        g->addr = s0;
        a.f0 = g->f0;
        a.x = g->x;
        a.y = g->y;
        a.addr = s1;
        switch (e->f1c) {
        case 0x14:
            g->v[0] = 0;
            g->n = g->x / 2;
            func_003F5630(s0, s1, e->f8);
            break;
        case 0x13:
            g->v[0] = 1;
            g->n = g->x * g->v[0];
            func_003F5630(s0, s1, e->f8);
            break;
        case 2:
            g->v[0] = 2; g->v[1] = 5; g->v[2] = 10; g->v[3] = 31;
            g->v[4] = 5; g->v[5] = 5; g->v[6] = 31; g->v[7] = 5;
            g->v[8] = 0; g->v[9] = 31; g->v[10] = 1; g->v[11] = 15; g->v[12] = 1;
            g->n = g->x * g->v[0];
            a.v[0] = 2; a.v[1] = 5; a.v[2] = 10; a.v[3] = 31;
            a.v[4] = 5; a.v[5] = 5; a.v[6] = 31; a.v[7] = 5;
            a.v[8] = 0; a.v[9] = 31; a.v[10] = 1; a.v[11] = 15; a.v[12] = 1;
            a.v[2] = 0; a.v[8] = 10; a.v[4] = 5; a.v[6] = 31;
            a.n = a.x * a.v[0];
            func_003F5E60(g, &a);
            break;
        case 1:
            g->v[0] = 3; g->v[1] = 8; g->v[2] = 16; g->v[3] = 255;
            g->v[4] = 8; g->v[5] = 8; g->v[6] = 255; g->v[7] = 8;
            g->v[8] = 0; g->v[9] = 255; g->v[10] = 0; g->v[11] = 0; g->v[12] = 0;
            g->n = g->x * g->v[0];
            a.v[0] = 3; a.v[1] = 8; a.v[2] = 16; a.v[3] = 255;
            a.v[4] = 8; a.v[5] = 8; a.v[6] = 255; a.v[7] = 8;
            a.v[8] = 0; a.v[9] = 255; a.v[10] = 0; a.v[11] = 0; a.v[12] = 0;
            a.v[2] = 0; a.v[8] = 16;
            a.n = a.x * a.v[0];
            func_003F5E60(g, &a);
            break;
        case 0:
            g->v[0] = 4; g->v[1] = 8; g->v[2] = 16; g->v[3] = 255;
            g->v[4] = 8; g->v[5] = 8; g->v[6] = 255; g->v[7] = 8;
            g->v[8] = 0; g->v[9] = 255; g->v[10] = 8; g->v[11] = 24; g->v[12] = 255;
            g->n = g->x * g->v[0];
            a.v[0] = 4; a.v[1] = 8; a.v[2] = 16; a.v[3] = 255;
            a.v[4] = 8; a.v[5] = 8; a.v[6] = 255; a.v[7] = 8;
            a.v[8] = 0; a.v[9] = 255; a.v[10] = 8; a.v[11] = 24; a.v[12] = 255;
            a.v[2] = 0; a.v[8] = 16;
            a.n = a.x * a.v[0];
            func_003F5E60(g, &a);
            break;
        }
        break;
    case 1:
        s0 = func_003DB9C0(e->f8);
        if (e->f28 == 0) {
            func_003DC190(s0, e->f8, e->f12, e->f18 / 64, *(s16 *)((s32)e + 0x1C), 0, 0, e->f18, e->f1a);
            e->f30 = s0;
        } else {
            func_003F5630(s0, func_003DD030(e->f28), e->f8);
            e->f30 = s0;
        }
        fmt_ov(g, e, s0);
        break;
    case 2:
        if (e->f28 == 0) {
            t = func_003DB9C0(e->f8);
        } else {
            t = func_003DD030(e->f28);
        }
        e->f30 = t;
        fmt_ov(g, e, t);
        break;
    case 3:
        if (e->f28 == 0) {
            t = func_003DB9C0(e->f8);
        } else {
            t = func_003DD030(e->f28);
        }
        e->f30 = t;
        fmt_ov(g, e, t);
        break;
    }
    g->f0 |= 2;
    return 1;
}
