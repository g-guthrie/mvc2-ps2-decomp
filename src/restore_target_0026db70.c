typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { float x, y, z; } V3;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_00178F20(u8 *, u8 *);
extern u8 *func_001B5FA0(void *, u8);

void func_0026DB70(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (*(s8 *)(p + 0x150)) {
        u8 *target;
        V3 saved;

        p[0x150] = 0;
        p[7]++;
        *(s16 *)(p + 0x1C) = 24;
        func_001757E0(p, 15, 3);
        target = *(u8 **)(p + 0x1DC);
        saved = *(V3 *)(target + 0x34);
        func_00178F20(p, target);
        *(float *)(target + 0x5C) = (*(float *)(target + 0x34) - saved.x) / 24.0f;
        *(u32 *)(target + 0x68) = 0;
        *(float *)(target + 0x6C) = -1.0714285373687744f;
        *(float *)(target + 0x60) = (*(float *)(target + 0x38) - saved.y) / 24.0f -
            24.0f * *(float *)(target + 0x6C) / 2.0f;
        *(V3 *)(target + 0x34) = saved;
        func_001B5FA0(p, 2);
    } else {
        func_00175700(p);
    }
}
