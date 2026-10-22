/* Animation step scripts: {frame, duration} pairs read by func_0041ABF0
   (frame is lb, duration is lbu; duration 0xFF holds the step). */
typedef signed char s8;
typedef unsigned char u8;
typedef struct { s8 frame; u8 duration; } AnimStep;
typedef char AnimStep_size_check[(sizeof(AnimStep) == 2) ? 1 : -1];
AnimStep data_u32_004A6BDC[10] = {
    {0, 1}, {0, 255}, {2, 2}, {1, 1},
    {0, 1}, {15, 1}, {14, 1}, {13, 1},
    {12, 255}, {0, 1},
};
