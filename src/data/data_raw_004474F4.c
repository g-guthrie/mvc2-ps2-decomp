typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Signed 16-bit pairs; final pair is zero. */
typedef struct raw_004474F4_rec {
    s16 lo;
    s16 hi;
} raw_004474F4_rec;
typedef char raw_004474F4_rec_size_check[(sizeof(raw_004474F4_rec) == 4) ? 1 : -1];
raw_004474F4_rec data_raw_004474F4[23] = {
    { 384, -384 },
    { 896, -768 },
    { 1024, -768 },
    { 768, -640 },
    { 512, -384 },
    { 1056, -896 },
    { 1024, -768 },
    { 768, -640 },
    { 1024, -768 },
    { 768, -640 },
    { 512, -576 },
    { 1024, -768 },
    { 688, -768 },
    { 512, -448 },
    { 768, -640 },
    { 768, -768 },
    { 416, -384 },
    { 512, -384 },
    { 640, -512 },
    { 1024, -768 },
    { 768, -640 },
    { 1024, -768 },
    { 0, 0 },
};
