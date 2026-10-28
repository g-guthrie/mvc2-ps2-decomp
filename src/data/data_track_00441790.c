typedef signed short s16;
typedef float f32;
/* Keyframe track, event category 3 (position + angle): func_001415B0 switches on object +0x20
 * (jtbl_004B1E50, case 0x00141824), steps 0x10-byte keys from the pointer at object +0x10
 * and compares the next key's s16 time against -1 to end the track. */
typedef struct { s16 time; s16 angle; f32 pos[3]; } PosRotKey;
typedef char PosRotKey_size_check[(sizeof(PosRotKey) == 16) ? 1 : -1];
PosRotKey data_track_00441790[4] = {
    { 0, 90, { 7.0f, 0.5f, -14.0f } },
    { 10, 0, { 9.98f, 0.5f, -14.5f } },
    { 15, 0, { 9.98f, 0.5f, -14.5f } },
    { -1, 0, { 9.98f, 0.5f, -14.5f } },
};
