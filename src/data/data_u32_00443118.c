typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;
/* 20-byte record: halfword pair, three zero words, and an f32 tail value. */
typedef struct { u16 a; u16 b; u32 zero[3]; f32 e; } Param20;
typedef char Param20_size_check[(sizeof(Param20) == 20) ? 1 : -1];
Param20 data_u32_00443118[1] = {
    { 0x75u, 0xFF03u, { 0u, 0u, 0u }, -0.00999999978f },
};
