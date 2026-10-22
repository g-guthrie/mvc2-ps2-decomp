typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 v; u8 pad[24]; } E28;
extern E28 D_0045F0C8[], D_0045F0CC[], D_0045F0D0[];
extern E28 D_0045F0E0[], D_0045F0E4[], D_0045F0E8[], D_0045F0EC[];
extern E28 D_0045F0FC[], D_0045F100[], D_0045F104[], D_0045F108[];

void func_0033DC60(u8 *p)
{
    extern void func_0032FEB0(f32, f32 *, f32 *, f32 *);
    f32 vx, vy, vz;
    s16 i;

    switch (p[4]) {
    case 0:
        func_0032FEB0((f32)*(s16 *)(p + 0x1C) / (D_0045F0FC[*(s16 *)(p + 0x1E)].v - D_0045F0E0[*(s16 *)(p + 0x1E)].v), &vx, &vy, &vz);
        i = *(s16 *)(p + 0x1E);
        *(f32 *)(p + 0x34) = vx * D_0045F0C8[i].v + vy * D_0045F0E4[i].v + vz * D_0045F100[i].v;
        *(f32 *)(p + 0x38) = vx * D_0045F0CC[i].v + vy * D_0045F0E8[i].v + vz * D_0045F104[i].v;
        *(f32 *)(p + 0x3C) = vx * D_0045F0D0[i].v + vy * D_0045F0EC[i].v + vz * D_0045F108[i].v;
        i = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = i;
        if ((f32)*(s16 *)(p + 0x1C) < D_0045F0FC[*(s16 *)(p + 0x1E)].v - D_0045F0E0[*(s16 *)(p + 0x1E)].v) {
            break;
        }
        *(s16 *)(p + 0x1C) = 0;
        i = *(s16 *)(p + 0x1E) + 1;
        *(s16 *)(p + 0x1E) = i;
        if ((u32)(*(s16 *)(p + 0x1E) + 1) >= 3) {
            *(s16 *)(p + 0x1E) = 1;
        }
        break;
    case 1:
        break;
    }
}
