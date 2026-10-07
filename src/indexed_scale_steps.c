/* Apply a frame-indexed scale on all axes while advancing rotation and state. */
typedef unsigned char u8;
extern float D_004B4230[];
extern float D_004B4230[];
extern float D_004B4230[];
extern float D_004B4230[];

#define INDEXED_SCALE_STEP(name, table, delta) \
void name(u8 *p) { \
    unsigned int index = p[5]; float *scale = (table); scale += index; \
    *(int *)(p + 0x48) += (delta); \
    *(float *)(p + 0x78) = *scale; \
    *(float *)(p + 0x7c) = *scale; \
    *(float *)(p + 0x80) = *scale; \
    if (++p[5] > 6) ++p[4]; \
}

INDEXED_SCALE_STEP(func_001632A0, D_004B4230, 0x2f7)
INDEXED_SCALE_STEP(func_00163410, D_004B4230, 0x2f7)
INDEXED_SCALE_STEP(func_00163580, D_004B4230, 0x2f7)
INDEXED_SCALE_STEP(func_001636F0, D_004B4230, 0x2f7)
