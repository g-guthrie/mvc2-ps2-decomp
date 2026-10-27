typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00186A60(void *p, s32 a);
void func_002D5F70(u8 *p) {
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1B7] = 1;
    switch (*(s8 *)(p + 0x4DD)) {
    case 0:
        p[0x1FD] = 1;
        break;
    case 1:
        p[0x1FD] = 3;
        p[0x1B7] = 0;
        break;
    case 2:
        p[0x1FD] = 0xF;
        break;
    }
    func_00186A60(p, 0x15);
}

extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern void func_001E0540(void);
void func_001E04D0(u8 *p, u32 n) {
    u8 *r = func_003DA750(0, 3, 0);
    if (r) {
        *(void **)(r + 0x10) = (void *)func_001E0540;
        r[0x20] = n;
        r[0x21] = 0;
        *(u8 **)(r + 0x18) = p;
        r[1] = (*(u8 **)(p + 0x1C8))[1];
        *(s16 *)(r + 0x26) = 0x3802;
    }
}

extern s32 func_00175700(void *p);
typedef struct { u8 pad[0x2B8]; u8 b[8]; } S371;
void func_00371A90(u8 *p) {
    S371 *q = *(S371 **)(p + 0x18);
    u8 *w;
    func_00175700(p);
    w = q->b;
    if (*((u8 *)q + 5) != 0) {
        p[5] = 2;
        *(s16 *)(p + 0x1C) = 10;
    } else if ((s8)p[0x153] < 0) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
        w[1] = 0;
    }
}

extern void func_001843A0(void *p);
extern void func_001757E0(void *p, s32 a, s32 b);
void func_0024FC10(u8 *p, u8 *q) {
    func_00175700(p);
    if (q[0] == 0) {
        func_001843A0(p);
    } else if (q[3] != 0) {
        u32 t = p[6];
        p[6] = t + 2;
        *(u32 *)(p + 0x60) = 0x41200000;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_001757E0(p, 0x15, 2);
    }
}

extern u8 *func_001940A0(u8 *p);
extern void func_00185960(u8 *p, u8 *a);
extern void func_001266A0(void *p, s32 a, s32 b);
void func_00202EE0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        u32 t = p[6];
        p[6] = t + 1;
    } else if (p[0x15B] != 0) {
        u8 *r;
        p[0x15B] = 0;
        r = func_001940A0(p);
        if (r != 0) {
            func_00185960(p, r);
        } else {
            func_001266A0(p, 0, 0);
            func_001843A0(p);
        }
    }
}

extern u8 D_004D18EC;
extern void func_003266E0(void *p);
void func_00325C00(u8 *p) {
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if ((D_004D18EC & (1 << p[0x1B8])) != 0 || (*(s8 *)(p + 0x211) & (1 << (p[0x1E6] ^ 1))) != 0) {
        func_003266E0(p);
    }
}

extern void func_00185490();
extern s32 func_001879C0(void *p);
void func_00187290(u8 *p) {
    if (*(s8 *)(p + 0x539) != 0) func_00185490(p);
    p[0x20D] = 0;
    p[0x1E7] = 1;
    if (func_001879C0(p) == 0) {
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        if ((*(u32 *)(p + 0x42C) & 4) != 0) {
            (*(void (**)(void *))(*(u8 **)(p + 0x43C) + 0x68))(p);
        } else {
            func_001757E0(p, 2, 1);
        }
    }
}

void func_0021E460(u8 *p) {
    switch (p[0x1FC]) {
    case 0:
        if ((s8)func_00175700(p) < 0) func_001843A0(p);
        break;
    case 1:
    case 2:
        if ((s8)func_00175700(p) < 0) func_001843A0(p);
        break;
    }
}

extern u8 func_0012F6F0(s32 a);
void func_003D4B70(u8 *p) {
    p[4] = func_0012F6F0(0);
    p[5] = func_0012F6F0(1);
    p[6] = func_0012F6F0(2);
    p[7] = func_0012F6F0(3);
    p[0xA] = func_0012F6F0(4);
    p[8] = func_0012F6F0(5);
    p[0xB] = func_0012F6F0(6);
    p[9] = func_0012F6F0(7);
    p[2] = func_0012F6F0(8);
    p[3] = func_0012F6F0(9);
}

extern void func_0015D010(void *p, u32 *v);
extern void func_0018C6E0(void *);
void func_0022B7D0(u8 *p) {
    u32 v[4];
    if (p[0x22] & 1) {
        *(s16 *)(p + 0x140) ^= 1;
        p[0x1E6] ^= 1;
    }
    v[0] = 0xC262AAAA;
    v[1] = 0x43362492;
    func_0015D010(p, v);
    func_001266A0(p, 5, 5);
    p[0x1B4] = 10;
    func_001757E0(p, 0xF, 7);
    func_0018C6E0(p);
}
