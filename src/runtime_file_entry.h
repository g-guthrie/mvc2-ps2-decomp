#ifndef RUNTIME_FILE_ENTRY_H
#define RUNTIME_FILE_ENTRY_H

struct RuntimeFileOps;
typedef struct RuntimeFileEntry {
    struct RuntimeFileOps *r;
    int res;
} RuntimeFileEntry;

#endif
