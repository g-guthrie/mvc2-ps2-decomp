typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
typedef signed int s32;

typedef struct { u8 pad[0x7C]; s16 f7c[8]; } GA;
extern GA *D_004C2794;
typedef struct {
    u8 pad[0x1B7];
    u8 special;
    u8 gap[0x124];
    int countdown;
} Owner;


static void func_00379960(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    u8 c;
    if (p[0x23] % 2 == 0) {
        p[0x1B0] = 0x42;
        p[0x1B1] = 0x42;
    } else {
        p[0x1B0] = 0;
        p[0x1B1] = 0;
    }
    if (q[0x1B7] != 0) {
        c = ((p[0x23] / 2) % 2 == 1) ? 0x44 : 0x45;
    } else {
        c = ((p[0x23] / 2) % 2 == 1) ? 0x30 : 0x38;
    }
    p[0x1B5] = c;
    p[0x1b2] = *(u16 *)(p + 0x1c0) = 0;
    *(s32 *)(p + 0x1d8) = 0;
    D_004C2794->f7c[p[2]]++;
}

static void func_00379A60(u8 *p)
{
    Owner *owner = *(Owner **)(p + 0x18);
    u8 *state = p + 0xD0;
    u8 animation;
    if (*(s8 *)(p + 0x1B2)) {
        *(s16 *)(state + 4) = 1;
        owner->countdown = 8;
    }
    if (!p[0x23] && owner->countdown)
        --owner->countdown;
    if (owner->countdown) {
        p[0x1B0] = 0;
        p[0x1B1] = 0;

        if (owner->special) {
            animation = (u8)(((int)p[0x23] / 2) % 2 == 1 ? 0x44 : 0x45);
        } else {
            animation = (u8)(((int)p[0x23] / 2) % 2 == 1 ? 0x30 : 0x38);
        }
        p[0x1B5] = animation;
        *(s8 *)(p + 0x1B2) = *(u16 *)(p + 0x1C0) = 0;
        *(int *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
    } else {
        if ((int)p[0x23] % 2 == 0) {
            p[0x1B0] = 0x42;
            p[0x1B1] = 0x42;
        } else {
            p[0x1B0] = 0;
            p[0x1B1] = 0;
        }

        if (owner->special) {
            animation = (u8)(((int)p[0x23] / 2) % 2 == 1 ? 0x44 : 0x45);
        } else {
            animation = (u8)(((int)p[0x23] / 2) % 2 == 1 ? 0x30 : 0x38);
        }
        p[0x1B5] = animation;
        *(s8 *)(p + 0x1B2) = *(u16 *)(p + 0x1C0) = 0;
        *(int *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
    }
}

typedef struct { f32 x, y, z; } V3;
typedef struct { u16 h0, h2, h4, h6, h8; } ST;
typedef struct {
    u8 pad0[1];
    u8 b1;
    u8 pad2[0x24 - 2];
    u8 b24;
} Pdummy;

typedef struct {
    u8 unknown00[0x34];
    float x;
    u8 unknown38[0x108];
    s16 facing;
} HorizontalBoundsActor;
extern float D_004F1FD8 __attribute__((section(".bss")));
extern float D_004F1FDC __attribute__((section(".bss")));

static int func_003797D0(u8 *actor_data)
{
    HorizontalBoundsActor *actor = (HorizontalBoundsActor *)actor_data;
    if (actor->facing == 0) {
        if (!(D_004F1FD8 - 146.666656494140625f <= actor->x))
            return 1;
    } else {
        if (146.666656494140625f + D_004F1FDC < actor->x)
            return 1;
    }
    return 0;
}

void func_00379FA0(u8 *p)
{
    extern void func_0037A800(u8 *);
    extern void func_0037A1D0(u8 *);
    extern int func_00175700(u8 *);
    extern void func_001E7F60(u8 *);
    u8 *q = *(u8 **)(p + 0x18);
    ST *st;
    u32 t;
    f32 c;
    s32 v;
    st = (ST *)(p + 0xD0);
    p[0x24] = *(s8 *)(q + 0x24);
    t = *(u16 *)(p + 0xD6);
    if (t != 0) {
        st->h6 = t - 1;
    } else if (st->h8 == 0) {
        st->h8 = 1;
        func_00379960(p);
    } else {
        func_00379A60(p);
    }
    *(V3 *)(p + 0x34) = *(V3 *)(*(u8 **)(p + 0x18) + 0x34);
    if (q[0x20D] == 2) {
        c = *(s16 *)(p + 0x140) ? 143.0f : -143.0f;
        *(f32 *)(p + 0x34) += c;
        *(f32 *)(p + 0x38) += 187.0f;
    } else {
        c = *(s16 *)(p + 0x140) ? 130.0f : -130.0f;
        *(f32 *)(p + 0x34) += c;
        *(f32 *)(p + 0x38) += 136.0f;
    }
    *(f32 *)(p + 0x64) = *(f32 *)(p + 0x34);
    if (*(s16 *)(p + 0x140) != 0) {
        v = p[0x23] * 40;
    } else {
        v = -(p[0x23] * 40);
    }
    *(f32 *)(p + 0x34) += (f32)v;
    *(f32 *)(p + 0x70) = *(f32 *)(p + 0x38);
    if (p[1] != (*(u8 **)(p + 0x18))[1]) {
        func_0037A800(p);
        return;
    }
    if (st->h0 != *(u16 *)(*(u8 **)(p + 0x18) + 0x168)) {
        p[4] = 2;
        p[0x13C] = 0;
    }
    if (p[0x23] % 2 == 0) {
        if (func_003797D0(p) == 0 && *(s8 *)(p + 0x1B2) == 0) {
            func_001E7F60(p);
        }
    }
    if (func_003797D0(p) == 0) {
        p[0x13C] = 1;
    } else {
        p[0x13C] = 0;
    }
    func_0037A1D0(p);
    func_00175700(p);
}
