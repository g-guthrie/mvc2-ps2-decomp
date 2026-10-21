#ifndef HTCI_FILE_REQUEST_H
#define HTCI_FILE_REQUEST_H
typedef struct HtciFileRequest {
    signed char slot_state;             /* +0: 0 free, 1 active */
    unsigned char open_flag;            /* +1: 0 direct handle closed on release, 1 cached handle preserved */
    signed char operation_state;        /* +2: native request state */
    unsigned char unknown_03_07[5];     /* +3..+7: opaque bytes, not inferred padding */
    unsigned long long file_size;       /* +8: byte size */
    signed int file_block_count_10;     /* +0x10: ceil(file_size / 0x800) */
    signed int result_14;               /* +0x14: result/status output */
    signed int file_handle_18;          /* +0x18: underlying file handle */
    signed int progress_blocks_1c;      /* +0x1C: current block position */
    void *request_buffer_20;             /* +0x20: buffer argument for async read */
    signed int requested_blocks_24;    /* +0x24: requested block count */
    signed int completed_blocks_28;    /* +0x28: completed block count */
    signed int request_handle_2c;       /* +0x2C: asynchronous request handle */
} HtciFileRequest;
#endif
