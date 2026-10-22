/* Animation step scripts: {frame, duration} pairs read by func_0041ABF0
   (frame is lb, duration is lbu; duration 0xFF holds the step). */
typedef signed char s8;
typedef unsigned char u8;
typedef struct { s8 frame; u8 duration; } AnimStep;
typedef char AnimStep_size_check[(sizeof(AnimStep) == 2) ? 1 : -1];
AnimStep data_u32_004A6C70[6] = {
    {0, 1}, {0, 1}, {0, 1}, {0, 1},
    {0, 1}, {0, 1},
};
