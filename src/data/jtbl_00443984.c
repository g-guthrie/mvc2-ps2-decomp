typedef signed char s8;
typedef unsigned short u16;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { V3 pos; V3 col; u16 id; s8 flags; s8 slot; } LightListRec;
extern LightListRec data_rec_004436E0[];
extern LightListRec data_rec_00443770[];
extern LightListRec data_rec_00443840[];
extern LightListRec data_rec_004438D0[];
/* Record lists of the D_00443960 family (func_00147B70 layout). */
LightListRec *const jtbl_00443984[11] = {
    data_rec_004436E0,
    data_rec_004436E0,
    data_rec_004436E0,
    data_rec_004436E0,
    data_rec_00443770,
    data_rec_00443770,
    data_rec_004436E0,
    data_rec_00443840,
    data_rec_00443840,
    data_rec_004438D0,
    data_rec_004436E0,
};
