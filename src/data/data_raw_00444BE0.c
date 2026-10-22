typedef unsigned int u32;
typedef float f32;
typedef struct { u32 ids[6]; u32 pad[2]; f32 tail; } Rec36;
typedef char Rec36_size_check[(sizeof(Rec36) == 36) ? 1 : -1];
/* func_00156A40 uses this block at 0x00444BE0 and the float at 0x00444C00. */
Rec36 data_raw_00444BE0 = {
    { 108, 109, 110, 111, 112, 113 },
    { 0, 0 },
    0.5f,
};
