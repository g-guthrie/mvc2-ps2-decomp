typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern s8 D_004ACD08[];

void func_00278710(u8 *p)
{
    *(s8 *)(p + 0x13D) = -1;
    *(s16 *)(p + 0x13E) = D_004ACD08[p[0x1B8]];
    if (!p[0x295]) {
        if (*(s8 *)(p + 0x1B4) && !p[5] && *(s8 *)(p + 0x1B3)) {
            p[0x295]++;
            goto move;
        }
        if (*(s8 *)(p + 0x297)) {
            if (!*(s8 *)(p + 0x1B4)) {
                s8 t = --*(s8 *)(p + 0x297);
                if (t == 0)
                    p[0x294] = 0;
            }
        }
        return;
    }
move:
    if (!*(s8 *)(p + 0x1B4)) {
        p[0x295] = 0;
        return;
    }
    {
        s16 s = (s16)(4 - ((*(s8 *)(p + 0x1B4) & 1) << 3));
        if (*(s16 *)(p + 0x140))
            s = -s;
        *(f32 *)(p + 0x34) += 1.6666666269302368f * (f32)s;
        if (!(*(s8 *)(p + 0x1B4) & 1)) {
            p[0x13D] = 1;
            *(s16 *)(p + 0x13E) = (s16)(D_004ACD08[p[0x1B8]] + 4);
        }
    }
}
