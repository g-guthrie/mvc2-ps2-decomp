/* Decode the input state and accept an airborne transition above the limit. */
typedef unsigned char u8;
extern int func_001E7FD0(u8 *);

#define HEIGHT_INPUT_GATE(name, mask, transition) \
int name(u8 *p) { \
    if ((p[0x22] = (*(unsigned short *)(p + 0x20e) & (mask)) >> 10) && \
        !p[0x212] && p[0x1b7] == 1 && \
        !(*(float *)(p + 0x38) <= 137.142852783203125f)) { \
        int result = func_001E7FD0(p); \
        if (result) { p[0x20b] = (transition); return result; } \
    } \
    return 0; \
}

HEIGHT_INPUT_GATE(func_0020F370, 0xc00, 1)
HEIGHT_INPUT_GATE(func_00225670, 0xc00, 2)
HEIGHT_INPUT_GATE(func_0024CF90, 0x1c00, 1)
HEIGHT_INPUT_GATE(func_00253220, 0xc00, 1)
HEIGHT_INPUT_GATE(func_00261B90, 0x1c00, 1)
HEIGHT_INPUT_GATE(func_00272B80, 0xc00, 1)
HEIGHT_INPUT_GATE(func_00285B60, 0xc00, 1)
HEIGHT_INPUT_GATE(func_0028D1B0, 0x1c00, 1)
HEIGHT_INPUT_GATE(func_00294500, 0x1c00, 1)
HEIGHT_INPUT_GATE(func_0029A310, 0xc00, 3)
HEIGHT_INPUT_GATE(func_002A5C40, 0xc00, 2)
HEIGHT_INPUT_GATE(func_002AB100, 0xc00, 2)
HEIGHT_INPUT_GATE(func_002B79F0, 0xc00, 1)
HEIGHT_INPUT_GATE(func_002C4570, 0x1c00, 2)
HEIGHT_INPUT_GATE(func_002CB780, 0xc00, 1)
HEIGHT_INPUT_GATE(func_002D0410, 0xc00, 2)
