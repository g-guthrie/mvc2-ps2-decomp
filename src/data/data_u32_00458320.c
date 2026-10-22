typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;
/* Transition record read by func_00189310/func_0018A460: flags tested at +2,
   state tag compared with the actor byte at +4. */
typedef struct { u8 kind; u8 pad0; u16 flags; u8 tag; u8 pad1[3]; u32 w[2]; } TransRec16;
typedef struct { u8 kind; u8 pad0; u16 flags; u8 tag; u8 pad1[3]; u32 w[3]; u32 pad2[3]; } TransRec32;
typedef char TransRec16_size_check[(sizeof(TransRec16) == 16) ? 1 : -1];
typedef char TransRec32_size_check[(sizeof(TransRec32) == 32) ? 1 : -1];

/* Transition table passed to func_00189310 by func_002A0DE0. */
typedef struct {
    TransRec16 m1[4];
    TransRec32 m2[1];
    TransRec16 m3[3];
} T_data_u32_00458320;
typedef char T_data_u32_00458320_size_check[(sizeof(T_data_u32_00458320) == 144) ? 1 : -1];
T_data_u32_00458320 data_u32_00458320 = {
    { { 0x03, 0, 0x0000, 0x00, {0,0,0}, { 0x10000800u, 0x00601800u } },
      { 0x03, 0, 0x1000, 0x01, {0,0,0}, { 0x18001000u, 0x03000800u } },
      { 0x03, 0, 0x1000, 0x02, {0,0,0}, { 0x18001000u, 0x00600800u } },
      { 0x03, 0, 0x1000, 0x03, {0,0,0}, { 0x10000800u, 0x03001800u } } },
    { { 0x05, 0, 0x1000, 0x04, {0,0,0}, { 0x18000800u, 0x14001000u, 0x00600400u }, {0,0,0} } },
    { { 0x03, 0, 0x9100, 0x06, {0,0,0}, { 0x18001000u, 0x03000800u } },
      { 0x03, 0, 0x9100, 0x07, {0,0,0}, { 0x14001000u, 0x00600400u } },
      { 0x03, 0, 0x9100, 0x08, {0,0,0}, { 0x18001000u, 0x00600800u } } },
};
