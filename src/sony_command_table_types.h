#ifndef MVC2_SONY_COMMAND_TABLE_TYPES_H
#define MVC2_SONY_COMMAND_TABLE_TYPES_H
typedef void (*SonyCommandHandler)(void *, void *);
typedef struct SonyCommandEntry {
    SonyCommandHandler handler;
    void *argument;
} SonyCommandEntry;
extern SonyCommandEntry *D_004C3AE4, *D_004C3AEC;
void func_00106240(unsigned int id, SonyCommandHandler handler, void *argument);
void func_00106270(unsigned int id);
#endif
