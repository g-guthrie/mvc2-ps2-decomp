typedef unsigned short u16;
typedef unsigned int u32;

extern volatile u16 D_004F4484;
extern volatile u16 D_004F4498;
extern int func_00131660(void);
extern int func_00131720(void);

int func_00131720(void) {
    u32 state = (u32)D_004F4484 | (u32)D_004F4498;
    if ((state & 0x100) != 0)
        goto enabled;
    return 0;

enabled:
    return 1;
}

int func_001317B0(void) {
    if (func_00131660())
        return 1;
    return func_00131720();
}
