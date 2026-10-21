#include "tlb_entry.h"
extern TLBEntry data_raw_004386E8[];
extern TLBEntry data_tlb_default_004387B8[];
extern TLBEntry data_tlb_extended_004388D8[];
typedef struct {
    u32 NumKernelTLBEntries;
    u32 NumDefaultTLBEntries;
    u32 NumExtendedTLBEntries;
    u32 NumWiredEntries;
    const TLBEntry *kernelTLB;
    const TLBEntry *defaultTLB;
    const TLBEntry *extendedTLB;
} TLBInfo;
TLBInfo data_tlb_info_00438958 = {
    13u, 18u, 8u, 0u,
    data_raw_004386E8, data_tlb_default_004387B8, data_tlb_extended_004388D8
};
