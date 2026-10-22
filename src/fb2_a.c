typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 v; u8 pad[24]; } E28;
extern E28 D_0045F058[], D_0045F05C[], D_0045F060[];
extern E28 D_0045F070[], D_0045F074[], D_0045F078[], D_0045F07C[];
extern E28 D_0045F08C[], D_0045F090[], D_0045F094[], D_0045F098[];

void func_0033D6E0(u8 *p)
{
    extern void func_0032FEB0(f32, f32 *, f32 *, f32 *);
    f32 vx, vy, vz;
    s16 i;

    switch (p[4]) {
    case 0:
        func_0032FEB0((f32)*(s16 *)(p + 0x1C) / (D_0045F08C[*(s16 *)(p + 0x1E)].v - D_0045F070[*(s16 *)(p + 0x1E)].v), &vx, &vy, &vz);
        i = *(s16 *)(p + 0x1E);
        *(f32 *)(p + 0x34) = vx * D_0045F058[i].v + vy * D_0045F074[i].v + vz * D_0045F090[i].v;
        *(f32 *)(p + 0x38) = vx * D_0045F05C[i].v + vy * D_0045F078[i].v + vz * D_0045F094[i].v;
        *(f32 *)(p + 0x3C) = vx * D_0045F060[i].v + vy * D_0045F07C[i].v + vz * D_0045F098[i].v;
        i = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = i;
        if ((f32)*(s16 *)(p + 0x1C) < D_0045F08C[*(s16 *)(p + 0x1E)].v - D_0045F070[*(s16 *)(p + 0x1E)].v) {
            break;
        }
        *(s16 *)(p + 0x1C) = 0;
        i = *(s16 *)(p + 0x1E) + 1;
        *(s16 *)(p + 0x1E) = i;
        if ((u32)(*(s16 *)(p + 0x1E) + 1) >= 4) {
            *(s16 *)(p + 0x1E) = 1;
        }
        break;
    case 1:
        break;
    }
}
