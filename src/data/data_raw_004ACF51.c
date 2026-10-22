typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
/* 11-byte record, layout taken from the bytes (reader not traced): u8 a[3], pad, u8 b[3], then four u8 fields. */
typedef struct { u8 ids[3]; u8 pad0; u8 seq[3]; u8 f0; u8 f1; u8 f2; u8 f3; } Rec11;
typedef char Rec11_size[(sizeof(Rec11)==11)?1:-1];
Rec11 data_raw_004ACF51 = {
    { 0x0Cu, 0x0Du, 0x0Eu }, 0x00u, { 0x01u, 0x02u, 0x00u }, 0x02u, 0x15u, 0x00u, 0x00u,
};
