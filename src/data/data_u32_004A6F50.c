/* First entry of a 0x10-byte command-entry list (read by func_00415020:
   s16 at +0 > 0 marks a live entry, word at +4 tested with 0xF0, word at +0xC
   shifted right 16). Field b and d are not read there; names are guesses. */
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef struct { s16 id; s16 b; u32 flags; s32 c; s32 d; } CmdEntry;
typedef char CmdEntry_size_check[(sizeof(CmdEntry) == 16) ? 1 : -1];
CmdEntry data_u32_004A6F50[1] = {
    { 0x200, 0x100, 0x00010000u, 0, 0 },
};
