typedef signed char s8;
typedef struct { s8 cell[8]; } GridRow;
/* func_0014BDA0 copies these 64 bytes to the stack (4 lq/sq) and walks them as 8 rows of 8 cells
 * (outer counter +8 per row, inner counter 0..7) with lb; -1 marks an empty cell, other cells
 * are masked with & 0x3F. */
GridRow data_rec_00444070[8] = {
    { { -1, -96, 92, 120, 71, 109, -74, -1 } },
    { { -1, -93, 2, 21, 6, 57, -82, -1 } },
    { { -89, 95, 0, 20, 22, 8, 111, -85 } },
    { { -95, 94, 1, 19, 23, 9, 104, -75 } },
    { { -91, 119, 4, 18, 11, 12, 105, -79 } },
    { { -90, 67, 34, 16, 15, 14, 108, -78 } },
    { { -1, -92, 5, 17, 10, 13, -77, -1 } },
    { { -1, -70, 93, 91, 112, 106, -76, -1 } },
};
