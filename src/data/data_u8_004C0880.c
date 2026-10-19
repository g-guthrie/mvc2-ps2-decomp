typedef unsigned char u8;
#include "profile_bytecode.h"

/* Opcode 1 consumes 0x32 and writes owner+0x472. */
u8 data_u8_004C0880[3] = {
    PROFILE_OPCODE_WRITE_FIELD_0472, 0x32, PROFILE_RESET_VALUE
};
