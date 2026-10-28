typedef signed short s16;
typedef float f32;
/* Keyframe track, event category 6 (angle + scale x/y): func_001415B0 switches on object +0x20
 * (jtbl_004B1E50, case 0x001418F0), steps 0xC-byte keys from the pointer at object +0x10
 * and compares the next key's s16 time against -1 to end the track. The reader also stops on -2 (hold) and -3 (loop back two keys) at 0x00141904-0x0014194C. */
typedef struct { s16 time; s16 angle; f32 scale[2]; } RotScaleKey;
typedef char RotScaleKey_size_check[(sizeof(RotScaleKey) == 12) ? 1 : -1];
RotScaleKey D_00441550[6] = {
    { 0, -45, { 2.2f, 2.2f } },
    { 240, -765, { 2.2f, 2.2f } },
    { 260, -825, { 2.5f, 2.5f } },
    { 320, -1005, { 3.0f, 1.0f } },
    { 380, -1185, { 6.0f, 6.0f } },
    { -1, -630, { 3.0f, 3.0f } },
};
