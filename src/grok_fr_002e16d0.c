typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2794;
extern u8 D_0045AE40[];
extern void func_001757E0(u8 *, int, int);
extern void func_001E3710(u8 *, int);

void func_002E16D0(u8 *p)
{
    if (*(u16 *)(p + 526) & 0x1000) {
        if (p[508] == 0) {
            if (p[530]) {
                p[437] = 0x12;
                p[434] = *(u16 *)(p + 448) = 0;
                *(u32 *)(p + 472) = 0;
                ((s16 *)(D_004C2794 + 124))[p[2]]++;
                func_001757E0(p, 12, 3);
                goto done_anim;
            }
        }
    }
    {
        s8 a2 = *(s8 *)(p + 530);
        s8 v1 = *(s8 *)(p + 508);
        p[437] = v1 + (a2 * 3 + 12);
        p[434] = *(u16 *)(p + 448) = 0;
        *(u32 *)(p + 472) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
        func_001757E0(p, (p[530] + 11) & 0xFF, p[508]);
    }
done_anim:
    *(u8 **)(p + 1032) = D_0045AE40 + (p[508] * 4 + p[530] * 12);
    p[443] = p[508];
    if (p[530])
        func_001E3710(p, (p[508] + 0x14) & 0xFF);
    if (p[530] == 0) {
        s8 a0 = *(s8 *)(p + 490);
        if (a0 & 0xF)
            p[490] = a0 - 1;
    } else {
        s8 a0 = *(s8 *)(p + 490);
        if (a0 & 0xF0)
            p[490] = a0 - 16;
    }
}
