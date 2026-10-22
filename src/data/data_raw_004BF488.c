typedef unsigned char u8;

extern const u8 D_00445E30[];
extern const u8 D_00445E50[];

/* Two pointers followed by 24 bytes; suffix after the signed-byte lookup at D_004BF484. */
typedef struct {
    const u8 *ptr[2];
    u8 bytes[24];
} Mvc2PtrBytes;
typedef char Mvc2PtrBytes_size_check[(sizeof(Mvc2PtrBytes) == 32) ? 1 : -1];
Mvc2PtrBytes data_raw_004BF488 = {
    { D_00445E30, D_00445E50 },
    { 0x00, 0x03, 0x01, 0x04, 0x02, 0x05, 0x00, 0x00,
      0x01, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x03, 0x01, 0x04, 0x02, 0x05, 0x00, 0x00 },
};
