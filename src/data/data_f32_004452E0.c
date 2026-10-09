typedef float f32;

/* func_0015D420 initializes task field0x1C to zero and installs
 * func_0015D6A0 in group 8. Its callback loads table[field0x1C] while
 * field0x1C < 16, then increments the counter. func_001E8CD0 dispatches
 * group 8 at 0x001E8DE0 on the D_004D18A6==0 frame path. */
f32 data_f32_004452E0[16] = {
    1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 0.7f, 0.5f, 0.4f, 0.2f, 0.0f, 0.0f,
};
