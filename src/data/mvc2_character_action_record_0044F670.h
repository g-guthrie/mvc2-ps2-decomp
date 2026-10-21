#ifndef MVC2_CHARACTER_ACTION_RECORD_0044F670_H
#define MVC2_CHARACTER_ACTION_RECORD_0044F670_H
typedef struct {
    void (*slot_00)(unsigned char *);
    void (*slot_01)(unsigned char *);
    void (*slot_02)(unsigned char *);
    void (*slot_03)(unsigned char *);
    void (*slot_04)(unsigned char *);
} Mvc2F670Slots0To4;
typedef struct {
    void (*slot_06)(unsigned char *);
    void (*slot_07)(unsigned char *);
    void (*slot_08)(unsigned char *);
} Mvc2F670Slots6To8;
typedef struct {
    void (*slot_10)(unsigned char *);
    void (*slot_11)(unsigned char *);
    void (*slot_12)(unsigned char *);
    int (*slot_13)(unsigned char *);
    void (*slot_14)(unsigned char *);
} Mvc2F670Slots10To14;
typedef struct {
    void (*slot_16)(unsigned char *);
    void (*slot_17)(unsigned char *);
    void (*slot_18)(unsigned char *);
    void (*slot_19)(unsigned char *);
} Mvc2F670Slots16To19;
/* Only recovered slot runs are callable views. Unknown slots remain bytes. */
typedef struct {
    Mvc2F670Slots0To4 slots_00_04;
    unsigned char raw_slot_05[4];
    Mvc2F670Slots6To8 slots_06_08;
    unsigned char raw_slot_09[4];
    Mvc2F670Slots10To14 slots_10_14;
    unsigned char raw_slot_15[4];
    Mvc2F670Slots16To19 slots_16_19;
} Mvc2F670Prefix80;
typedef union {
    struct { Mvc2F670Prefix80 prefix; unsigned char tail_bytes[32]; } fields;
    unsigned int copy_words[28];
} Mvc2F670Source112View;
typedef char F670Prefix_size80[(sizeof(Mvc2F670Prefix80)==80)?1:-1];
typedef char F670Source_size112[(sizeof(Mvc2F670Source112View)==112)?1:-1];
extern const Mvc2F670Source112View D_0044F670;
extern const Mvc2F670Slots0To4 jtbl_0044F670;
extern const Mvc2F670Slots6To8 data_callback_fields_0044F688;
extern const Mvc2F670Slots10To14 data_callback_fields_0044F698;
extern const Mvc2F670Slots16To19 data_callback_fields_0044F6B0;
extern unsigned char data_callback_raw_0044F684[4];
extern unsigned char data_callback_raw_0044F694[4];
extern unsigned char data_callback_raw_0044F6AC[4];
#endif
