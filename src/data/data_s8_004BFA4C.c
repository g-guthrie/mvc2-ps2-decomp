typedef signed char s8;

/* q8_h.c and w1912_g.c use (random & 3) to select a signed step
 * added to p[0x22] before wrapping it to a five-bit state. */
s8 data_s8_004BFA4C[4] = { 0, 0, 1, -1 };
