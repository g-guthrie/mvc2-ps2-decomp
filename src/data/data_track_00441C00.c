typedef signed short s16;
typedef float f32;
/* Keyframe track, event category 4 (scale x/y): func_001415B0 switches on object +0x20
 * (jtbl_004B1E50, case 0x00141878), steps 0xC-byte keys from the pointer at object +0x10
 * and compares the next key's s16 time against -1 to end the track. */
typedef struct { s16 time; s16 pad; f32 scale[2]; } ScaleKey;
typedef char ScaleKey_size_check[(sizeof(ScaleKey) == 12) ? 1 : -1];
ScaleKey data_track_00441C00[3] = {
    { 0, 0, { 0.0f, 1.0f } },
    { 7, 0, { 0.25f, 1.0f } },
    { -1, 0, { 1.0f, 0.1f } },
};
