#ifndef MVC2_INTERACTION_FILTER_HEADER_H
#define MVC2_INTERACTION_FILTER_HEADER_H
typedef unsigned short u16;
typedef struct InteractionFilterHeader {
    u16 stateCount;
    u16 conditionFlags;
} InteractionFilterHeader;
#endif
