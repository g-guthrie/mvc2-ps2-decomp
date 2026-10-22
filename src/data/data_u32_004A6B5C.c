/* Animation step scripts: {frame, duration} pairs read by func_0041ABF0
   (frame is lb, duration is lbu; duration 0xFF holds the step). */
typedef signed char s8;
typedef unsigned char u8;
typedef struct { s8 frame; u8 duration; } AnimStep;
typedef char AnimStep_size_check[(sizeof(AnimStep) == 2) ? 1 : -1];
AnimStep data_u32_004A6B5C[22] = {
    {0, 1}, {0, 255}, {13, 4}, {14, 4},
    {15, 4}, {0, 1}, {1, 1}, {2, 1},
    {3, 1}, {4, 1}, {5, 1}, {6, 1},
    {7, 1}, {8, 1}, {9, 1}, {10, 1},
    {11, 1}, {12, 255}, {11, 4}, {10, 6},
    {11, 4}, {12, 255},
};
