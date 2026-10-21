typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;

typedef struct {
    u8 active_00;
    u8 unknown_01;
    u16 value_02;
    void *callback_object_04;
    s32 command_arg_08;
    s32 callback_arg_0C;
    s32 runtime_handle_10;
} RuntimeSlot20;

RuntimeSlot20 data_runtime_slots_00495BB8[32] = { 0 };
