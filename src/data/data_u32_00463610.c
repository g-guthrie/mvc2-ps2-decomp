typedef int s32;
typedef signed short s16;
typedef struct { s32 x; s32 y; s16 dx; s16 dy; s16 a; s16 b; } Fixed16Record;
typedef char Fixed16Record_size_check[(sizeof(Fixed16Record) == 16) ? 1 : -1];
/* x, y are 16.16 fixed point. */
Fixed16Record data_u32_00463610 = { -655360, -204800, -96, 96, 11, 12320 };
