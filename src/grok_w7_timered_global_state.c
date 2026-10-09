typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;

extern u8 D_004D18A0;
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_001E3210(u8 *, int);
extern void func_002F1DF0(u8 *);

void func_002F0F70(u8 *p)
{
    s16 timer;

    if (p[6] == 0) {
        p[6]++;
        p[0x20D] = 0;
        *(s16 *)(p + 0x1C) = 0x3C;
        func_001757E0(p, 21, 37);
        func_001E3210(p, 21);
        return;
    }

    func_00175700(p);
    if (D_004D18A0 == 4
        && *(s8 *)(p + 0x539) == 0
        && (*(u16 *)(p + 0x35E) & 2) != 0) {
        if (*(s16 *)(p + 0x1C) < 2)
            *(s16 *)(p + 0x1C) = 2;
    }

    timer = *(s16 *)(p + 0x1C);
    timer--;
    *(s16 *)(p + 0x1C) = timer;
    if (timer == 0)
        func_002F1DF0(p);
}
