typedef signed char s8;
typedef unsigned char u8;
typedef signed int s32;
typedef unsigned int u32;

typedef struct {
    s8 active;
    u8 pad01[3];
    s32 count;
    void *resources[2];
    void *bindings[2];
    void *inputs[2];
    s32 remote;
    u8 flags24[4];
    s32 field28;
    s32 field2C;
    s32 field30;
    s32 field34;
    s32 offsets[2];
    s32 counts[2];
    u8 flag48;
    u8 flag49;
    u8 flag4A;
    u8 flag4B;
    s32 field4C;
    s32 total;
    s32 maximum;
} DecoderGroup;

/* Eight native decoder-group records, each 0x58 bytes. */
DecoderGroup data_decoder_group_pool_0048FD38[8] = { 0 };
