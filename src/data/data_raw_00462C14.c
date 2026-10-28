typedef float f32;
/* Float velocities between D_00462C10 (16.666666f, loaded with lwc1 into actor +0x5C by
 * func_003564A0) and the lwc1-indexed table D_00462C30. No direct reader of these seven
 * was found; the values are multiples of the 5/3 (x) and 15/7 (y) scales the same
 * readers apply (15 = 9 * 5/3, 8.5714283 = 4 * 15/7, -4.2857141 = -2 * 15/7). */
f32 data_raw_00462C14[7] = {
    15.0f, 15.416666f, 8.5714283f, 15.0f, 2.14285707f, 13.541666f, -4.28571415f,
};
