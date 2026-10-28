typedef signed short s16;
typedef float f32;
/* Keyframe track, event category 6 (angle + scale x/y): func_001415B0 switches on object +0x20
 * (jtbl_004B1E50, case 0x001418F0), steps 0xC-byte keys from the pointer at object +0x10
 * and compares the next key's s16 time against -1 to end the track. The reader also stops on -2 (hold) and -3 (loop back two keys) at 0x00141904-0x0014194C. */
typedef struct { s16 time; s16 angle; f32 scale[2]; } RotScaleKey;
typedef char RotScaleKey_size_check[(sizeof(RotScaleKey) == 12) ? 1 : -1];
RotScaleKey D_00441700[9] = {
    { 0, 0, { 3.0f, 3.0f } },
    { 30, 90, { 2.0f, 2.0f } },
    { 60, 180, { 1.0f, 1.0f } },
    { 120, 360, { 2.0f, 2.0f } },
    { 180, 540, { 3.0f, 3.0f } },
    { 260, 900, { 2.0f, 2.0f } },
    { 320, 990, { 3.0f, 1.0f } },
    { 380, 1080, { 6.0f, 6.0f } },
    { -1, -630, { 3.0f, 3.0f } },
};
