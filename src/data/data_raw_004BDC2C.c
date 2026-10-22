/* Leading zero word, then the two strings appended while building a path:
   the backslash separator (D_004BDC30) and the ";1" suffix (D_004BDC38). */
typedef struct Tab_004BDC2C {
    char pad[4];
    char sep[8];
    char ver[8];
} Tab_004BDC2C;
typedef char Tab_004BDC2C_size_check[(sizeof(Tab_004BDC2C) == 20) ? 1 : -1];
Tab_004BDC2C data_raw_004BDC2C = { { 0, 0, 0, 0 }, "\\", ";1" };
