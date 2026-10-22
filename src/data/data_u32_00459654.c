typedef unsigned char u8;
typedef unsigned short u16;
/* 4-byte entry: arg = D_00459630[idx*4] (passed to func_001757E0), cmd = D_00459632[idx*2]
   (added to the command number in func_002BD190). */
typedef struct { u8 arg; u8 pad; u16 cmd; } AnimEntry;
typedef char AnimEntry_size_check[(sizeof(AnimEntry) == 4) ? 1 : -1];
AnimEntry data_u32_00459654[3] = {
    { 0x08, 0, 0x004F },
    { 0x08, 0, 0x004F },
    { 0x08, 0, 0x004F }
};
