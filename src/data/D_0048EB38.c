typedef signed char s8;
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct {
    s8 used;
    u8 pad_01[3];
    void *resource;
    void *interface;
    void *stream;
    u32 streamOffset;
    u32 streamSize;
} ResourceRecord;
ResourceRecord D_0048EB38[16] = { { 0 } };
