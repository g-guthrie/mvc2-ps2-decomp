typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed int s32;
typedef float f32;
extern s32 func_00176160(u8 *, int, int, int);
void func_0028D810(u8 *p, u8 *record)
{
    u8 *state = p + 696;
    do {
        state[14] = record[0];
        func_00176160(p, record[1], record[2] + p[37] * 87, record[3]);
        if (*(u32 *)(record + 4) == 1) state[15] = 0;
        else state[15] = 1;
        record += *(u32 *)(record + 4) * 8;
    } while (state[14] == 0);
    *(u8 **)(state + 16) = record;
}
void func_00294B20(u8 *p, u8 *record)
{
    u8 *state = p + 696;
    do {
        state[14] = record[0];
        func_00176160(p, record[1], record[2] + p[37] * 87, record[3]);
        if (*(u32 *)(record + 4) == 1) state[15] = 0;
        else state[15] = 1;
        record += *(u32 *)(record + 4) * 8;
    } while (state[14] == 0);
    *(u8 **)(state + 16) = record;
}
