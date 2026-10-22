typedef int s32;

/* Eight 16.16 fixed-point values as (scale, -1/16) pairs. */
typedef struct {
    s32 scale;
    s32 offset;
} Fixed1616Pair;

typedef char Fixed1616Pair_size_check[(sizeof(Fixed1616Pair) == 8) ? 1 : -1];

Fixed1616Pair data_u32_0044F940[4] = {
    { 0x00040000, (s32)0xFFFFF000 },
    { 0x00080000, (s32)0xFFFFF000 },
    { 0x00010000, (s32)0xFFFFF000 },
    { 0x00030000, (s32)0xFFFFF000 },
};
