typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

/* Indexed by p[0x21] in func_001DF7F0 (actor_emission_cycles_001CCF60.c). */
typedef struct {
    u16 count;
    u16 first_code;
} DropSequence;
typedef char DropSequence_size_check[(sizeof(DropSequence) == 4) ? 1 : -1];
DropSequence data_raw_0044EF10[4] = {
    { 1, 0x0300 },
    { 1, 0x0301 },
    { 2, 0x0302 },
    { 1, 0x0304 },
};
