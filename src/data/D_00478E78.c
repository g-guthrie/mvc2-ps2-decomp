typedef signed char s8;
typedef signed int s32;
/* Eight 0x30-byte stream records (func_003F5F88 sets rate 44100), cleared as
 * one block with func_0011D8F8(D_00478E78, 0, 0x180) (src/s0b.c, src/sdk3f.c).
 * func_003F5F88 (src/r3_33_a.c) claims the first record whose s8 st is 0 and
 * writes st/b1/cnt (sb) and the s32 a[] entries (sw); func_003F6408
 * (src/w9s2.c) walks st with stride 0x30. Only the head is named. */
typedef struct {
    s8 st;
    s8 b1;
    s8 cnt;
    s8 pad3;
    s32 a0;
    unsigned char rest[0x28];
} StreamRecord;
typedef char StreamRecord_size_check[(sizeof(StreamRecord) == 0x30) ? 1 : -1];
StreamRecord D_00478E78[8] = { { 0 } };
