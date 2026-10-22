typedef unsigned char u8;
typedef signed int s32;
typedef float f32;
#pragma pack(1)
/* Tail bytes of the u8 table D_0045EEA8, then f32 rows D_0045EEC0/D_0045EED0 (stride 24, lwc1), the f32 triple
   D_0045EF08, a zero word, and the first s32 slots of D_0045EF18 (lh, indexed by id * 4). */
struct {
    u8 pad0[9];
    f32 rows[3][6];
    f32 vec[3];
    s32 zero0;
    s32 frame[3];
    s32 zero1[3];
} data_raw_0045EEB7 = {
    { 0 },
    { { -1420.0f, 2130.0f, -1380.0f, -1420.0f, -370.0f, -1380.0f },
      { -1360.0f, 1920.0f, -1430.0f, -1360.0f, -150.0f, -1430.0f },
      { -1500.0f, 1800.0f, -1420.0f, -1500.0f, -360.0f, -1420.0f } },
    { -1.0f, -0.699999988f, -0.5f },
    0,
    { 9, 16, 23 },
    { 0, 0, 0 }
};
typedef char data_raw_0045EEB7_size_check[(sizeof(data_raw_0045EEB7) == 121) ? 1 : -1];
