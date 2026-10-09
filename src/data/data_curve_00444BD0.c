/* The field-5 curve uses selector 0. func_001568A0 allocates a zeroed callback object with fields 4 and 5 left at 0; func_00156930 calls the helper only for time values 0..4, below this record endpoint 5. */
typedef int s32;
typedef float f32;
typedef struct { s32 startFrame; f32 startValue; s32 endFrame; f32 endValue; } Curve;
Curve data_curve_00444BD0 = { 0, 1.0f, 5, 0.1f };
