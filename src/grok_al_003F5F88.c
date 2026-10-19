typedef signed int s32;
typedef signed char s8;

typedef struct {
    s8 used;
    s8 b1;
    s8 b2;
    s8 pad;
    s32 w4[3];
    s32 w10[3];
    s32 w1c;
    s32 w20;
    float f24;
    float f28;
    s32 w2c;
} Slot;

extern Slot D_00478E78[];
extern void func_003F9630(void);
extern void func_003F9660(void);
extern float D_004BF280;

Slot *func_003F5F88(s32 count, s32 *a, s32 *b)
{
    s32 i;
    Slot *p;
    s32 *dst;
    s32 *dst2;

    p = D_00478E78;
    i = 0;
    if (p->used) {
        i++;
        while (i < 8) {
            p++;
            if (p->used)
                i++;
            else
                break;
        }
    }
    if (i == 8)
        return 0;
    func_003F9630();
    p = &D_00478E78[i];
    p->b2 = (s8)count;
    if (count > 0) {
        dst2 = p->w10;
        dst = p->w4;
        i = 0;
        do {
            dst[4] = 0;
            dst[0] = a[i];
            dst++;
            dst2[i] = b[i];
            i++;
        } while (i < count);
    }
    p->w20 = 0xAC44;
    p->w1c = count;
    p->f28 = D_004BF280;
    p->used = 1;
    p->b1 = 0;
    p->w2c = 0;
    p->f24 = D_004BF280;
    func_003F9660();
    return p;
}
