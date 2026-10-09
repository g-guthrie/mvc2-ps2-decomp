typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
extern u8 *D_004C28DC;
extern void func_001DB640(u8 *);
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
void func_0030A7C0(u8 *p)
{
    s16 timer;
    s16 count;
    D_004C28DC = p + 0x2B8;
    if ((s8)p[0x151] == 0) {
        p[0x13C] = 1;
        if ((*(s16 *)(p + 0x1C) & 0xF) == 0)
            func_001DB640(p);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        /* Ordered comparison leaves unordered positions on the countdown path. */
        if (*(f32 *)(p + 0x430) < *(f32 *)(p + 0x38)) {
            p[6]++;
            D_004C28DC[7] = 1;
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            p[0x20D] = 0;
            func_001757E0(p, 18, 11);
            return;
        }
        timer = *(s16 *)(p + 0x1E);
        timer--;
        *(s16 *)(p + 0x1E) = timer;
        if (timer == 0) {
            *(s16 *)(p + 0x1E) = 4;
            count = *(s16 *)(p + 0x1C);
            count++;
            *(s16 *)(p + 0x1C) = count;
            if (count >= 11)
                *(s16 *)(p + 0x1C) = 11;
            func_001757E0(p, 18, ((u8 *)(p + 0x1C))[0]);
            return;
        }
        func_00175700(p);
        return;
    }
    p[0x13C] = 0;
    func_00175700(p);
}
