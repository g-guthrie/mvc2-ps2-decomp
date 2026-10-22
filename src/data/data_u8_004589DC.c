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

/* Unit starts 4 bytes before D_004589E0 (zero tail of the preceding table).
   tab[stance(p+0x1FC)*4 + p[0x212]*12] is a 4-byte move-code row; the pointer
   is stored at p+0x408 by func_002AC6B0 / func_002AC830.  The record list is
   passed to func_00189310 (D_00458A40.. and D_00458B60); the f32 tail is read
   as a 4-float block at D_00458B80. */
typedef struct {
    u8 lead_pad[4];
    s8 tab_E0[2][3][4];  u8 pad_F8[8];
    s8 tab_A00[2][3][4]; u8 pad_A18[8];
    s8 tab_A20[2][3][4]; u8 pad_A38[8];
    TransRec16 recs[18];
    TransRec32 last;
    f32 consts[4];
} T_data_u8_004589DC;
typedef char T_data_u8_004589DC_size_check[(sizeof(T_data_u8_004589DC) == 436) ? 1 : -1];
T_data_u8_004589DC data_u8_004589DC = {
    {0,0,0,0},
    { { { 1, 2, 1, 2 },
      { -1, 2, -1, 2 },
      { -1, -1, -1, -1 } },
    { { 1, 2, 1, 2 },
      { -1, 2, -1, 2 },
      { -1, -1, -1, -1 } } }, {0},
    { { { 1, 2, 1, 2 },
      { -1, 2, -1, 2 },
      { -1, -1, -1, -1 } },
    { { 1, 2, 1, 2 },
      { -1, 2, -1, 2 },
      { -1, -1, -1, -1 } } }, {0},
    { { { 1, 2, 0, 2 },
      { -1, 2, 1, 2 },
      { -1, -1, -1, 2 } },
    { { 1, 2, 1, 2 },
      { -1, 2, -1, 2 },
      { -1, -1, -1, -1 } } }, {0},
    {
      { 0x03, 0, 0x0000, 0x00, {0,0,0}, { 0x18001000u, 0x03000800u } },
      { 0x03, 0, 0x0000, 0x0D, {0,0,0}, { 0x18001000u, 0x03000800u } },
      { 0x03, 0, 0x0000, 0x05, {0,0,0}, { 0x14001000u, 0x03000400u } },
      { 0x03, 0, 0x0000, 0x07, {0,0,0}, { 0x14001000u, 0x03000400u } },
      { 0x03, 0, 0x0000, 0x01, {0,0,0}, { 0x14001000u, 0x00600400u } },
      { 0x03, 0, 0x0000, 0x0C, {0,0,0}, { 0x14001000u, 0x00600400u } },
      { 0x03, 0, 0x9100, 0x06, {0,0,0}, { 0x18001000u, 0x03000800u } },
      { 0x03, 0, 0x9100, 0x08, {0,0,0}, { 0x14001000u, 0x03000400u } },
      { 0x03, 0, 0x9100, 0x0E, {0,0,0}, { 0x14001000u, 0x00600400u } },
      { 0x03, 0, 0x1100, 0x14, {0,0,0}, { 0x10000400u, 0x00401400u } },
      { 0x03, 0, 0x0000, 0x00, {0,0,0}, { 0x10000800u, 0x03001800u } },
      { 0x03, 0, 0x0000, 0x0D, {0,0,0}, { 0x10000800u, 0x03001800u } },
      { 0x03, 0, 0x0000, 0x05, {0,0,0}, { 0x18001000u, 0x03000800u } },
      { 0x03, 0, 0x0000, 0x07, {0,0,0}, { 0x18001000u, 0x03000800u } },
      { 0x03, 0, 0x9100, 0x06, {0,0,0}, { 0x18001000u, 0x00600800u } },
      { 0x03, 0, 0x9100, 0x0B, {0,0,0}, { 0x18001000u, 0x03000800u } },
      { 0x03, 0, 0x1000, 0x10, {0,0,0}, { 0x10000800u, 0x03601800u } },
      { 0x03, 0, 0x1000, 0x11, {0,0,0}, { 0x10000400u, 0x03601400u } }
    },
    { 0x04, 0, 0x1100, 0x12, {0,0,0}, { 0x02000200u, 0x00400800u, 0x00000100u }, {0,0,0} },
    { 6.66666651f, 8.5714283f, 10.0f, 18.75f }
};
