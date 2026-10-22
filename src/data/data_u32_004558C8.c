/* Interaction descriptors read through func_00189310 and func_00189950 (src/y1_f.c, record_gates.c, init_indirect_state.c; func_00281320..func_002815B0). Two zero words precede the first descriptor and no reader references them. */
#include "interaction_sequence_fields.h"
typedef unsigned int u32;

typedef struct {
    InteractionSequenceHeader header;
    u8 unreadByte5;
    InteractionSequencePayload3 body;
} InteractionDescriptor16;

typedef struct {
    InteractionSequenceHeader header;
    u8 unreadByte5;
    u16 postAcceptFlags;
    u16 masks[8];
} InteractionDescriptor24;

typedef struct {
    InteractionSequenceHeader header;
    u8 unreadByte5;
    u16 postAcceptFlags;
    u16 masks[12];
} InteractionDescriptor32;

typedef struct {
    u32 unreadWords0[2];
    InteractionDescriptor32 desc1;
    InteractionDescriptor16 desc2;
    InteractionDescriptor32 desc3;
    InteractionDescriptor16 desc4;
    InteractionDescriptor16 desc5;
    InteractionDescriptor16 desc6;
    InteractionDescriptor16 desc7;
} InteractionDescriptorBlock152;

typedef char InteractionDescriptorBlock152_size_check[(sizeof(InteractionDescriptorBlock152) == 152) ? 1 : -1];

InteractionDescriptorBlock152 data_u32_004558C8 = {
    { 0x00000000u, 0x00000000u },
    { { 5, 0x1000u, 0 }, 0, 0x0000u, { 0x0400u, 0x1400u, 0x1000u, 0x1800u, 0x0800u, 0x0300u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u } },
    { { 3, 0x1000u, 1 }, 0, { 0x0000u, { 0x0800u, 0x1000u, 0x1800u, 0x0060u } } },
    { { 5, 0x1000u, 2 }, 0, 0x0000u, { 0x0800u, 0x1800u, 0x1000u, 0x1400u, 0x0400u, 0x0060u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u } },
    { { 3, 0x9100u, 3 }, 0, { 0x0000u, { 0x1000u, 0x1800u, 0x0800u, 0x0300u } } },
    { { 3, 0x9100u, 4 }, 0, { 0x0000u, { 0x1000u, 0x1800u, 0x0800u, 0x0060u } } },
    { { 3, 0x9100u, 5 }, 0, { 0x0000u, { 0x0800u, 0x1000u, 0x1800u, 0x0060u } } },
    { { 4, 0x000Au, 6 }, 0, { 0x0000u, { 0x0060u, 0x0000u, 0x0000u, 0x0000u } } }
};
