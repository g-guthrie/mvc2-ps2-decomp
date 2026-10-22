typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 *a[3]; } E25b;
typedef struct { u8 pad[0x18]; E25b e[1]; } G25b;
typedef struct { u8 pad[0x14]; s32 f14; } H25b;
extern G25b *D_004C2794;
extern H25b *D_004C2840;

void func_001356F0(u8 *p, s32 flag) {
    extern void func_001E7430(u8 *);
    extern void func_001E7470(u8 *);
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_001358F0();
    u8 *s0;
    s32 i;
    s32 cnt;
    s32 n;
    u8 *o;
    if (D_004C2840->f14 == 0x40) return;
    if ((*(u32 *)(p + 0x428) & 0x7000000) != 0) return;
    n = 1;
    if (flag != 0) {
        n = *(s8 *)(p + 0x26D);
        if (n == 1) flag = 0;
        else n = 3;
    }
    if (flag == 0) {
        func_001E7430(p);
    } else {
        func_001E7470(D_004C2794->e[p[2]].a[0]);
        func_001E7470(D_004C2794->e[p[2]].a[1]);
        func_001E7470(D_004C2794->e[p[2]].a[2]);
    }
    i = 0;
    cnt = 0;
    for (; i < n; i++) {
        s0 = D_004C2794->e[p[2]].a[i];
        if (n != 1 || i != 0) {
            if ((p[0x33D] & (1 << (s0[0x1B8] / 2))) == 0) continue;
        }
        if ((o = func_003DA750(0, 0xE, 1)) != 0) {
            *(void **)(o + 0x10) = func_001358F0;
            *(u8 **)(o + 0x18) = p;
            o[2] = p[2];
            o[1] = s0[1];
            o[0x22] = s0[0x425];
            o[0x1B8] = s0[0x1B8];
            *(u8 **)(o + 0x14) = s0;
            *(s16 *)(o + 0x140) = *(s16 *)(p + 0x140);
            o[0x20] = flag;
            o[0x21] = cnt;
            *(s16 *)(o + 0x26) = 6;
            cnt++;
        }
    }
}
