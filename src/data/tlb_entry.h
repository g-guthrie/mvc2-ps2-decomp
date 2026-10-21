typedef unsigned int u32;
typedef struct {
    u32 PageMask;
    u32 EntryHi;
    u32 EntryLo0;
    u32 EntryLo1;
} TLBEntry;
