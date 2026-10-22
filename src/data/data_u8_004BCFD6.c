typedef unsigned char u8;
/* Two zero bytes, the 34-character message "cvFsMakeDir #2:illegal device name", then six zero bytes. */
typedef struct {
    u8 pad_00[2];
    char msg_02[34];
    u8 tail_24[6];
} data_u8_004BCFD6_t;
typedef char data_u8_004BCFD6_size_check[(sizeof(data_u8_004BCFD6_t) == 42) ? 1 : -1];

data_u8_004BCFD6_t data_u8_004BCFD6 = {
    { 0, 0 },
    { 'c','v','F','s','M','a','k','e','D','i','r',' ','#','2',':','i','l','l','e','g','a','l',' ','d','e','v','i','c','e',' ','n','a','m','e' },
    { 0, 0, 0, 0, 0, 0 },
};
