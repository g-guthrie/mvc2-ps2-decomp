/* func_00280AE0 dispatches values 0 through 10; other values reset state.
 * Opcodes 1 and 2 consume one operand and return the advanced cursor.
 * Other commands can continue parsing within the same call. */
enum {
    PROFILE_OPCODE_WRITE_FIELD_0472 = 1,
    PROFILE_OPCODE_WRITE_FIELD_045C = 2,
    PROFILE_RESET_VALUE = 0x63
};
