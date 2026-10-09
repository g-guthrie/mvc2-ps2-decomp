/* sn_runtime_leaves.c reads and returns this Runtime pointer. */
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct Runtime {
    u8 pad[0xA8];
    u64 value;
} Runtime;

extern u32 data_u32_0043B3F0[];
Runtime *data_ptr_0043B6F8[1] = {
    (Runtime *)(data_u32_0043B3F0 + 6),
};
