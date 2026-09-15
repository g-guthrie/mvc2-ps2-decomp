typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef float f32;

#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define P(p, o) (*(u8 **)((u8 *)(p) + (o)))

typedef struct {
    f32 x, y, z;
} V3;

typedef struct {
    u8 pad_00[16];
    void *callback;
    u8 pad_14[4];
    void *arg;
} SpawnEntry;

typedef struct {
    u8 pad_00[16];
    void *callback;
    u8 pad_14[4];
    void *arg;
    u8 pad_1c[10];
    u16 event_id;
} EventEntry;

extern s8 func_00175670(u8 *);
extern s8 func_00175700(u8 *);
extern void func_001754A0(u8 *, s32, s32);
extern void func_001757E0(u8 *, s32, s32);
extern void func_001AFC90(u8 *);
extern void func_001E3270(u8 *, s32, f32);
extern void func_001B5350(u8 *, u8 *);
extern void func_001B3E30(u8 *, s32, s32);
extern SpawnEntry *func_003DA750(s32, s32, s32);
extern void func_001BE570(void);
extern void func_001BFB10(void);
extern void func_001B6FA0(void);
extern void func_001B73B0(void);

void func_001A7720(u8 *p) {
    s16 t = S(p, 0x1c);
    S(p, 0x1c) = t - 1;
    if (t == 0) {
        p[0x13c] = 1;
        p[5]++;
    }
}

void func_001A4400(u8 *p, u8 *q) {
    if ((s8)q[0x2b8] >= 0) {
        u8 *r = P(p, 8);
        F(p, 0x60) = F(r, 0x60);
        F(p, 0x34) = F(r, 0x34) - F(p, 0x60);
    } else {
        p[4] = 2;
        p[0x13c] = 0;
    }
}

s32 func_001BBD40(u8 *p) {
    u8 *q = P(p, 0x18);
    if (q[0x169] != 21) {
        return 1;
    }
    if (q[0x1e4] != 21) {
        return 1;
    }
    return q[5] != 0;
}

void func_001B46E0(u8 *p) {
    u8 *q = P(p, 0x18);
    func_00175670(p);
    if ((s8)q[0x151] == 0) {
        p[4] = 2;
    }
}

void func_001BA580(u8 *p) {
    func_001E3270(p, 35, 32.0f);
    p[4]++;
    p[0x13c] = 0;
}

void func_001BE420(u8 *p) {
    SpawnEntry *e = func_003DA750(0, 3, 0);
    if (e) {
        e->callback = func_001BE570;
        e->arg = p;
    }
}

void func_001BFAC0(u8 *p) {
    SpawnEntry *e = func_003DA750(0, 3, 0);
    if (e) {
        e->callback = func_001BFB10;
        e->arg = p;
    }
}

void func_001BFC20(u8 *p) {
    u8 *q = P(p, 0x18);
    if (q[4] >= 2) {
        p[4] = 2;
        p[0x13c] = 0;
        return;
    }
    S(p, 0x140) = S(q, 0x140);
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
}

void func_001AEBC0(u8 *p) {
    if (P(p, 0x18)[0x1e4] != 22) {
        func_001AFC90(p);
    }
}

void func_001AA0D0(u8 *p) {
    if (func_00175700(p) < 0) {
        I(p, 0xd0) = p[6];
        I(p, 0xd4) = p[7];
        p[6] = 2;
        p[7] = 0;
    }
}

void func_001AB110(u8 *p) {
    if (func_00175700(p) < 0) {
        I(p, 0xd0) = p[6];
        I(p, 0xd4) = p[7];
        p[6] = 1;
        p[7] = 0;
    }
}

void func_001B5610(u8 *p) {
    p[6]++;
    func_001754A0(p, 27, p[0x20]);
    p[0x24] = 0;
}

void func_001AAD60(u8 *p) {
    func_00175700(p);
    if ((s8)p[0x151] != 0) {
        p[7]++;
        I(p, 0x60) = 0x40cdb6db;
        I(p, 0x6c) = 0xbf4db6db;
    }
}

void func_001B6F40(u8 *p) {
    EventEntry *e = (EventEntry *)func_003DA750(0, 3, 0);
    if (e) {
        e->callback = func_001B6FA0;
        e->arg = p;
        ((u8 *)e)[1] = p[1];
        e->event_id = 0x1502;
    }
}

void func_001B7350(u8 *p) {
    EventEntry *e = (EventEntry *)func_003DA750(0, 3, 0);
    if (e) {
        e->callback = func_001B73B0;
        e->arg = p;
        ((u8 *)e)[1] = p[1];
        e->event_id = 0x1503;
    }
}

void func_001BDBC0(u8 *p, u8 *q) {
    if ((s8)q[0x150] != 1 || q[0x1e4] != 22) {
        p[4]++;
        p[0x13c] = 0;
    } else {
        S(p, 0x140) = S(q, 0x140);
        F(p, 0x34) = F(q, 0x34);
        F(p, 0x38) = F(q, 0x38);
    }
}

void func_001B4280(u8 *p) {
    u8 *q = P(p, 0x18);
    p[6]++;
    p[0x13c] = 1;
    func_001B5350(q, p);
    func_001754A0(p, 27, p[0x20]);
    p[0x24] = 7;
}

void func_001B4680(u8 *p) {
    u8 *q = P(p, 0x18);
    p[6]++;
    p[0x13c] = 1;
    func_001B5350(q, p);
    func_001754A0(p, 27, p[0x20]);
    p[0x24] = 7;
}

void func_001B4770(u8 *p) {
    u8 *q = P(p, 0x18);
    p[6]++;
    p[0x13c] = 1;
    func_001B5350(q, p);
    func_001754A0(p, 27, p[0x20]);
    p[0x24] = 8;
}

void func_001ABBE0(u8 *p, u8 *q) {
    func_00175700(p);
    if ((s8)q[0x151] == 0) {
        p[7]++;
        func_001757E0(p, 23, 18);
    }
}

void func_001B4DE0(u8 *p) {
    u8 *q = P(p, 0x18);
    if ((s8)func_00175670(p) < 0) {
        p[4] = 2;
        func_001B3E30(q, 21, 11);
    }
}

void func_001B51D0(u8 *p) {
    u8 *q = P(p, 0x18);
    if (*(u16 *)(p + 0xd0) != *(u16 *)(q + 0x168)) {
        p[4] = 2;
        return;
    }
    if ((s8)func_00175670(p) < 0) {
        p[4] = 2;
    }
}
