typedef unsigned char u8; typedef unsigned int u32;
typedef struct sceCdRMode { u8 trycount, spindlctrl, datapattern, pad; } sceCdRMode;
typedef struct CdvdReadRequest { u32 lbn; u32 sectors; void *destination; sceCdRMode mode; void *completion_data; void *current_position; } CdvdReadRequest;
typedef char request_size_is_0x18[(sizeof(CdvdReadRequest)==0x18)?1:-1];
CdvdReadRequest data_cdvd_read_request_00439A80 = { 0 };
