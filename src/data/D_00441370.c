typedef unsigned char u8;
typedef unsigned int u32;
extern u8 data_zero_004410E0[0x10];
extern u32 data_u32_004410F0[160];

/* func_001434A0 resets D_004C2648 at timer 0 (0x0014355C-60), then indexes
 * this table at timer values 0x6E, 0x1E3, 0x233, 0x346, 0x3CA, 0x41A, and
 * 0x5BB (0x001435A8-CC and 0x00143570-98). Each event increments the index.
 * func_00143A60 increments that timer once per update and func_001434A0 is
 * called on every update. At timer 0x6BB, after the final table read, it clears
 * the active-state byte and advances the state (0x00143C10-34), so selectors
 * 0..6 are the complete reachable range. The targets stay raw; this table only
 * records the seven observed addresses. */
void * const D_00441370[7] = {
    data_zero_004410E0,
    data_u32_004410F0 + 24,
    data_u32_004410F0 + 64,
    data_u32_004410F0 + 88,
    data_u32_004410F0 + 112,
    data_u32_004410F0 + 48,
    data_u32_004410F0 + 136,
};
