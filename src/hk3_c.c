typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x34]; f32 f34; f32 f38; } HK3D_S;

int func_00174170(void);

void func_001B5CD0(u8 *a0) {
    u8 *a2;
    s32 a1;
    HK3D_S *s0;
    f32 c1 = 0.4166666567325592f;
    f32 c2 = 0.5357142686843872f;
    s32 r;

    *(s8 *)(a0 + 0x13C) = 0;
    a2 = *(u8 **)(a0 + 0x18);
    a1 = *(s8 *)(a2 + 0x151);
    if (a1 == 2) {
        a0[4] = 2;
        return;
    }
    if (a1 != 3) {
        return;
    }
    s0 = *(HK3D_S **)(a2 + 0x1DC);
    r = func_00174170() & 3;
    switch (r) {
    case 0:
        s0->f34 = s0->f34 + c1;
        s0->f38 = s0->f38 + c2;
        break;
    case 1:
        s0->f34 = s0->f34 - c1;
        s0->f38 = s0->f38 - c2;
        break;
    case 2:
        s0->f34 = s0->f34 - c1;
        s0->f38 = s0->f38 + c2;
        break;
    case 3:
        s0->f34 = s0->f34 + c1;
        s0->f38 = s0->f38 - c2;
        break;
    }
}
