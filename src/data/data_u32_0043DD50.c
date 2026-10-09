typedef unsigned int u32;
/* func_00131E20 selects field0x4DD in 0..2 and reads four packed words
 * per record; each word supplies three masked unsigned bytes converted
 * to floats, and its high byte is ignored. field0x4DD is zero, reduced
 * modulo 3, or mapped through
 * D_004405A0. Valid field0x540 values come from bounded setup tables, the
 * 64-byte D_0043F9A0 map (0..0x3A or a guarded -1 sentinel), or the
 * three-step state codes0x18..0x1A. D_004405A0 values are all0..2. */
u32 data_u32_0043DD50[3][4] = {
    { 0xFFFF40FFu, 0xFFFFFF00u, 0xFFFF40FFu, 0xFFFFFF00u },
    { 0xFF00FF00u, 0xFFFFFF00u, 0xFF00FF00u, 0xFFFFFF00u },
    { 0xFF00C0FFu, 0xFFFFFF00u, 0xFF00C0FFu, 0xFFFFFF00u },
};
