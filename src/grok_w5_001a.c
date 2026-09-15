typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;

extern s8 func_00175670(u8 *);
extern s8 func_00175700(u8 *);
extern void func_001754A0(u8 *, s32, s32);
extern void func_001757E0(u8 *, s32, s32);
extern u8 *func_003DA750(s32, s32, s32);
extern void func_001AA040(u8 *, u8 *);
extern void func_001A0B80(u8 *);
extern void func_001A44C0(u8 *);
extern void func_001A5600(u8 *);
extern void func_001A6C40(u8 *);
extern void func_001A9700(u8 *);

typedef struct {
    u8 pad_00[16];
    void *callback;
    void *field_14;
    void *arg;
    u8 pad_1c[4];
    u8 b20;
    u8 b21;
    u8 pad_22[4];
    u16 event_id;
} EventEntry;

void func_001A0B20(u8 *p, u8 a1) {
    EventEntry *e = (EventEntry *)func_003DA750(0, 3, 1);
    if (e) {
        e->event_id = 0xC03;
        e->b20 = a1;
        e->callback = func_001A0B80;
        e->arg = p;
    }
}

void func_001A6BE0(u8 *p, u8 a1) {
    EventEntry *e = (EventEntry *)func_003DA750(0, 3, 1);
    if (e) {
        e->event_id = 0xE06;
        e->b20 = a1;
        e->callback = func_001A6C40;
        e->arg = p;
    }
}

void func_001A5590(u8 *p, void *a1, u8 a2) {
    EventEntry *e = (EventEntry *)func_003DA750(0, 3, 0);
    if (e) {
        e->event_id = 0xE04;
        e->b20 = a2;
        e->callback = func_001A5600;
        e->arg = p;
        e->field_14 = a1;
    }
}

void func_001A4450(u8 *p, u8 a1) {
    EventEntry *e = (EventEntry *)func_003DA750(0, 3, 0);
    if (e) {
        e->event_id = 0xE02;
        e->b20 = a1;
        e->b21 = 1;
        e->callback = func_001A44C0;
        e->arg = p;
        e->field_14 = p;
    }
}

void func_001A0C90(u8 *p, u8 *q) {
    func_00175700(p);
    if (q[0x169] != 18 || q[0x168] >= 3 || ((s8)q[0x151] & 2)) {
        p[4] = 2;
        p[0x13c] = 0;
    }
}

void func_001A7FA0(u8 *p, u8 *q) {
    if ((s8)q[0x150] != 0 && q[0x1e4] == 21 && q[0x1fd] == 1) {
        func_00175670(p);
    } else {
        p[4]++;
        p[0x13c] = 0;
    }
}

void func_001A8610(u8 *p, u8 *q) {
    if ((s8)q[0x150] != 0 && q[0x1e4] == 29 && q[0x1fd] == 5) {
        func_00175670(p);
    } else {
        p[4]++;
        p[0x13c] = 0;
    }
}

void func_001A95C0(u8 *p) {
    if (--*(s16 *)(p + 0x1c) == 0) {
        p[5]++;
        func_001754A0(p, 27, 12);
    }
}

void residual_001A9920(u8 *p) {
    p[7]++;
    p[0x13c] = 0;
    p[0] = 0;
    func_001757E0(p, 23, 17);
}

void func_001A9B00(u8 *p, u8 *q) {
    if (func_00175700(p) < 0) {
        *(s32 *)(p + 0xd0) = p[6];
        *(s32 *)(p + 0xd4) = p[7];
        p[6] = 11;
        p[7] = 0;
        func_001AA040(p, q);
    }
}

void func_001A96A0(u8 *p) {
    u8 *slot;
    EventEntry *e;
    slot = p + 0x2b8;
    e = (EventEntry *)func_003DA750(0, 4, 0);
    if (e) {
        e->callback = func_001A9700;
        e->arg = p;
        slot[4] = 1;
        *(void **)slot = e;
    }
}
