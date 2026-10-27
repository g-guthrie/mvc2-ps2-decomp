typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern f32 D_004643BC[];
extern f32 D_004F1FD0;
extern u8 *D_004C2794;
extern void (*D_00455458[])(u8 *);
extern void (*D_00463DB0[])(u8 *, u8 *, u8 *);

void func_0034AD90(u8 *p, u8 *q) {
    extern int func_00175700(u8 *);
    extern void func_001757E0();
    extern void func_00198170();
    extern void func_0034B040();
    s8 c;
    s8 r = func_00175700(p);
    if (r < 0) {
        u32 t = p[5];
        p[5] = t + 1;
        *(s16 *)(p + 0x1C) = 5;
        *(s16 *)(p + 0x1E) = 5;
        func_001757E0(p, 0x16, 0x17);
    } else if ((c = *(s8 *)(p + 0x151)) != 0) {
        if (c == 0x42) {
            p[0x151] = 0;
            func_00198170(p, 1);
        }
        p[0x151] = 0;
        func_0034B040(p, q);
    }
}


typedef struct { u8 p0[0x20]; u8 a, b; u8 pad[0x2E]; f32 f50, f54; u8 pad2[0xC]; f32 f64; u8 pad3[8]; f32 f70; } S_80A90;
void func_00380A90(S_80A90 *p) {
    s32 t;
    if (p->a != 0) {
        { f32 m = D_004643BC[p->a]; p->f50 = p->f64 * m; }
        t = p->a;
        p->a = t + 1;
        if ((t + 1 & 0xFF) > 0x1E) {
            p->a = 0;
            p->f50 = p->f64;
        }
    }
    if (p->b != 0) {
        { f32 m = D_004643BC[p->b]; p->f54 = p->f70 * m; }
        t = p->b;
        p->b = t + 1;
        if ((t + 1 & 0xFF) > 0x1E) {
            p->b = 0;
            p->f54 = p->f70;
        }
    }
}

extern u32 D_004F1CC0, D_004F1CC4, D_004F1CC8, D_004F1CCC, D_004F1CD0;
void func_003298E0(void) {
    u32 a1, x;
    if (D_004F1CC0 != 0) {
        if (D_004F1CCC != 0) D_004F1CCC--;
        a1 = D_004F1CCC;
        if (a1 == 0 && D_004F1CC4 == 0) {
            D_004F1CC0 = 0;
            return;
        }
        if (D_004F1CC4 == 0) {
            x = (a1 * 255) / D_004F1CD0;
        } else {
            x = ((D_004F1CD0 - a1) * 255) / D_004F1CD0;
        }
        D_004F1CC8 = D_004F1CC8 & 0xFFFFFF;
        D_004F1CC8 |= (x & 0xFF) << 24;
    }
}
