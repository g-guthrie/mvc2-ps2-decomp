typedef signed char s8;
typedef signed int s32;
/* First 8 bytes of record 0 of D_00478E78, eight 0x30-byte stream records (func_003F5F88 sets rate 44100) cleared with
 * func_0011D8F8(D_00478E78, 0, 0x180) (src/s0b.c, src/sdk3f.c). func_003F5F88
 * (src/r3_33_a.c) claims the first record whose s8 st is 0 and writes st/b1/cnt (sb) and
 * the s32 a[] entries (sw); func_003F6408 (src/w9s2.c) walks st with stride 0x30. The rest of
 * the record and records 1..7 continue in data_zero_00478E80. */
typedef struct {
    s8 st;
    s8 b1;
    s8 cnt;
    s8 pad3;
    s32 a0;
} StreamRecordHead;
typedef char StreamRecordHead_size_check[(sizeof(StreamRecordHead) == 8) ? 1 : -1];
StreamRecordHead data_zero_00478E78 = { 0, 0, 0, 0, 0 };
