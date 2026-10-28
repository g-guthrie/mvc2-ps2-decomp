typedef signed short s16;
typedef signed char s8;
typedef unsigned char u8;
/* func_001BE040 (src/parent_effect_initializer.c) reads D_0044C290[p->b20]. */
typedef struct { s16 x, y; s8 pose; u8 animation; } Placement;
typedef char Placement_size_check[(sizeof(Placement) == 6) ? 1 : -1];
Placement D_0044C290[26] = {
    { -64, 16, -1, 16 },
    { 64, 16, 1, 17 },
    { -64, 0, -3, 18 },
    { 64, 0, 3, 19 },
    { 64, -16, 2, 20 },
    { -64, -16, -3, 21 },
    { -64, 0, -1, 22 },
    { 64, 0, 1, 23 },
    { -64, 0, -2, 24 },
    { 64, 0, 2, 25 },
    { -64, 0, -1, 26 },
    { 64, 0, 1, 27 },
    { -64, 0, -2, 28 },
    { 64, 0, 2, 29 },
    { -64, 0, -1, 30 },
    { 64, 0, 1, 31 },
    { -64, 0, -1, 32 },
    { 64, 0, 1, 33 },
    { -64, 0, 0, 34 },
    { 64, 0, 1, 35 },
    { 64, -32, -4, 36 },
    { -64, -32, 4, 37 },
    { -64, 32, 3, 38 },
    { 64, 32, -3, 39 },
    { 64, 0, -3, 40 },
    { 64, -16, -3, 41 },
};
