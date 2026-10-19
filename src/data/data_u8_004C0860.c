typedef unsigned char u8;
#include "profile_bytecode.h"

/* Each opcode 2 consumes its operand and writes owner+0x45C. */
u8 data_u8_004C0860[5] = {
    PROFILE_OPCODE_WRITE_FIELD_045C, 1,
    PROFILE_OPCODE_WRITE_FIELD_045C, 2,
    PROFILE_RESET_VALUE
};
