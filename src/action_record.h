#ifndef MVC2_ACTION_RECORD_H
#define MVC2_ACTION_RECORD_H

typedef struct Mvc2ActionRecord {
    unsigned char delay;
    unsigned char mode;
    unsigned char source_frame;
    unsigned char copy_count;
    signed int cursor_stride;
} Mvc2ActionRecord;

typedef char Mvc2ActionRecord_must_be_8_bytes[sizeof(Mvc2ActionRecord) == 8 ? 1 : -1];

#endif
