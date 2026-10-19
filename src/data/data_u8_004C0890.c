typedef unsigned char u8;
#include "profile_bytecode.h"

/* Opcode 1 consumes 0x1E; opcode 2 consumes 1; 0x63 takes the reset path. */
u8 data_u8_004C0890[5] = {
    PROFILE_OPCODE_WRITE_FIELD_0472, 0x1E,
    PROFILE_OPCODE_WRITE_FIELD_045C, 1,
    PROFILE_RESET_VALUE
};
