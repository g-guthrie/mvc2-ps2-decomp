/* func_001A3810 consumes two byte pairs selected by states 0 and 1. */
typedef unsigned char u8;

typedef struct {
    u8 flip;
    u8 frame;
} A3810FlipFrame;

A3810FlipFrame data_D_004BF680[2] = {
    { 0x00, 0x05 },
    { 0x00, 0x06 },
};

/* Interior byte-view alias used by the native second-field GP-relative load. */
extern u8 data_D_004BF681[];
