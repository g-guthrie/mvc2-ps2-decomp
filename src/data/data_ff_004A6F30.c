/* Terminator entry of a 0x10-byte command-entry list (func_00415020 stops when
   the leading s16 is <= 0); the list is copied as a 32-byte template. */
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef struct { s16 id; s16 b; u32 flags; s32 c; s32 d; } CmdEntry;
typedef char CmdEntry_size_check[(sizeof(CmdEntry) == 16) ? 1 : -1];
CmdEntry data_ff_004A6F30[1] = {
    { -1, -1, 0xFFFFFFFFu, -1, -1 },
};
