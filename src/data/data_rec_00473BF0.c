typedef unsigned char u8;
typedef unsigned short u16;
/* func_003AE960 stores &D_00473BF0 to actor+0x164; the reader then loads lhu 0x12 from the
 * pointee (same shape as the D_00473320 descriptor). Other bytes have no reader (zero). */
typedef struct {
    u8 unk_00[0x12];
    u16 h12;
    u8 unk_14[0xC];
} Data00473BF0;
typedef char Data00473BF0_size_check[(sizeof(Data00473BF0) == 0x20) ? 1 : -1];
Data00473BF0 data_rec_00473BF0 = { { 0 }, 0x002E, { 0 } };
