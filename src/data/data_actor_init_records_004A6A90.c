typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
/* Indexed by the actor byte +0x20 (sll 4) in the initialisers at 0x0041A1F0 and
 * 0x0041A4C0: x00/y04 are loaded with lwc1 and converted with cvt.s.w, h08/h0A
 * with lh, b0C/b0D with lbu. Bytes 0x0E..0x0F are not read. */
typedef struct {
    s32 x00;
    s32 y04;
    s16 h08;
    s16 h0A;
    u8 b0C;
    u8 b0D;
    u8 pad0E[2];
} ActorInitRecord;
typedef char ActorInitRecord_size_check[(sizeof(ActorInitRecord) == 16) ? 1 : -1];
ActorInitRecord data_actor_init_records_004A6A90[3] = {
    { -655360, 0, -47, 45, 0x11u, 0x40u, { 0, 0 } },
    { -655360, 0, 3, 92, 0x0Fu, 0x41u, { 0, 0 } },
    { -655360, 0, 36, 41, 0x0Du, 0x42u, { 0, 0 } },
};
