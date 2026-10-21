#ifndef MVC2_RUNTIME_RESOURCE_RECORD_H
#define MVC2_RUNTIME_RESOURCE_RECORD_H

/* Serialized records hold a relative offset; relocation turns it into a pointer. */
typedef union ResourcePayload {
    void *data;
    unsigned int offset;
} ResourcePayload;

typedef struct ResourceRecord {
    short id;
    unsigned short type;
    unsigned int flags;
    ResourcePayload payload;
    int attributes;
} ResourceRecord;

typedef struct ResourceRecordPair {
    ResourceRecord records[2];
} ResourceRecordPair;

typedef char ResourceRecord_size_check[sizeof(ResourceRecord) == 16 ? 1 : -1];
typedef char ResourceRecordPair_size_check[sizeof(ResourceRecordPair) == 32 ? 1 : -1];

int func_00415020(int slot, ResourceRecord *records);
void func_0016F530(int slot, int group_address, unsigned int *roots,
                  ResourceRecord *records, int mode, int flags);
void func_0016F5B0(int slot, int group_address, unsigned int *roots,
                  ResourceRecord *records, int mode, int flags);

#endif
