typedef unsigned int u32;
u32 func_00102898(u32 value) {
    volatile u32 *reg = (volatile u32 *)0x1000E060;
    u32 old = *reg;
    *reg = value;
    return old;
}
