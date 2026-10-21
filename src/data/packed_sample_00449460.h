#ifndef PACKED_SAMPLE_00449460_H
#define PACKED_SAMPLE_00449460_H
typedef signed short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef struct PackedSample_00449460 {
    s16 x;
    s16 y;
    s8 tag;
    u8 raw_tail[3];
} PackedSample_00449460;
typedef char packed_sample_00449460_size_check[(sizeof(PackedSample_00449460) == 8) ? 1 : -1];
#endif
