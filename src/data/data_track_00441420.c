typedef signed short s16;
typedef float f32;
/* Keyframe track, event category 2 (angle in degrees): func_001415B0 switches on object +0x20
 * (jtbl_004B1E50, case 0x001417DC), steps 0x4-byte keys from the pointer at object +0x10
 * and compares the next key's s16 time against -1 to end the track. */
typedef struct { s16 time; s16 angle; } RotKey;
typedef char RotKey_size_check[(sizeof(RotKey) == 4) ? 1 : -1];
RotKey data_track_00441420[4] = {
    { 0, 0 },
    { 150, -180 },
    { 270, -360 },
    { -1, -360 },
};
