typedef short s16;
/* Five (s16, s16) pairs. */
typedef struct Mv_PAIR16 {
    s16 s_00;
    s16 s_02;
} Mv_PAIR16;
typedef char Mv_PAIR16_size_check[(sizeof(Mv_PAIR16) == 4) ? 1 : -1];
const Mv_PAIR16 jtbl_00461CBC[5] = {
    { 18, 21 },
    { 24, 27 },
    { 30, 33 },
    { 36, 39 },
    { 42, 45 },
};
