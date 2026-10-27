#ifndef SONY_PAD_SLOT_H
#define SONY_PAD_SLOT_H
typedef struct SonyPadSlot {
    unsigned char *buffer;
    unsigned char *command;
    unsigned char *dma_destination;
    int dma_id;
    int enabled;
    int tail[2];
} SonyPadSlot;
extern SonyPadSlot D_004C83D0[][4];
#endif
