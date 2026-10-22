/* Eight owner-keyed interaction descriptors (ownerKey 0..7 in order), read by
 * func_002034A0 and the func_00203560..func_00203970 family via D_004502C0+.
 * Each descriptor is header + unread byte +5 + postAcceptFlags (+6) + masks (+8);
 * masks[0..sequenceCount-1] are the ordered sequence masks and masks[sequenceCount]
 * is the terminal mask, see interaction_sequence_fields.h. */
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
    InteractionDescriptor24 desc4;
    InteractionDescriptor24 desc5;
    InteractionDescriptor32 desc6;
    InteractionDescriptor16 desc7;
} InteractionDescriptorBlock160;

typedef char InteractionDescriptor16_size_check[(sizeof(InteractionDescriptor16) == 16) ? 1 : -1];
typedef char InteractionDescriptor24_size_check[(sizeof(InteractionDescriptor24) == 24) ? 1 : -1];
typedef char InteractionDescriptor32_size_check[(sizeof(InteractionDescriptor32) == 32) ? 1 : -1];
typedef char InteractionDescriptorBlock160_size_check[(sizeof(InteractionDescriptorBlock160) == 160) ? 1 : -1];

InteractionDescriptorBlock160 data_u32_004502C0 = {
    { { 3, 0x0000u, 0 }, 0, { 0x0000u, { 0x1000u, 0x0000u, 0x1000u, 0x0360u } } },
    { { 3, 0x2000u, 1 }, 0, { 0x0000u, { 0x1000u, 0x1800u, 0x0800u, 0x0060u } } },
    { { 2, 0x0000u, 2 }, 0, { 0x0000u, { 0x0400u, 0x0800u, 0x0300u, 0x0000u } } },
    { { 3, 0x0000u, 3 }, 0, { 0x0000u, { 0x1000u, 0x1800u, 0x0800u, 0x0300u } } },
    { { 4, 0x0100u, 4 }, 0, 0x0000u, { 0x0020u, 0x0200u, 0x1000u, 0x0040u, 0x0100u, 0, 0, 0 } },
    { { 2, 0x8100u, 5 }, 0, 0x0000u, { 0x0400u, 0x0800u, 0x0300u, 0, 0, 0, 0, 0 } },
    { { 4, 0x1100u, 6 }, 0, 0x0000u, { 0x0200u, 0x0200u, 0x0800u, 0x0040u, 0x0100u, 0, 0, 0, 0, 0, 0, 0 } },
    { { 3, 0x8100u, 7 }, 0, { 0x0000u, { 0x1000u, 0x0000u, 0x1000u, 0x0300u } } },
};
