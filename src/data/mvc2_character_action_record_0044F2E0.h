#ifndef MVC2_CHARACTER_ACTION_RECORD_0044F2E0_H
#define MVC2_CHARACTER_ACTION_RECORD_0044F2E0_H
/* Native per-character callback prefix. Slot 13 is a returned predicate. */
typedef struct {
    void (*slot_00)(unsigned char *);
    void (*slot_01)(unsigned char *);
    void (*slot_02)(unsigned char *);
    void (*slot_03)(unsigned char *);
    void (*slot_04)(unsigned char *);
    void (*slot_05)(unsigned char *);
    void (*slot_06)(unsigned char *);
    void (*slot_07)(unsigned char *);
    void (*slot_08)(unsigned char *);
    void (*slot_09)(unsigned char *);
    void (*slot_10)(unsigned char *);
    void (*slot_11)(unsigned char *);
    void (*slot_12)(unsigned char *);
    int (*slot_13)(unsigned char *);
    void (*slot_14)(unsigned char *);
    void (*slot_15)(unsigned char *);
    void (*slot_16)(unsigned char *);
    void (*slot_17)(unsigned char *);
    void (*slot_18)(unsigned char *);
    void (*slot_19)(unsigned char *);
} Mvc2CharacterActionPrefix80;
/* Copy representation of the complete native 28-word default record.
 * Tail bytes have no recovered callback contract and receive no DATA credit. */
typedef union {
    struct {
        Mvc2CharacterActionPrefix80 callbacks;
        unsigned char raw_tail[32];
    } fields;
    unsigned int copy_words[28];
} Mvc2CharacterActionRecord112View;
typedef char Mvc2ActionPrefix_size80[(sizeof(Mvc2CharacterActionPrefix80)==80)?1:-1];
typedef char Mvc2ActionRecord_size112[(sizeof(Mvc2CharacterActionRecord112View)==112)?1:-1];
/* D_ is the existing native full-record alias; jtbl_ is its emitted prefix. */
extern const Mvc2CharacterActionRecord112View D_0044F2E0;
extern const Mvc2CharacterActionPrefix80 jtbl_0044F2E0;
/* Shared live slot-zero protocol: actor passed even to this empty implementation. */
extern void func_001E9700(unsigned char *actor);
/* Same proven one-actor/predicate protocol for the next complete prefix. */
extern const Mvc2CharacterActionRecord112View D_0044FBD0;
extern const Mvc2CharacterActionPrefix80 jtbl_0044FBD0;
extern void func_001F7A90(unsigned char *actor);
#endif
