#ifndef MVC2_INTERACTION_OWNER_TAG_H
#define MVC2_INTERACTION_OWNER_TAG_H
typedef unsigned char u8;
/* Bytes +4..+7 of an interaction descriptor (header at +0, state masks at +8).
 * The filtered dispatchers (func_00189310 and siblings) and func_0018A460-gated
 * paths read only +4 (lbu, compared with the actor's s8 owner slot at +0x45C).
 * +5..+7 have no reader and are zero in every retail descriptor. */
typedef struct InteractionOwnerTag {
    u8 ownerTag;
    u8 unread[3];
} InteractionOwnerTag;
#endif
