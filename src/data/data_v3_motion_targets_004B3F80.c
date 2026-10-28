typedef struct V3 { float x, y, z; } V3;
/* Indexed by ((s8)D_004C2840[0x9C] & 0xF) - 1 without a mod (func_00161690 in
 * src/y1_g.c and its 0x004B3FB0 twin), so index 3 reaches the fourth entry;
 * the key cycle in src/vector_cycle_transitions.c uses entries 0..2. */
V3 data_v3_motion_targets_004B3F80[4] = {
    { 0.50980395f, 0.50980395f, 1.0f },
    { 0.7058824f, 1.0f, 0.7058824f },
    { 1.0f, 0.50980395f, 0.50980395f },
    { 1.0f, 1.0f, 1.0f },
};
