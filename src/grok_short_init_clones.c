typedef unsigned char u8;
typedef signed char s8;

extern void func_00186A60(u8 *, int);

#define INIT_2A0A10 \
    { \
        s8 v; \
        p[5] = 0; p[7] = 0; p[6] = 0; \
        v = *(s8 *)(p + 1245); \
        switch (v) { \
        case 0: p[509] = 1; break; \
        case 1: p[509] = 1; break; \
        case 2: p[509] = 1; break; \
        } \
        func_00186A60(p, 29); \
    }

void func_002A0A10(u8 *p) { INIT_2A0A10 }
void func_00304950(u8 *p) { INIT_2A0A10 }
