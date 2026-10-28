typedef signed char s8;
typedef unsigned short u16;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { V3 pos; V3 col; u16 id; s8 flags; s8 slot; } LightListRec;
extern LightListRec data_rec_00443610[];
/* func_00147B70: lw D_00443960[p[0x21]] (lbu 0x21, stride 4); a NULL slot takes the bnez fallback (func_003DAA40).
   Nine slots up to jtbl_00443984, which the catalog keeps as a separate table. */
LightListRec *data_ptr_00443960[9] = {
    data_rec_00443610, data_rec_00443610, data_rec_00443610,
    0, 0, 0, 0, 0, 0,
};
