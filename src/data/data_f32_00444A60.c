typedef float f32;

/* func_00154F10 allocates a cleared task and installs func_00154FF0. The
 * callback advances field0x1C through three setup steps, switches to state
 * 1, then loads this table at indices0..5 before removing the task. The frame
 * dispatcher runs both selected task groups (0x17 and 0x3B) via
 * func_001E8890. */
f32 data_f32_00444A60[6] = { 1.0f, 1.0f, 1.0f, 1.0f, 0.5f, 0.2f };
