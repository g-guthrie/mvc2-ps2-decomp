#ifndef HTCI_FILE_REQUEST_H
#define HTCI_FILE_REQUEST_H
typedef union HtciOpaqueWord {
    unsigned char bytes[4];
    signed int word;
} HtciOpaqueWord;
typedef struct HtciFileRequest {
    signed char slot_state;
    unsigned char open_flag;
    signed char operation_state;
    unsigned char raw_03_07[5];
    unsigned long long file_size;
    HtciOpaqueWord raw_10_13;
    signed int result_14;
    signed int file_handle_18;
    signed int progress_1c;
    HtciOpaqueWord raw_20_23;
    signed int requested_bytes_24;
    HtciOpaqueWord raw_28_2b;
    signed int request_handle_2c;
} HtciFileRequest;
#endif
