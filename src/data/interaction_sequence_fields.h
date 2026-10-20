typedef unsigned char u8;
typedef unsigned short u16;

/* Native func_001893E0 consumes sequenceCount ordered masks, then passes the
 * completed index unchanged to func_00189500 for one terminal mask. The
 * caller-selected D_00448F10 callbacks read the same header: predicateFlags
 * at +2, ownerKey's low byte at +4, postAcceptFlags at +6, and masks from +8.
 * Byte +5 is not read by these consumers and is deliberately kept in a raw
 * source unit. */
#pragma pack(1)
typedef struct {
    u16 sequenceCount;
    u16 predicateFlags;
    u8 ownerKey;
} InteractionSequenceHeader;
#pragma pack()

typedef struct {
    u16 postAcceptFlags;
    u16 masks[4];
} InteractionSequencePayload3;

typedef struct {
    u16 postAcceptFlags;
    u16 masks[6];
} InteractionSequencePayload5;
