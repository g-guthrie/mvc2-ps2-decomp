/* 208-byte table: 17 colour records followed by one u32 word.
   Record fields are the ones read by func_003D1040 in src/grok_ad_003D1040.c
   (a = id, -1 ends the entry, b = scale, pad/r/g/bl = colour). */
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef float f32;
typedef struct Rec { s32 a; f32 b; u8 pad; u8 r, g, bl; } Rec;
typedef struct Table208 { Rec recs[17]; u32 tail; } Table208;
typedef char data_u32_00477060_size_check[(sizeof(Table208) == 208) ? 1 : -1];
Table208 data_u32_00477060 = {
    {
        { 82, 12000.0f, 0x00u, 0x80u, 0x94u, 0xA6u },
        { 7, 1300000.0f, 0x00u, 0xB3u, 0x8Cu, 0x99u },
        { -1, 0.0f, 0x00u, 0x7Fu, 0x7Fu, 0x7Fu },
        { -1, 0.0f, 0x00u, 0x7Fu, 0x7Fu, 0x7Fu },
        { 128, 5000.0f, 0x00u, 0xFFu, 0xFFu, 0xD8u },
        { 64, 40000.0f, 0x00u, 0x22u, 0x22u, 0x4Bu },
        { 45, 130000.0f, 0x00u, 0x8Fu, 0x8Fu, 0xCFu },
        { 110, 1260000.0f, 0x00u, 0xCBu, 0x51u, 0x46u },
        { 115, 47000.0f, 0x00u, 0x00u, 0x00u, 0x00u },
        { -1, 400000.0f, 0x00u, 0x80u, 0x94u, 0xA6u },
        { 7, 1300000.0f, 0x00u, 0xFFu, 0xE6u, 0xC0u },
        { -1, 0.0f, 0x00u, 0x7Fu, 0x7Fu, 0x7Fu },
        { -1, 0.0f, 0x00u, 0x7Fu, 0x7Fu, 0x7Fu },
        { -1, 19000.0f, 0x00u, 0xFFu, 0x80u, 0xC0u },
        { 64, 40000.0f, 0x00u, 0x20u, 0x10u, 0x10u },
        { 64, 100000.0f, 0x00u, 0x80u, 0x80u, 0x80u },
        { 35, 130000.0f, 0x00u, 0xE5u, 0xDBu, 0xCAu },
    },
    0x00000000u,
};
