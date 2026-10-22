typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
/* 16.16 fixed-point triplets (6 records), followed by two zero words. */
typedef struct { s32 a; s32 b; s32 c; } Fixed16Triple;
typedef struct { Fixed16Triple rec[6]; u32 tail[2]; } Fixed16Table;
typedef char Fixed16Table_size[(sizeof(Fixed16Table)==80)?1:-1];
Fixed16Table data_u32_00473D20 = {
  {
    { -294912, 4096, -12288 },
    { -425984, 6144, -12288 },
    { -557056, 8192, -12288 },
    { -327680, 4096, -8192 },
    { -458752, 6144, -8192 },
    { -589824, 8192, -8192 },
  },
  { 0x00000000u, 0x00000000u },
};
