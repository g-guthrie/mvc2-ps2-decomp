typedef unsigned char u8;
typedef signed char s8;

extern void func_00186A60(u8 *, int);

#define INIT_8D7A \
    { \
        s8 v; \
        u8 *r = p + 696; \
        p[5] = 0; p[7] = 0; p[6] = 0; \
        v = (s8)p[1245]; \
        switch (v) { \
        case 0: p[509] = 0; p[525] = 0; r[2] = 2; break; \
        case 1: p[509] = 2; p[439] = 1; break; \
        case 2: p[509] = 2; p[439] = 1; break; \
        } \
        func_00186A60(p, 21); \
    }

void func_0028D7A0(u8 *p) { INIT_8D7A }
void func_00294A40(u8 *p) { INIT_8D7A }

#define INIT_3005 \
    { \
        s8 v; \
        p[5] = 0; p[7] = 0; p[6] = 0; \
        v = (s8)p[1245]; \
        switch (v) { \
        case 0: p[509] = 0; p[439] = 0; break; \
        case 1: p[509] = 0; p[439] = 1; break; \
        case 2: p[509] = 6; p[439] = 1; break; \
        } \
        func_00186A60(p, 21); \
    }

void func_00300520(u8 *p) { INIT_3005 }
void func_00300590(u8 *p) { INIT_3005 }

#define INIT_25C0 \
    { \
        s8 v; \
        p[5] = 0; p[7] = 0; p[6] = 0; \
        v = (s8)p[1245]; \
        switch (v) { \
        case 0: p[509] = 0; p[439] = 1; break; \
        case 1: p[509] = 1; p[439] = 1; break; \
        case 2: p[509] = 0; p[439] = 1; break; \
        } \
        func_00186A60(p, 21); \
    }

void func_0025C0B0(u8 *p) { INIT_25C0 }
void func_002AB810(u8 *p) { INIT_25C0 }
