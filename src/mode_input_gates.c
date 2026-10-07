/* Preserve the two accepted input modes and their distinct transition kinds. */
typedef unsigned char u8;
extern int func_001E7FD0(u8 *);

#define MODE_INPUT_GATE(name) \
int name(u8 *p) { \
    if ((p[0x22] = (*(unsigned short *)(p + 0x20e) & 0xc00) >> 10)) { \
        int mode = p[0x212]; \
        if (!mode && p[0x1b7] == 1) { \
            int result = func_001E7FD0(p); \
            if (result) { p[0x20b] = 0; return result; } \
        } else if (mode == 1 && p[0x1b7] == 1) { \
            int result = func_001E7FD0(p); \
            if (result) { p[0x20b] = 1; return result; } \
        } \
    } \
    return 0; \
}

MODE_INPUT_GATE(func_001FB430)
MODE_INPUT_GATE(func_002255C0)
MODE_INPUT_GATE(func_00269E00)
MODE_INPUT_GATE(func_002A5B90)
MODE_INPUT_GATE(func_002AB050)
MODE_INPUT_GATE(func_002C44C0)
MODE_INPUT_GATE(func_002D0360)
MODE_INPUT_GATE(func_002D53F0)
MODE_INPUT_GATE(func_0030BB60)
