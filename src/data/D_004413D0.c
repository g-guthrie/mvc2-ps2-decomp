typedef signed short s16;
typedef float f32;
/* Keyframe track, event category 1 (position): func_001415B0 switches on object +0x20
 * (jtbl_004B1E50, case 0x001417A4), steps 0x10-byte keys from the pointer at object +0x10
 * and compares the next key's s16 time against -1 to end the track. */
typedef struct { s16 time; s16 pad; f32 pos[3]; } PosKey;
typedef char PosKey_size_check[(sizeof(PosKey) == 16) ? 1 : -1];
PosKey D_004413D0[4] = {
    { 0, 0, { 0.0f, 0.0f, -4.0f } },
    { 15, 0, { 0.0f, 0.0f, -15.0f } },
    { 240, 0, { 0.0f, 0.0f, -15.0f } },
    { -1, 0, { 0.0f, 0.0f, -15.0f } },
};
