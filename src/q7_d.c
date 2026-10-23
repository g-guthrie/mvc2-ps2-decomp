typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_001B3D90(u8 *q, u8 *p);
extern s32 func_00175670(void *p);

typedef struct {
    u8 pad[0x1C];
    s16 timer;
} TimerActor;

static void func_00396F90(TimerActor *p, s8 *q) {
    s16 t = p->timer - 1;
    p->timer = t;
    if (t <= 0) {
        p->timer = 2;
        *q = *q - 1;
    }
}

void func_00397250(u8 *a, u8 *b, s8 *c) {
    if (b[0x169] != 0x16) {
        u32 t = a[4];
        a[4] = t + 1;
        a[0x13C] = 0;
    } else {
        c[7] = 0;
        func_00396F90((TimerActor *)a, c);
        if (c[0] < 0) {
            u32 t = a[4];
            a[4] = t + 1;
        }
    }
}


s32 func_001B3980(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    if (*(u16 *)(p + 0xD0) != *(u16 *)(q + 0x168)) {
        p[6] = 0;
        p[5] = 0;
        p[4] = 0;
        p[0x13C] = 0;
    } else {
        s8 m;
        func_001B3D90(q, p);
        p[0x24] = 0;
        m = q[0x151];
        if (m == 2) {
        } else if (m != 1) {
            u32 t = p[6];
            p[6] = t + 1;
            p[0x13C] = 0;
        } else {
            if (*(s8 *)(q + 0x1B4) == 0) {
                return func_00175670(p);
            }
        }
    }
}
