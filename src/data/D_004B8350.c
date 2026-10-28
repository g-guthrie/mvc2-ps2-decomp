typedef float f32;
/* Float pairs indexed by p[0x20] with scale 8: D_004B8350 at 0x00355298 and its second
 * column D_004B8354 at 0x00355348 (lbu 0x20, sll 3); rows 2..5 are also read through
 * D_004B8360/D_004B8364 at 0x0037580C (w188_d.c). p[0x20] selects one of the six
 * entries of D_004B8380, which bounds the row count. */
f32 D_004B8350[6][2] = {
    { -9.0625f, -3.6160712f },
    { -10.0f, 0.0f },
    { -8.333333f, 5.3571424f },
    { -7.5f, -6.5625f },
    { -10.0f, 0.0f },
    { -8.333333f, 5.3571424f },
};
