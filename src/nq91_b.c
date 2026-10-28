typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

void func_0018E810(u8 *p, u8 *q)
{
    extern void func_00328990(u8 *);
    extern void func_00328C10(u8 *);
    extern void func_00328E60(u8 *);
    extern void func_003294B0(u8 *);
    u8 k;
    u8 t;
    u8 m;
    k = *(s8 *)(q + 0x1C0) & 0xF;
    if (k == 0) {
        k = *(s8 *)(p + 0x245) & 7;
        if (k == 0) return;
    }
    if (k & 8) k = 1;
    switch (k) {
    case 1: m = 1; break;
    case 2: m = 2; break;
    case 3: m = 3; break;
    case 6: m = 4; break;
    default: return;
    }
    t = p[0x23F];
    p[0x23E] = m;
    if (t != m) p[0x23D] = 0;
    if (*(s8 *)(p + 0x23D) < 4) {
        switch ((u8)m) {
        case 1: func_00328990(p); return;
        case 2: func_00328C10(p); return;
        case 3: func_00328E60(p); return;
        case 4: func_003294B0(p); return;
        }
    }
}
