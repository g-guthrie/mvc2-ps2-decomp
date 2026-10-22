typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad[4]; s8 b4; u8 pad5[3]; s16 h8; } S32A;
typedef struct { u8 b0; u8 pad[827]; s8 b828; u8 pad2[635]; } Ent;
extern Ent D_004F20B0[6];
extern u8 D_004F2668[16];
typedef struct { u8 pad[118]; u8 b118; } S2794;
extern S2794 *D_004C2794;
typedef struct { u8 pad[156]; s8 b156; } S2840;
extern S32A *D_004C2840;
extern s32 func_0032A570(void *a);

void func_0032A7F0(void) {
    if (func_0032A570(D_004F20B0)) {
        D_004C2840->b4++;
        D_004C2840->h8 = 60;
    } else if (func_0032A570(D_004F2668)) {
        D_004C2840->b4++;
        D_004C2840->h8 = 60;
    }
}


extern s16 D_004C27A4;
extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern void func_0035EB70(void);

s32 func_0035EAE0(u8 *p) {
    s32 i;
    if (D_004C27A4 < 5) {
        return 0;
    }
    i = 0;
    do {
        u8 *v = func_003DA750(0, 1, 1);
        if (v != 0) {
            *(s16 *)(v + 38) = 3585;
            v[32] = i;
            *(void **)(v + 16) = (void *)func_0035EB70;
            *(u8 **)(v + 24) = p;
        }
        i++;
    } while (i < 4);
    return i;
}

typedef struct { u8 pad[133]; s8 b133; } S2840b;
extern s32 D_00440510[16];
extern void func_0013C110(u8 *p);

void func_0013C3D0(u8 *p) {
    *(s32 *)(p + 68) = *(s32 *)(p + 68) - 256;
    *(s32 *)(p + 68) = *(u16 *)(p + 68);
    if (*(s32 *)(p + 68) <= D_00440510[((S2840b *)D_004C2840)->b133]) {
        u32 t = p[4];
        p[4] = t + 1;
        *(s32 *)(p + 68) = D_00440510[((S2840b *)D_004C2840)->b133];
        func_0013C110(p);
        *(s16 *)(p + 28) = 90;
    }
}

extern void *D_004C2838;
extern void func_001630F0(void);

void func_00163050(V3 *s) {
    u8 *v = func_003DA750(0, 9, 1);
    if (v != 0) {
        v[316] = 1;
        *(void **)(v + 16) = (void *)func_001630F0;
        *(s32 *)(v + 208) = 1049;
        *(f32 *)(v + 80) = 1.0f;
        *(f32 *)(v + 84) = 1.0f;
        *(s16 *)(v + 204) = 31;
        *(void **)(v + 132) = D_004C2838;
        *(V3 *)(v + 52) = *s;
        *(s32 *)(v + 72) = 0;
        *(s32 *)(v + 120) = 0;
        *(s32 *)(v + 124) = 0;
        *(s32 *)(v + 128) = 0;
    }
}

typedef struct { u8 pad[6]; u8 b6; u8 b7; u8 pad2[6]; u8 b14; } S2974;
extern S2974 *D_004C2974;
extern s32 func_00175700();
extern int func_00174470(const void *);
extern void func_00367F60(u8 *p);
extern void func_00367140(u8 *p);

void func_00367010(u8 *p) {
    if (D_004C2974->b14 != 0) {
        D_004C2974->b6 = 1;
        D_004C2974->b7 = *(s8 *)(p + 320) ^ 1;
        func_00367140(p);
    } else {
        u32 t;
        func_00175700(p);
        *(f32 *)(p + 52) += *(f32 *)(p + 92);
        *(f32 *)(p + 92) += *(f32 *)(p + 104);
        if (func_00174470(p) == 0) {
            t = p[4];
            p[4] = t + 1;
            func_00367F60(p);
        }
    }
}
