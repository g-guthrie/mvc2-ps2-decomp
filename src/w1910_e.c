typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x106]; u16 tab[1]; } G_e;
extern G_e *D_004C2840;

void func_002E47A0(u8 *p)
{
    extern void func_001861B0(u8 *);
    extern void func_002E76A0(u8 *);
    extern void func_002E4890(u8 *);
    extern void func_002E4980(u8 *);
    extern void func_002E4A70(u8 *);
    extern void func_002E4B60(u8 *);
    u8 *q = p + 0x2B8;
    func_001861B0(p);
    if (*(s8 *)(q + 9) != 0 && p[0x1FC] == 2) {
        func_002E76A0(p);
        if (D_004C2840->tab[p[2]] != 0) {
            q[0x11] = 1;
        }
        return;
    }
    if (p[0x212] == 0) {
        if (p[0x20D] == 0) {
            func_002E4890(p);
        } else {
            func_002E4980(p);
        }
    } else {
        if (p[0x20D] == 0) {
            func_002E4A70(p);
        } else {
            func_002E4B60(p);
        }
    }
    q[0x11] = 0;
}
