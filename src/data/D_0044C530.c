typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
/* func_001C0A90 (src/payload_placement_initializers_001a79b0.c) reads
 * D_0044C530[p->b20]: lb +0/+1, lb +2 (low byte of pose), lh +4/+6, lbu +8/+9.
 * The pose halfword is sign-extended in every record. Records from
 * 0x0044C5A8 on are still separate units. */
typedef struct { s8 flags; s8 paletteDelta; s16 pose; s16 velocityX; s16 velocityY; u8 animation; u8 variant; } EffectLaunch;
typedef char EffectLaunch_size_check[(sizeof(EffectLaunch) == 10) ? 1 : -1];
EffectLaunch D_0044C530[12] = {
    { 0, 0, -1, -24, -46, 27, 3 },
    { 0, 0, -1, -24, -34, 27, 3 },
    { 0, 0, -1, -29, -68, 27, 3 },
    { 0, 0, -1, -24, -46, 27, 4 },
    { 0, 0, -1, -24, -34, 27, 4 },
    { 0, 0, -1, -29, -68, 27, 4 },
    { 0, 0, -1, 2, -22, 27, 0 },
    { 1, 5, 0, 0, 0, 27, 36 },
    { 0, 0, -1, 0, 0, 27, 5 },
    { 0, 0, -1, 0, 0, 27, 17 },
    { 0, 0, -2, -24, -181, 27, 18 },
    { 0, 0, -2, -67, -159, 27, 19 },
};
