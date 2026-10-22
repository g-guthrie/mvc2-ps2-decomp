typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

/* No direct reader found; this 16-byte shape is shared by four units:
 * u16 id, s16 count, three f32. */
typedef struct {
    u16 id;
    s16 n;
    f32 f[3];
} Rec16;
typedef char Rec16_size_check[(sizeof(Rec16) == 16) ? 1 : -1];

Rec16 data_u32_00442EDC = {
    0x0071u, -252,
    {0.0f, 0.0f, -0.00999999978f}
};
