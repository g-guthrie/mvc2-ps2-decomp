typedef float f32;

/* Constructors func_00160C80, func_00160D10, and func_00160DB0 initialize
 * task field0x1C to zero and install func_00160F90 in group 9. The frame
 * dispatcher func_001E8CD0 calls func_003DA6F0 for group 9 at 0x001E8DE8 or
 * 0x001E8E40. func_00160F90 scales field0x1C by four, loads this float, and
 * increments it while field0x1C < 22 before removing the task. */
f32 data_f32_004456F0[22] = {
    1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
};
