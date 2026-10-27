typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 *D_004C2840;
extern void func_003DA2A0();
extern void func_00122840(s32 a);
extern void func_003C8650();
extern int func_00175700(u8 *);
extern u8 *D_004C25D4;
extern u8 *D_004C25D0;
extern u8 D_004F1F41[];
extern u8 D_004F1F42[];
extern s32 func_00174170();
extern void func_001757E0(void *p, s32 a, s32 b);
extern u8 D_004BFB50[8];
extern u8 D_004BFB48[8];
extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern void func_001BA660();
extern s16 *D_004C26F4;

void func_003DA220(void) {
    D_004C2840[3]++;
    D_004C2840[4] = 0;
    D_004C2840[5] = 0;
    D_004C2840[6] = 0;
    D_004C2840[7] = 0;
    D_004C2840[0x19] = 1;
    if (D_004C2840[0x4C] != 5) {
        func_003DA2A0();
    }
    func_00122840(-1);
}

void func_003C8660(s8 *p, s8 *q) {
    if ((u8)q[5] != 0 || (u8)q[0x1E4] != 0x1D) {
        func_003C8650();
    } else {
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
        p[0x24] = q[0x24];
        p[0x31] = p[0x1E];
        if (*(u8 *)(q + 0x15B)) {
            func_00175700((u8 *)p);
        }
    }
}

void func_00126400(void) {
    if (D_004C25D4[1] == 0x1A) {
        D_004F1F41[0] = 4;
        D_004F1F42[0] = 4;
    } else if (D_004C25D0[1] == 0x1A) {
        D_004F1F41[0] = 3;
        D_004F1F42[0] = 3;
    } else {
        D_004F1F41[0] = 0;
        D_004F1F42[0] = 0;
    }
}

void func_001EADD0(u8 *p) {
    u32 t = p[6];
    s32 c;
    p[6] = t + 1;
    c = D_004BFB50[p[0x20]];
    if (p[0x20] == 0) {
        c = D_004BFB48[func_00174170() & 7];
    }
    func_001757E0(p, 0x13, c);
}

u8 *func_001BA5D0(u8 *p, u8 n) {
    u8 *v = func_003DA750(0, 3, 0);
    if (v) {
        *(void (**)())(v + 0x10) = func_001BA660;
        *(u8 **)(v + 0x18) = p;
        *(s16 *)(v + 0x140) = *(s16 *)(*(u8 **)(v + 0x18) + 0x140);
        *(s16 *)(v + 0x26) = 0x1700;
        D_004C26F4 = (s16 *)(v + 0xD0);
        *D_004C26F4 = *(u16 *)(*(u8 **)(v + 0x18) + 0x168);
        v[0x23] = n;
        return v;
    }
    return 0;
}

extern void func_00175670();
void func_001BCD70(u8 *p, u8 *q) {
    func_00175670(p, q);
    if (q[0x1E4]) {
        u32 t;
        *(u32 *)(p + 0x64) = 0x3D4CCCCD;
        t = p[5];
        p[5] = t + 1;
        return;
    }
    {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) {
            u32 t;
            *(u32 *)(p + 0x64) = 0x3C4CCCCD;
            t = p[5];
            p[5] = t + 1;
            return;
        }
    }
}

extern s8 D_004C26CC;
u16 func_00191920(u8 a, u8 b) {
    u16 lo = (b & 0xF) + ((D_004C26CC & 1) + (a & 0xF));
    u16 sum;
    if (lo > 9) {
        lo -= 10;
        lo |= 0x10;
    }
    sum = (b & 0xF0) + ((s16)lo + (a & 0xF0));
    {
        u16 r = sum;
        if (r > 0x99) {
            r = (u8)(r - 0xA0);
            D_004C26CC = 1;
        } else {
            D_004C26CC = 0;
        }
        return r;
    }
}
