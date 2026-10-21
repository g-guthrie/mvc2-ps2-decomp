typedef struct CdReadCompletion {
 int first_count,second_count;
 unsigned char *first_destination,*second_destination;
 unsigned char first_bytes[64],second_bytes[64];
} CdReadCompletion;
typedef char completion_size_is_0x90[(sizeof(CdReadCompletion)==0x90)?1:-1];
CdReadCompletion data_cdvd_read_completion_0043AA80 = { 0 };
