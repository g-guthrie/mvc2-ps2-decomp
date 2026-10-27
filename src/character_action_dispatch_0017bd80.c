/* Provisional: action-record ownership and callback ABI require proof. */
#include "data/mvc2_character_action_record_0044F2E0.h"
void func_0017BD80(unsigned char *p) {
    Mvc2CharacterActionRecord112View *record = *(Mvc2CharacterActionRecord112View **)(p + 0x43c);
    record->fields.callbacks.slot_08(p);
}

void func_0017BD90(unsigned char *p) {
    Mvc2CharacterActionRecord112View *record = *(Mvc2CharacterActionRecord112View **)(p + 0x43c);
    record->fields.callbacks.slot_07(p);
}
