typedef unsigned int u32;
typedef float f32;
typedef union {
    u32 bits;
    f32 value;
} f32_bits;

/* func_00160F90 selects entries 0..21 through task field0x1C and loads
 * each selected word with lwc1.  Spell the float bit pattern through the
 * union's integer member because MWCC emits a different byte order for an
 * all-1.0f initializer array. */
f32_bits data_f32_004456F0[22] = {
    { 0x3F800000u }, { 0x3F800000u }, { 0x3F800000u }, { 0x3F800000u },
    { 0x3F800000u }, { 0x3F800000u }, { 0x3F800000u }, { 0x3F800000u },
    { 0x3F800000u }, { 0x3F800000u }, { 0x3F800000u }, { 0x3F800000u },
    { 0x3F800000u }, { 0x3F800000u }, { 0x3F800000u }, { 0x3F800000u },
    { 0x3F800000u }, { 0x3F800000u }, { 0x3F800000u }, { 0x3F800000u },
    { 0x3F800000u }, { 0x3F800000u },
};
