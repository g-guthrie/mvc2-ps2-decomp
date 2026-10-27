#ifndef SONY_CONSOLE_RING_H
#define SONY_CONSOLE_RING_H
typedef struct SonyConsoleRing {
    unsigned int size;
    int count;
    char *head;
    char *tail;
} SonyConsoleRing;
#endif
