#ifndef RUNTIME_ENTRY_TABLE_H
#define RUNTIME_ENTRY_TABLE_H

typedef signed char RuntimeS8;
typedef unsigned char RuntimeU8;
typedef signed int RuntimeS32;

/* One 64-byte record in an outer runtime-entry slot. */
typedef struct RuntimeEntryRecord {
    RuntimeS32 key;
    char name[0x28];
    RuntimeS32 argument_2c;
    RuntimeS32 argument_30;
    RuntimeS32 argument_34;
    RuntimeS32 word_38;
    RuntimeS32 value_3c;
} RuntimeEntryRecord;

/* A slot has a 0x38-byte control prefix followed by sixteen records. */
typedef struct RuntimeEntrySlot {
    RuntimeS8 in_use;
    RuntimeU8 reserved_01;
    RuntimeS8 state_02;
    RuntimeU8 reserved_03_07[5];
    RuntimeS32 argument_08;
    RuntimeU8 reserved_0c_13[8];
    RuntimeS32 argument_14;
    RuntimeS32 argument_18;
    RuntimeU8 reserved_1c_1f[4];
    RuntimeS32 record_index;
    RuntimeS32 remaining;
    RuntimeS32 handle;
    RuntimeS32 scaled_size;
    RuntimeU8 reserved_30_37[8];
    RuntimeEntryRecord records[16];
} RuntimeEntrySlot;

typedef char RuntimeEntryRecord_size_check[
    sizeof(RuntimeEntryRecord) == 0x40 ? 1 : -1];
typedef char RuntimeEntrySlot_size_check[
    sizeof(RuntimeEntrySlot) == 0x438 ? 1 : -1];

#endif
