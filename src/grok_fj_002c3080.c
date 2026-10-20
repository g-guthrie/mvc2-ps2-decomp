typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;

typedef struct { s8 ticks; s8 step; } SelectorSweep;
extern SelectorSweep *D_004C28D8 __attribute__((section(".sdata")));
extern void func_002C3200(u8 *);
extern void func_002C31F0(u8 *);

void func_002C3080(u8 *p)
{
    s8 t;
    u16 keys;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (*(s8 *)(p + 0x539) || p[0x269] == 4 || p[0x269] == 5) {
        t = D_004C28D8->ticks - 1;
        D_004C28D8->ticks = t;
        if (t) {
            func_002C3200(p);
            return;
        }
        p[0x22] += (u8)D_004C28D8->step;
        if ((u8)p[0x22] >= 8 || (u8)p[0x22] < 3)
            D_004C28D8->step = -D_004C28D8->step;
        func_002C31F0(p);
        return;
    }
    keys = *(u16 *)(p + 0x35E) & *(u16 *)(p + 0x360);
    if ((keys & 0x3000) == 0) {
        func_002C31F0(p);
        return;
    }
    t = D_004C28D8->ticks - 1;
    D_004C28D8->ticks = t;
    if (t) {
        func_002C3200(p);
        return;
    }
    if (*(u16 *)(p + 0x35E) & 0x2000) {
        if (p[0x22])
            p[0x22]--;
    } else if (p[0x22] < 9)
        p[0x22]++;
    func_002C31F0(p);
}
