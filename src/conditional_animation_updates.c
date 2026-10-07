/* Resolve the signed pending action before advancing the normal animation. */
typedef unsigned char u8;
extern int func_00169CE0(u8 *, int, int);
extern signed char func_00175700(u8 *);
extern void func_00186CE0(u8 *, int);

#define CONDITIONAL_ANIMATION_UPDATE(name) \
void name(u8 *p) { \
    if (p[0x1ee]) { p[0x201] = 2; p[0x1b1] = 0; } \
    if (!p[0x249] && *(short *)(p + 0x434) && \
        *(signed char *)(p + 0x24a)) { \
        if (*(signed char *)(p + 0x539)) { \
            if (func_00169CE0(p, 29, 2)) *(signed char *)(p + 0x24a) = -1; \
            else p[0x24a] = 0; \
        } \
        if (*(signed char *)(p + 0x24a) < 0) { \
            p[0x1e7] = 0; func_00186CE0(p, 17); return; \
        } \
    } \
    if (func_00175700(p) < 0) func_00186CE0(p, 23); \
}

CONDITIONAL_ANIMATION_UPDATE(func_00176CF0)
CONDITIONAL_ANIMATION_UPDATE(func_00177320)
CONDITIONAL_ANIMATION_UPDATE(func_00177700)
CONDITIONAL_ANIMATION_UPDATE(func_001782C0)
