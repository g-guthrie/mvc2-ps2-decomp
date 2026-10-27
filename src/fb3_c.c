typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad[0x7C]; s16 h7C[1]; } G3CAB20;
extern G3CAB20 *D_004C2794;
extern f32 D_004F1FC8[];
extern f32 D_004F1FCC[];

typedef struct { u8 pad[0x38]; f32 f38; } SP;
#define F32(o) (*(f32 *)(p + (o)))
#define U32(o) (*(u32 *)(p + (o)))
#define S16(o) (*(s16 *)(p + (o)))
#define U16(o) (*(u16 *)(p + (o)))

void func_003CAB20(u8 *p, u8 *q, u32 type) {
    extern u32 func_00174170();
    extern void func_001757E0();
    extern u8 *func_003CA900(u8 *, unsigned int);
    extern void func_001E3210();
    extern void func_001548D0();
    extern void func_003CDB90();
    V3 vv;
    f32 a, b, c;
    u32 r;
    s32 i;
    u8 *o;
    s8 *t;
    u32 w;

    p[7] = 0;
    p[6] = 0;
    switch (type) {
    case 0:
        a = 26.66666603088379f;
        c = D_004F1FC8[0] - a;
        b = 13.333333015441895f;
        if (S16(0x140) == 0) {
            c = a + D_004F1FCC[0];
            b = -b;
        }
        F32(0x34) = c;
        F32(0x38) = *(f32 *)(q + 0x430);
        F32(0x5C) = b;
        U32(0x68) = 0;
        S16(0x1C) = 0x14;
        r = func_00174170();
        p[0x21] = (r % 14) * 2 + 1;
        p[0x1B5] = (p[0x21] >> 1) + 0x30;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        U32(0x1D8) = 0;
        D_004C2794->h7C[p[2]]++;
        func_001757E0(p, 0x17, (u8)(p[0x21] + 2));
        break;
    case 1:
        a = -640.0f;
        b = 13.333333015441895f;
        if (S16(0x140) == 0) {
            a = -a;
            b = -b;
        }
        F32(0x34) = *(f32 *)(q + 0x34) + a;
        F32(0x38) = *(f32 *)(q + 0x430);
        F32(0x5C) = b;
        U32(0x68) = 0;
        p[0x23] = 0;
        S16(0x1C) = 0x258;
        if ((p[0x20] & 3) == 0) S16(0x1E) = 1;
        r = func_00174170();
        i = r % 15;
        for (;;) {
            s8 *cc;
            p[0x21] = i;
            cc = (s8 *)(q + 0x2C8) + i;
            if (*cc > 0) {
                *cc = *cc - 1;
                break;
            }
            i = (p[0x21] + 1) % 15;
        }
        w = p[0x21] + 0x40;
        if (p[0x20] == 0) w = 0x4F;
        p[0x1B5] = w;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        U32(0x1D8) = 0;
        D_004C2794->h7C[p[2]]++;
        U16(0x1C0) |= 0x40;
        w = p[0x21];
        p[0x21] = w << 1;
        func_001757E0(p, 0x17, (u8)(p[0x21] + 2));
        break;
    case 2:
        a = 26.66666603088379f;
        c = D_004F1FC8[0] - a;
        if (S16(0x140) == 0) {
            c = a + D_004F1FCC[0];
        }
        F32(0x34) = c;
        F32(0x38) = *(f32 *)(q + 0x430);
        U32(0x68) = 0;
        r = func_00174170();
        p[0x21] = (r % 13) * 2 + 1;
        p[0x1B5] = 0x55;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        U32(0x1D8) = 0;
        D_004C2794->h7C[p[2]]++;
        func_001757E0(p, 0x17, (u8)(p[0x21] + 2));
        break;
    case 3:
        S16(0x1C) = 0x14;
        S16(0x1E) = 3;
        a = 106.66666412353516f;
        c = D_004F1FC8[0] - a;
        b = 11.666666030883789f;
        if (S16(0x140) == 0) {
            c = a + D_004F1FCC[0];
            b = -b;
        }
        F32(0x34) = c;
        F32(0x38) = 342.85711669921875f + *(f32 *)(q + 0x430);
        F32(0x5C) = b;
        U32(0x68) = 0;
        F32(0x60) = -8.571428298950195f;
        F32(0x6C) = 0.2678571343421936f;
        p[0x1B5] = 0x50;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        U32(0x1D8) = 0;
        D_004C2794->h7C[p[2]]++;
        func_001757E0(p, 0x17, 0x24);
        break;
    case 4:
        S16(0x1C) = 0x14;
        S16(0x1E) = 3;
        a = 26.66666603088379f;
        b = -5.0f;
        if (S16(0x140) != 0) {
            a = -a;
            b = -b;
        }
        F32(0x34) = *(f32 *)(q + 0x34) + a;
        F32(0x38) = 480.0f + *(f32 *)(q + 0x430);
        F32(0x5C) = b;
        U32(0x68) = 0;
        F32(0x60) = -19.28571319580078f;
        F32(0x6C) = 0.5357142686843872f;
        p[0x1B5] = 0x53;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        U32(0x1D8) = 0;
        D_004C2794->h7C[p[2]]++;
        func_001757E0(p, 0x17, 0x24);
        break;
    case 5:
        F32(0x60) = 0;
        F32(0x6C) = -0.8035714030265808f;
        func_001757E0(p, 0x17, 0x2D);
        break;
    case 6:
        S16(0x1C) = 0x14;
        a = 106.66666412353516f;
        c = D_004F1FC8[0] - a;
        b = 15.0f;
        if (S16(0x140) == 0) {
            c = a + D_004F1FCC[0];
            b = -b;
        }
        F32(0x34) = c;
        F32(0x38) = *(f32 *)(q + 0x430);
        F32(0x5C) = b;
        U32(0x68) = 0;
        p[0x1B5] = 0x54;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        U32(0x1D8) = 0;
        D_004C2794->h7C[p[2]]++;
        func_001757E0(p, 0x17, 0x24);
        break;
    case 7:
        p[0x24] = 9;
        a = 53.33333206176758f;
        c = a + D_004F1FCC[0];
        b = -11.666666030883789f;
        if (S16(0x140) != 0) {
            c = D_004F1FC8[0] - a;
            b = -b;
        }
        F32(0x34) = c;
        F32(0x38) = 68.57142639160156f + *(f32 *)(q + 0x430);
        F32(0x5C) = b;
        U32(0x6C) = 0;
        U32(0x60) = 0;
        U32(0x68) = 0;
        p[0x1B5] = 0x51;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        U32(0x1D8) = 0;
        D_004C2794->h7C[p[2]]++;
        U16(0x1C0) |= 0x200;
        func_001757E0(p, 0x17, 0x25);
        o = func_003CA900(q, 0x14);
        if (o != 0) {
            *(u8 **)(o + 0xD8) = p;
            *(f32 *)(o + 0x34) = F32(0x34);
        }
        break;
    case 9:
    case 8:
        if (p[5] != 1 && p[5] != 2 && p[5] != 6 && p[5] != 0x12) func_001E3210(p, 0x27);
        vv.z = 0;
        vv.x = 0;
        vv.y += 17.14285659790039f;
        func_001548D0(p, &vv, 0);
        if (F32(0x38) <= *(f32 *)(q + 0x430)) {
            ((SP *)p)->f38 = *(f32 *)(q + 0x430);
            F32(0x5C) = -F32(0x5C);
            U32(0x68) = 0;
            r = func_00174170() & 7;
            { f32 fr = (f32)r; F32(0x60) = 2.142857074737549f * fr; }
            F32(0x6C) = -0.5357142686843872f;
            func_001757E0(p, 0xD, func_00174170() & 7);
        } else {
            F32(0x5C) = -F32(0x5C) / 4.0f;
            U32(0x68) = 0;
            F32(0x60) = -8.571428298950195f;
            F32(0x6C) = -0.5357142686843872f;
            func_001757E0(p, 0xD, 0xB);
        }
        break;
    case 10:
        a = -10.0f;
        w = S16(0x140);
        b = 26.66666603088379f;
        S16(0x140) = w ^ 1;
        if (S16(0x140) != 0) {
            a = -a;
            b = -b;
        }
        F32(0x34) += b;
        F32(0x5C) = a;
        U32(0x68) = 0;
        func_001757E0(p, 0x17, 0x2C);
        break;
    case 11:
        w = S16(0x140);
        a = -10.0f;
        S16(0x140) = w ^ 1;
        if (S16(0x140) != 0) a = -a;
        F32(0x5C) = a;
        U32(0x68) = 0;
        func_001757E0(p, 0x17, 0x2B);
        break;
    case 12:
        w = S16(0x140);
        a = -10.0f;
        S16(0x140) = w ^ 1;
        if (S16(0x140) != 0) a = -a;
        F32(0x5C) = a;
        U32(0x68) = 0;
        func_001757E0(p, 0x17, 0x2A);
        func_003CDB90(p, 0x10000);
        break;
    case 13:
        F32(0x5C) = -F32(0x5C) / 2.0f;
        U32(0x68) = 0;
        F32(0x6C) = -0.8035714030265808f;
        a = -4.285714149475098f;
        if (F32(0x38) <= *(f32 *)(q + 0x430)) a = 8.571428298950195f;
        F32(0x60) = a;
        func_001757E0(p, 0x17, 0x29);
        break;
    case 14:
        S16(0x1C) = 2;
        func_001757E0(p, 0x17, 0x28);
        break;
    case 15:
        S16(0x1C) = 0x1E;
        func_001757E0(p, 0x17, 0x27);
        break;
    case 16:
        F32(0x38) = *(f32 *)(q + 0x430);
        func_001757E0(p, 0x11, 0);
        break;
    case 17:
        p[7] = 0xB;
        F32(0x60) = 0;
        U32(0x68) = 0;
        F32(0x6C) = -0.8035714030265808f;
        func_001757E0(p, 1, 9);
        break;
    case 18:
        *(s16 *)(q + 0x1E) = *(s16 *)(q + 0x1E) - 1;
        p[7] = 0xA;
        S16(0x1E) = 0x10;
        U32(0x68) = 0;
        U32(0x5C) = 0;
        F32(0x60) = -12.857142448425293f;
        F32(0x6C) = -0.8035714030265808f;
        p[0x1B5] = 0x56;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        U32(0x1D8) = 0;
        D_004C2794->h7C[p[2]]++;
        func_001757E0(p, 0x17, 0x31);
        break;
    case 19:
        p[7] = 0xC;
        F32(0x60) = 0;
        U32(0x68) = 0;
        F32(0x6C) = -0.8035714030265808f;
        func_001757E0(p, 0x17, 0x32);
        func_003CDB90(p, 0);
        break;
    case 20:
        F32(0x38) = *(f32 *)(q + 0x430);
        a = -8.333333015441895f;
        if (S16(0x140) != 0) a = -a;
        F32(0x5C) = a;
        U32(0x68) = 0;
        S16(0x1C) = 0x1E;
        func_001757E0(p, 0x17, 0x2F);
        break;
    case 21:
        S16(0x1C) = 0x78;
        func_001757E0(p, 0x17, 0x30);
        break;
    case 22:
        S16(0x140) ^= 1;
        F32(0x5C) = -F32(0x5C);
        func_001E3210(p, 0x27);
        vv = *(V3 *)(p + 0x34);
        vv.y += 17.14285659790039f;
        func_001548D0(p, &vv, 0);
        break;
    default:
        break;
    }
    p[5] = type;
}
