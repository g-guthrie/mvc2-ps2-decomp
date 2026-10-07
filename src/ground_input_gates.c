/* Consume a grounded input request and clear its accepted transition kind. */
typedef unsigned char u8;
extern int func_001E7FD0(u8 *);

#define GROUND_INPUT_GATE(name) \
int name(u8 *p) { \
    if ((p[0x22] = (*(unsigned short *)(p + 0x20e) & 0xc00) >> 10) && \
        !p[0x212] && p[0x1b7] == 1) { \
        int result = func_001E7FD0(p); \
        if (result) { p[0x20b] = 0; return result; } \
    } \
    return 0; \
}

GROUND_INPUT_GATE(func_0024CF10)
GROUND_INPUT_GATE(func_002531A0)
GROUND_INPUT_GATE(func_0025B440)
GROUND_INPUT_GATE(func_00261B10)
GROUND_INPUT_GATE(func_0026E830)
GROUND_INPUT_GATE(func_00272B00)
GROUND_INPUT_GATE(func_00285AE0)
GROUND_INPUT_GATE(func_0028D130)
GROUND_INPUT_GATE(func_00294480)
GROUND_INPUT_GATE(func_002CB700)
