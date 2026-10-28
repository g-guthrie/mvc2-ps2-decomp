/*
 * func_001A3810 (0x001A386C / 0x001A3900) indexes 2-byte {flip, frame} pairs
 * by actor byte +0x21 (sll 1). The four pairs run up to jtbl_004BF688; the
 * second pair word (0x004BF684) has no other reader or pointer and is not
 * zero, so it belongs to this table rather than to alignment.
 */
typedef unsigned char u8;

typedef struct {
    u8 flip;
    u8 frame;
} A3810FlipFrame;

A3810FlipFrame data_D_004BF680[4] = {
    { 0x00, 0x05 },
    { 0x00, 0x06 },
    { 0x00, 0x07 },
    { 0x01, 0x07 },
};

/* Interior byte-view alias used by the native second-field GP-relative load. */
extern u8 data_D_004BF681[];
