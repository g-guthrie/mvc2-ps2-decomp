typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

/* Used by the actor routine at func_0039FD90: the 8 offsets at +0x00 are
 * indexed by actor byte 0x20 (stride 4, y/x scaled by constants and added to
 * actor +0x34/+0x38); eight 32-byte rows at +0x20 (indexed by byte 0x20 << 5)
 * each hold four 8-byte entries picked by a 2-bit random value. */
typedef struct {
    s16 x;
    s16 y;
} Mvc2Offset;
typedef struct {
    s16 x;
    s16 y;
    s16 flip_mask;   /* xor-ed into actor +0x140 */
    u8 state;        /* passed to func_001757E0 */
    u8 pad;
} Mvc2OffsetStep;
typedef struct {
    Mvc2Offset offsets[8];
    Mvc2OffsetStep steps[8][4];
} Mvc2OffsetTable;
typedef char Mvc2OffsetTable_size_check[(sizeof(Mvc2OffsetTable) == 288) ? 1 : -1];
Mvc2OffsetTable data_u32_004728C0 = {
    {
        { 0, 128 },
        { 12, 112 },
        { 24, 88 },
        { 12, 60 },
        { 0, 32 },
        { -12, 60 },
        { -24, 88 },
        { -12, 112 },
    },
    {
        {
            { 0, 72, 0, 0x0B, 0 },
            { 0, 64, 0, 0x0C, 0 },
            { 0, 72, 1, 0x0B, 0 },
            { 0, 64, 1, 0x0C, 0 },
        },
        {
            { 80, 20, 0, 0x05, 0 },
            { 34, 44, 0, 0x07, 0 },
            { 64, 52, 0, 0x08, 0 },
            { 80, 32, 0, 0x09, 0 },
        },
        {
            { 80, 8, 1, 0x06, 0 },
            { 80, 12, 1, 0x0A, 0 },
            { 80, -8, 0, 0x1D, 0 },
            { 80, -12, 0, 0x21, 0 },
        },
        {
            { 80, -20, 1, 0x1C, 0 },
            { 34, -44, 1, 0x1E, 0 },
            { 64, -52, 1, 0x1F, 0 },
            { 80, -32, 1, 0x20, 0 },
        },
        {
            { 0, -72, 1, 0x22, 0 },
            { 0, -64, 1, 0x23, 0 },
            { 0, -72, 1, 0x22, 0 },
            { 0, -64, 1, 0x23, 0 },
        },
        {
            { -80, -20, 0, 0x1C, 0 },
            { -34, -44, 0, 0x1E, 0 },
            { -64, -52, 0, 0x1F, 0 },
            { -80, -32, 0, 0x20, 0 },
        },
        {
            { -80, 8, 0, 0x06, 0 },
            { -80, 12, 0, 0x0A, 0 },
            { -80, -8, 1, 0x1D, 0 },
            { -80, -12, 1, 0x21, 0 },
        },
        {
            { -80, 20, 1, 0x05, 0 },
            { -34, 44, 1, 0x07, 0 },
            { -64, 52, 1, 0x08, 0 },
            { -80, 32, 1, 0x09, 0 },
        },
    },
};
