typedef signed short s16;
typedef signed char s8;

typedef struct AnimationSample {
    s16 offset_00;
    s16 offset_02;
    s8 selector_04;
    s16 offset_06;
} AnimationSample;
typedef char AnimationSample_size_check[sizeof(AnimationSample) == 8 ? 1 : -1];

/* 32 records. The +0x05 byte is compiler alignment padding before the s16 at +0x06. */
AnimationSample data_animation_samples_0044A410[32] = {
    { -27, 1, 12, 6 },
    { -24, 1, 12, 22 },
    { -22, 2, 12, 7 },
    { -18, 2, 12, 23 },
    { -14, 3, 12, 8 },
    { -9, 4, 12, 24 },
    { -4, 4, 12, 9 },
    { 0, 4, 12, 25 },
    { 4, 4, 12, 10 },
    { 9, 4, 12, 26 },
    { 14, 3, 12, 11 },
    { 18, 2, 12, 27 },
    { 22, 2, 12, 13 },
    { 24, 1, 12, 29 },
    { 27, 1, 12, 14 },
    { 28, 0, 12, 30 },
    { 27, -1, 10, 15 },
    { 25, -2, 10, 31 },
    { 23, -3, 10, 0 },
    { 19, -3, 10, 16 },
    { 15, -4, 10, 0 },
    { 10, -5, 10, 16 },
    { 5, -5, 10, 1 },
    { 0, -5, 10, 17 },
    { -5, -5, 10, 2 },
    { -10, -5, 10, 18 },
    { -15, -4, 10, 3 },
    { -19, -3, 10, 19 },
    { -23, -3, 10, 4 },
    { -25, -2, 10, 20 },
    { -27, -1, 10, 5 },
    { -28, 0, 10, 21 },
};
