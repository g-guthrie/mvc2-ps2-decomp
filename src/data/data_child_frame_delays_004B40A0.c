/* func_001626C0 reads index mode*8 + frame into the signed +0x1E timer.
 * func_00162740 decrements that timer, then advances/clamps frame at seven.
 * The valid table read domain is 0 <= mode*8 + frame < 16. */
typedef signed short s16;
s16 data_child_frame_delays_004B40A0[16] = {
    2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2
};
