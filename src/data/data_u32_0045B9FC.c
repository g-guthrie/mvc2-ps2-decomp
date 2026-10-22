/* Interaction descriptors read through func_00189310: the owner pointers are
   D_0045BA00 + 16*k for k = 0..7 (readers in conditional_engine_chains.c, y13_d.c, t9_d.c).
   Four lead bytes precede them and no reader references them. */
#include "interaction_sequence_fields.h"

typedef struct {
    InteractionSequenceHeader header;
    u8 unreadByte5;
    InteractionSequencePayload3 body;
} InteractionDescriptor16;

typedef struct {
    u8 leadBytes[4];
    InteractionDescriptor16 desc[8];
} data_u32_0045B9FC_t;

typedef char data_u32_0045B9FC_size_check[(sizeof(data_u32_0045B9FC_t) == 132) ? 1 : -1];

data_u32_0045B9FC_t data_u32_0045B9FC = {
    { 0x00, 0x00, 0x00, 0x00 },
    {
    { { 3, 0x9100u, 0x00 }, 0x00, { 0x0000u, { 0x1000u, 0x1400u, 0x0400u, 0x0300u } } },
    { { 3, 0xA100u, 0x0A }, 0x00, { 0x0000u, { 0x1000u, 0x1400u, 0x0400u, 0x0300u } } },
    { { 3, 0x0000u, 0x02 }, 0x00, { 0x0000u, { 0x1000u, 0x1800u, 0x0800u, 0x0300u } } },
    { { 3, 0x8000u, 0x0D }, 0x00, { 0x0000u, { 0x1000u, 0x1800u, 0x0800u, 0x0300u } } },
    { { 3, 0x2000u, 0x03 }, 0x00, { 0x0000u, { 0x1000u, 0x1800u, 0x0800u, 0x0060u } } },
    { { 3, 0xA000u, 0x0E }, 0x00, { 0x0000u, { 0x1000u, 0x1800u, 0x0800u, 0x0060u } } },
    { { 3, 0x1000u, 0x04 }, 0x00, { 0x0000u, { 0x1000u, 0x1800u, 0x0800u, 0x0060u } } },
    { { 3, 0x9000u, 0x0F }, 0x00, { 0x0000u, { 0x1000u, 0x1800u, 0x0800u, 0x0060u } } }
    }
};
