typedef signed short s16;
typedef signed char s8;

typedef struct MotionRecord {
    s16 xOffset;
    s16 yOffset;
    s8 stateValue;
    s16 effectParameter;
} MotionRecord;
typedef char MotionRecord_size_check[sizeof(MotionRecord) == 8 ? 1 : -1];

/* 32 records selected by func_00198E30: (s8(p[0x22]) + 4) & 0x7C,
 * then byte-offset *2; the four reads land at record fields +0,+2,+4,+6.
 * The +0x05 byte is alignment padding and is zero in the target image.
 */
MotionRecord data_motion_0044A510[32] = {
    { -16, -27, 12, 0 },
    { -17, -24, 12, 0 },
    { -17, -22, 12, 1 },
    { -16, -18, 12, 1 },
    { -14, -14, 12, 1 },
    { -13, -9, 12, 2 },
    { -10, -4, 12, 2 },
    { -8, 0, 12, 2 },
    { -4, 4, 12, 3 },
    { -1, 9, 12, 3 },
    { 2, 14, 12, 3 },
    { 6, 18, 12, 4 },
    { 9, 22, 12, 4 },
    { 11, 24, 12, 4 },
    { 14, 27, 12, 5 },
    { 16, 28, 12, 5 },
    { 16, 27, 10, 0 },
    { 17, 25, 10, 0 },
    { 17, 23, 10, 1 },
    { 16, 19, 10, 1 },
    { 14, 15, 10, 1 },
    { 13, 10, 10, 2 },
    { 10, 5, 10, 2 },
    { 8, 0, 10, 2 },
    { 4, -5, 10, 3 },
    { 1, -10, 10, 3 },
    { -2, -15, 10, 3 },
    { -6, -19, 10, 4 },
    { -9, -23, 10, 4 },
    { -11, -25, 10, 4 },
    { -14, -27, 10, 5 },
    { -16, -28, 10, 5 },
};
