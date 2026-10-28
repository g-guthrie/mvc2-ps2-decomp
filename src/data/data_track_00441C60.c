typedef signed short s16;
typedef signed int s32;
typedef float f32;
/* Head key of the event-category-7 track (schedule event 0x27 at frame 1547 points here; the
 * pointer word is at 0x004424F0). The track is a run of 0x18-byte keys ending with a key whose
 * s16 time is -1 (at 0x00441CC0), the same terminator convention func_001415B0 uses for its
 * category 0..6 tracks. Field kinds follow the retail words of all five keys: +4 is always a
 * float (-13.0f, 20.0f), +8 an integer (0, 0xDC, 0xB7C, 0x168) and +0xC..+0x14 floats (1.0f,
 * 7.4f, 8.0f, 10.0f). Category 7 is outside func_001415B0's 0..6 switch and no reader of the
 * fields was found, so they are not named. Later keys continue at data_u32_00441C78. */
typedef struct {
    s16 time;
    s16 pad;
    f32 a;
    s32 b;
    f32 c[3];
} TrackKey18;
typedef char TrackKey18_size_check[(sizeof(TrackKey18) == 0x18) ? 1 : -1];
TrackKey18 data_track_00441C60 = { 0, 0, -13.0f, 0, { 1.0f, 1.0f, 1.0f } };
