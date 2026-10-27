typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern s8 func_00175700();
extern void func_001757E0();
extern void func_00126400();
extern void func_003266E0();
void func_00325A70(u8 *p) {
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (func_00175700(p) < 0) {
        func_00126400();
        func_003266E0(p);
    } else if (*(s8 *)(p + 0x150)) {
        p[0x150] = 0;
        if (*(s16 *)(p + 0x1C) > 0) func_001757E0(p, 0x16, 0x17);
    }
}

extern void func_002FA200(u8 *);
extern void func_001843A0();
void func_002F8070(u8 *p) {
    if (p[0x2CE]) {
        func_002FA200(p);
    } else {
        switch (p[0x1FC]) {
        case 0:
        case 1:
        case 2:
            if (func_00175700(p) < 0) func_001843A0(p);
            break;
        }
    }
}

void func_002B6BC0(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) - 1;
    if (*(s16 *)(p + 0x1C) <= 0) {
        u32 t = p[6];
        p[6] = t + 1;
        if (*(s16 *)(p + 0x140)) {
            func_001757E0(p, 0x15, 0x24);
        } else {
            func_001757E0(p, 0x15, 0x23);
        }
    }
}

extern void func_0018C6E0(void *);
extern void func_0015D010();
void func_002FB4E0(u8 *p) {
    struct { u32 a, b, c; } v;
    if (p[0x22] & 1) {
        u32 t = p[0x1E6];
        p[0x1E6] = t ^ 1;
        *(s16 *)(p + 0x140) = p[0x1E6];
    }
    p[0x1B4] = 10;
    func_0018C6E0(p);
    func_001757E0(p, 0xF, 0);
    v.a = 0xC2AA0000;
    v.b = 0x42564924;
    v.c = 0;
    func_0015D010(p, &v);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
}
