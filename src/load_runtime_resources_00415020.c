typedef struct ResourceRecord { short id; unsigned short type; unsigned int flags; void *data; int attributes; } ResourceRecord;
typedef struct RuntimeEntrySlot { int handle; unsigned int state; } ResourceTag;
extern unsigned char D_0057ED70[];
extern unsigned int D_0057FB70[];
extern ResourceTag D_0057E570[];
extern int D_004C28A8, D_004C28A4;
extern int func_00415250(ResourceRecord *);
int func_00415020(int slot, ResourceRecord *record)
{
    unsigned char *destination = D_0057ED70 + slot;
    for (; record->id > 0; ++destination, ++record, ++D_004C28A8) {
        int handle;
        int resource_index;
        if ((signed char)*destination != -1) return -1;
        if (D_004C28A8 == 4096) return -1;
        handle = func_00415250(record);
        resource_index = D_004C28A8;
        D_0057FB70[resource_index] = handle;
        if (record->flags & 0xf0) {
            ResourceTag *tag;
            if (D_004C28A4 == 256) return -1;
            tag = &D_0057E570[D_004C28A4];
            if (tag->handle != -1) return -1;
            tag->handle = D_0057FB70[resource_index];
            tag->state = (unsigned int)(record->attributes >> 16);
            ++D_004C28A4;
        }
        *destination = resource_index;
    }
    return 0;
}
