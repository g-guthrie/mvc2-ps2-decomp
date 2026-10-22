typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_001754A0(void *p, s32 a, s32 b);
void func_00198D80(u8 *p) {
    if ((*(u8 **)(p + 0x18))[0x22] == 1) {
        u32 t = p[5];
        p[5] = t + 1;
        if (p[0x22] == 0) func_001754A0(p, 0x1B, 8);
        else func_001754A0(p, 0x1B, 0xB);
    }
}
extern u32 D_00444880[];
extern u32 D_004448A0[];
extern void func_003DF850(s32 a, u32 b);
void func_00153A40(s32 a, s32 b) {
    u32 v = D_00444880[a] | D_004448A0[b];
    func_003DF850(0xD, 0);
    func_003DF850(0x5D, v);
}
void func_00297F90(u8 *p) {
    f32 *v = (f32 *)(p + 0x60);
    f32 *w = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *v += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *v = 0;
        *w = 0;
    }
}
extern void (*D_0044B2F8[])(u8 *, u8 *);
void func_001A4C30(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    if (p[0x23] == 0) {
        if (q[5] != 0 || q[0x1E4] != 0x15 || q[0x1FD] != 2) {
            p[4] = 2;
        }
        D_0044B2F8[p[4]](p, q);
    }
}
void func_001318E0(s32 *out, u32 a, u32 b) {
    s32 i;
    s32 sum;
    s32 w;
    s32 sh;
    s32 sh2;
    s32 j;
    sum = 0;
    i = 2;
    w = 1;
    sh = 8;
    do {
        sum += w * ((b >> sh) & 0xF);
        i++;
        sh += 4;
        w *= 10;
    } while (i < 8);
    j = 0;
    sh2 = 0;
    do {
        sum += w * ((a >> sh2) & 0xF);
        j++;
        sh2 += 4;
        w *= 10;
    } while (j < 8);
    *out = sum;
}
extern s32 func_00175700(void *p);
extern int func_00174470(const void *);
extern s32 func_00350FD0(void *p);
s32 func_00350E40(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (func_00174470(p) == 0) return func_00350FD0(p);
}
void func_00372B60(u8 *p) {
    s16 v = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = v;
    if (v <= 0) {
        *(s16 *)(p + 0x1E) = 1;
        switch (p[0x20]) {
        case 0:
            *(s32 *)(p + 0x48) += 0x800;
            break;
        case 1:
            *(s32 *)(p + 0x48) -= 0x800;
            break;
        case 2:
            *(s32 *)(p + 0x48) -= 0x800;
            break;
        }
    }
}
extern void func_001757E0(void *p, s32 a, s32 b);
void func_0028F930(u8 *p) {
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t = p[7];
        p[7] = t + 1;
        p[0x1E6] ^= 1;
        *(s16 *)(p + 0x140) = p[0x1E6];
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_001757E0(p, 0x12, 2);
    } else {
        func_00175700(p);
    }
}
extern void func_00257740(void *p);
extern void func_00184540(void *p);
void func_00257520(u8 *p) {
    switch (p[0x1FC]) {
    case 2:
        if (*(u16 *)(p + 0x20E) & 0x1000) {
            func_00257740(p);
            return;
        }
        break;
    case 0:
    case 1:
        break;
    }
    {
        s8 r = func_00175700(p);
        if (r < 0) func_00184540(p);
    }
}
extern s32 func_00175700(void *p);
extern void func_0038F4A0(void *p, s32 a, s32 b);
void func_0029F880(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 2) {
        u32 t;
        *(s8 *)(p + 0x151) = 0;
        p[0x28F] = 0;
        p[0x28E] = 0x10;
        if (p[0x1FD] == 0xC) {
            func_0038F4A0(p, 1, 0);
            *(s32 *)(p + 0x308) = 0;
        } else {
            func_0038F4A0(p, 0, 0);
            *(s32 *)(p + 0x308) = 0;
        }
        t = p[6];
        p[6] = t + 1;
    }
}
extern s8 D_004D18D4[];
extern void func_00191210(void *p);
void func_00177C50(u8 *p) {
    p[0x201] = 2;
    if (*(s8 *)(p + 0x205) == 0) {
        if (p[0x425] == 0) {
            s16 h;
            if (D_004D18D4[p[2]] != 1) return;
            h = *(s16 *)(p + 0x1C) - 1;
            *(s16 *)(p + 0x1C) = h;
            if (h > 0) return;
        }
        p[0x268] = 9;
        p[0x26B] = p[0x2B3];
        p[0x2B3] = 0;
        *(s16 *)(p + 0x2B4) = 0x12C;
        func_00191210(p);
    }
}
extern void (*D_00464750[])(u8 *);
extern void func_003859F0(u8 *p);
void func_003850A0(u8 *p) {
    s16 h = *(s16 *)(p + 0x1C);
    u8 *q = *(u8 **)(p + 0x18);
    if (h != 0) *(s16 *)(p + 0x1C) = h - 1;
    if (q[5] != 0 || q[0x1E4] != 0x1D || q[0x1FD] != 0xB || q[0x425] != 0) {
        func_003859F0(p);
    } else {
        D_00464750[p[5]](p);
    }
}
extern void func_001548D0(void *p, f32 *v, s32 a);
extern void func_001E3710(void *p, s32 a);
extern void func_00231490(void *p, void *q);
void func_002315F0(u8 *p, u8 *q) {
    u32 v[4];
    u32 t = p[7];
    p[7] = t + 1;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0xC1092492;
    *(u32 *)(p + 0x6C) = 0xC0092492;
    p[0x20] = 0;
    v[1] = 0x42676DB6;
    v[0] = 0;
    func_001548D0(p, (f32 *)v, 0);
    func_001E3710(p, 0x23);
    func_00231490(p, q);
}
extern void func_001757E0(void *p, s32 a, s32 b);
void func_00316510(u8 *p) {
    u32 t;
    *(u32 *)(p + 0x5C) = 0x41195555;
    *(u32 *)(p + 0x68) = 0xBD555555;
    *(u32 *)(p + 0x60) = 0x413C9249;
    *(u32 *)(p + 0x6C) = 0xBF22DB6D;
    if (*(s16 *)(p + 0x140)) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
    }
    func_001757E0(p, 0xF, 0x13);
    *(s16 *)(p + 0x1C) = 0x20;
    t = p[6];
    p[6] = t + 1;
}
extern u8 D_0043CD60[]; s32 func_0012C0D0(s32 x){ u8 c = (u8)x; s32 i=0; do{ if (c == D_0043CD60[i]) return i>>2; i++;}while(i<32); return -1;}
