typedef signed char s8;
/* func_0018E970 computes ((p->b21b - t->b21b + 7) & 0xF), loads one
 * signed correction, adds it to p->b243, then clamps the result to 0..15.
 * The mask bounds every lookup to these 16 entries, regardless of input bytes.
 */
s8 data_s8_00446D40[16] = {
    3, 3, 2, 2, 1, 1, 0, 0,
    0, -1, -1, -2, -2, -3, -3, -3,
};
