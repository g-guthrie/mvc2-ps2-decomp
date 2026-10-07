/* Update mode-two motion, enforce its height bound, then dispatch substate. */
typedef unsigned char u8;
typedef int (*StateHandler)(u8 *, u8 *);
extern void func_001820A0(u8 *);
extern StateHandler D_00450C20[];
extern StateHandler D_00450C40[];
extern StateHandler D_00450C70[];
extern StateHandler D_004542A8[];
extern StateHandler D_004542B8[];
extern StateHandler D_004543C0[];

#define CLAMPED_STATE_DISPATCH(name, table) \
int name(u8 *p) { \
    if (p[0x20d] == 2) { \
        func_001820A0(p); \
        if (*(float *)(p + 0x38) < *(float *)(p + 0x430)) \
            *(float *)(p + 0x38) = *(float *)(p + 0x430); \
    } \
    { \
        StateHandler *handlers = (table); \
        unsigned int state = (unsigned int)p + 0x2b8; \
        unsigned int index = p[6]; \
        return handlers[index](p, (u8 *)state); \
    } \
}

CLAMPED_STATE_DISPATCH(func_00212390, D_00450C20)
CLAMPED_STATE_DISPATCH(func_002127D0, D_00450C40)
CLAMPED_STATE_DISPATCH(func_00212EC0, D_00450C70)
CLAMPED_STATE_DISPATCH(func_00265760, D_004542A8)
CLAMPED_STATE_DISPATCH(func_00265AB0, D_004542B8)
CLAMPED_STATE_DISPATCH(func_00268D50, D_004543C0)
