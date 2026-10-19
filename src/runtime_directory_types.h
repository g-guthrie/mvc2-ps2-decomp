#ifndef MVC2_RUNTIME_DIRECTORY_TYPES_H
#define MVC2_RUNTIME_DIRECTORY_TYPES_H

/* Names follow span_count descriptor/length pairs in the directory buffer. */
typedef struct RuntimeDirectoryEntry {
    int descriptor;
    int length;
} RuntimeDirectoryEntry;

typedef struct RuntimeDirectory {
    unsigned char *entries;
    unsigned int count;
    int span_count;
    int name_length;
} RuntimeDirectory;

extern RuntimeDirectory D_004895C0;

#endif
