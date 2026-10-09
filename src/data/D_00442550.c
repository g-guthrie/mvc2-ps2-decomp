typedef float f32;
typedef struct { f32 value[3]; } F32Vector3;
extern F32Vector3 data_f32v3_004B20C0[];
extern F32Vector3 data_f32v3_004B2310[];
extern F32Vector3 data_f32v3_004B2570[];
extern F32Vector3 data_f32v3_004B27D0[];
extern F32Vector3 data_f32v3_004B2A20[];
extern F32Vector3 data_f32v3_004B2C70[];
extern F32Vector3 data_f32v3_004B2EC0[];
/* func_003DA780 zero-fills each 0x1E4-byte object through func_0011D8F8 at
 * 0x003DA804, so field1E starts at 0. func_001442F0 samples the current and
 * next vec3 with stride 12 and reads their frame durations from the 49-value
 * D_004B3110 table (0x00144340, 0x00144350). After each completed interval it
 * increments field1E; when it reaches 48 it sets field4=1 (0x00144420-0x00144434),
 * so subsequent calls skip interpolation at 0x001442F8. Thus frames 0..48 are
 * the full used span for each selector.
 * func_00143D50 calls func_00144260 with selectors 0..6: s0 starts at 0
 * (0x00143D60), is passed at 0x00143D68, and loops while the incremented
 * value is less than 7 (0x00143D6C-0x00143D7C). The factory stores that value
 * in field20 at 0x001442C0; func_001442F0 reads field20 and indexes this table
 * at 0x00144310-0x00144338. func_00144260 also reads each target's vec3 at
 * offsets 0, 4, and 8. */
const F32Vector3 * const D_00442550[7] = {
    data_f32v3_004B20C0,
    data_f32v3_004B2310,
    data_f32v3_004B2570,
    data_f32v3_004B27D0,
    data_f32v3_004B2A20,
    data_f32v3_004B2C70,
    data_f32v3_004B2EC0,
};
