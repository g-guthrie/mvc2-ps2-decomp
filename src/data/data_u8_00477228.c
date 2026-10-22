typedef signed int s32;
typedef float f32;

/* f32 0.98 then s32 -1 (identical in both copies). */
typedef struct {
    f32 scale;
    s32 mask;
} Rec_00477228;
typedef char Rec_00477228_size_check[(sizeof(Rec_00477228) == 8) ? 1 : -1];
Rec_00477228 data_u8_00477228 = { 0.980000019f, -1 };
