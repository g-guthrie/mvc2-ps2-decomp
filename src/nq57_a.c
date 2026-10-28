typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s16 a, b, c; } E12;
typedef struct { u8 pad[0x1C]; E12 e[8]; } S12;
void func_0012BA70(S12 *p, s32 i, u32 k) {
    extern s32 func_00417A40(void);
    s32 v, b;
    b = 0; v = 0;
    switch (k) {
    case 0: case 2:
        v = func_00417A40() % 0x5DD + 0x1F4;
        b = 0; break;
    case 1: case 3:
        v = func_00417A40() % 0x3E9 + 0x3E8;
        b = 0; break;
    case 4: case 5:
        v = func_00417A40() % 0x5DD + 0x5DC;
        b = 0; break;
    case 6: case 7:
        v = func_00417A40() % 0x7D1 + 0x7D0;
        b = 0; break;
    }
    p->e[i].a = v;
    p->e[i].b = b;
    p->e[i].c = 0;
}
