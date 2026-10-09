typedef float f32;

/* func_003CEBC0 and func_003CECD0 index this float3 table with
 * D_004F7F32. That signed-byte global is initialized/assigned only zero
 * (stores at 0x003D4410 and 0x003D52A0), so these consumers select row 0. */
f32 data_f32_004768A0[3] = { 0.026f, 0.968f, -12.99f };
