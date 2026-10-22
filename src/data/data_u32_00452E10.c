/* Interaction descriptors read through func_00189310 (src/accepted_transition_resets.c). */
#include "interaction_sequence_fields.h"

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
    InteractionDescriptor16 desc0;
    InteractionDescriptor16 desc1;
    InteractionDescriptor16 desc2;
    InteractionDescriptor16 desc3;
    InteractionDescriptor16 desc4;
} InteractionDescriptorBlock80;

typedef char InteractionDescriptorBlock80_size_check[(sizeof(InteractionDescriptorBlock80) == 80) ? 1 : -1];

InteractionDescriptorBlock80 data_u32_00452E10 = {
    { { 3, 0x0000u, 0 }, 0, { 0x0000u, { 0x1000u, 0x1800u, 0x0800u, 0x0060u } } },
    { { 3, 0x1000u, 1 }, 0, { 0x0000u, { 0x1000u, 0x1800u, 0x0800u, 0x0300u } } },
    { { 3, 0x1000u, 2 }, 0, { 0x0000u, { 0x0800u, 0x1000u, 0x1800u, 0x0300u } } },
    { { 3, 0x9100u, 4 }, 0, { 0x0000u, { 0x1000u, 0x1400u, 0x0400u, 0x0300u } } },
    { { 3, 0x9100u, 5 }, 0, { 0x0000u, { 0x1000u, 0x1800u, 0x0800u, 0x0300u } } }
};
