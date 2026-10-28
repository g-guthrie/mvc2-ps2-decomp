/* Sixteen 0xB0-byte stream slots. func_003F7BB0 clears all 0xB00 bytes;
 * func_003F7C38 scans slot->state (lh, stride 0xB0, 16 slots), clears one slot and
 * fills the fields below; func_003F7BE8/func_003F7C18 read 0x18/0x3C/0x40/0x88/0x8C;
 * func_003F88E0 dispatches on slot->kind (lh 0x98). Unread ranges are kept as bytes. */
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef void (*StreamSlotFn)(void);
typedef struct {
    s16 state;            /* 0x00 */
    u8 pad02[6];
    s32 handle;           /* 0x08: func_00404290 result */
    u8 pad0C[0x0C];
    s32 limit;            /* 0x18 */
    u8 pad1C[0x1C];
    s32 arg0;             /* 0x38 */
    s32 arg1;             /* 0x3C */
    s32 arg2;             /* 0x40 */
    s32 arg3;             /* 0x44 */
    u8 pad48[0x30];
    StreamSlotFn query;   /* 0x78: func_003F7BE8 */
    void *query_ctx;      /* 0x7C: the slot itself */
    StreamSlotFn advance; /* 0x80: func_003F7C18 */
    void *advance_ctx;    /* 0x84: the slot itself */
    s32 pos_a;            /* 0x88 */
    s32 pos_b;            /* 0x8C */
    u8 pad90[8];
    s16 kind;             /* 0x98 */
    u8 pad9A[0x16];
} StreamSlot;
typedef char StreamSlot_size_check[sizeof(StreamSlot) == 0xB0 ? 1 : -1];
StreamSlot D_004791F8[16] = { { 0 } };
