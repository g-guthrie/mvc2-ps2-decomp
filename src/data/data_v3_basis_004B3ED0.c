typedef struct V3 { float x, y, z; } V3;
/* Entries 0..2 are cycled mod 3 (func_00161530, src/z0_b.c). The fourth
 * entry is not reached by those readers; it is typed from the parallel tables at
 * 0x004B3F80/0x004B3FB0, whose fourth entry is reachable. */
V3 data_v3_basis_004B3ED0[4] = {
    { 0.0f, 0.0f, 1.0f },
    { 0.0f, 1.0f, 0.0f },
    { 1.0f, 0.0f, 0.0f },
    { 1.0f, 1.0f, 1.0f },
};
