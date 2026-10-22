typedef float f32;
typedef struct { f32 x, y, z; } Float3;
typedef char Float3_size_check[(sizeof(Float3) == 12) ? 1 : -1];
/* Selector 1 is not passed to the component columns. */
Float3 data_raw_0044065C = { 227.81f, -52.74f, -140.94f };
