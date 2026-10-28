#ifndef PACKED_SAMPLE_00449460_H
#define PACKED_SAMPLE_00449460_H
typedef signed short s16;
/* 8-byte sample: func_00194FF0 reads x (+0) and y (+2) with lh and the low
 * byte of tag (+4) with lb (0x00195074-0x001951D4). The halfword at +6 is
 * never read and is zero in every record. */
typedef struct PackedSample_00449460 {
    s16 x;
    s16 y;
    s16 tag;
    s16 unused;
} PackedSample_00449460;
typedef char packed_sample_00449460_size_check[(sizeof(PackedSample_00449460) == 8) ? 1 : -1];
#endif
