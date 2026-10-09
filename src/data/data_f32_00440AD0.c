typedef float f32;

/* func_003D1B80 calls func_00140020 only with selectors 0..11. The
 * constructor indexes by 12*selector and loads all three components with
 * lwc1, proving this complete 12-row float3 table. */
f32 data_f32_00440AD0[36] = {
    1.0f, 1.0f, 10.0f, 1.0f, 1.0f, 10.0f,
    1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 10.0f,
    1.0f, 1.0f, 10.0f, 1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 10.0f, 1.0f, 1.0f, 10.0f,
    1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 10.0f,
    1.0f, 1.0f, 10.0f, 1.0f, 1.0f, 1.0f,
};
