typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
/* Four-vertex quad passed as func_00417AE0(4, &D_00443B70) at 0x001491A8
 * (src/rb61_c.c): each 16-byte vertex supplies x/y (lwc1 +0/+4) and a
 * colour word (lw +0xC); vertex 0's depth (+8) is negated for the view
 * vector. Depths of vertices 1-3 are not read but share the vertex layout.
 * func_00149020 rewrites the x/y fields with swc1 each frame. */
typedef struct { f32 x, y, depth; u32 color; } QuadVertex;
typedef char QuadVertex_size_check[(sizeof(QuadVertex) == 16) ? 1 : -1];
QuadVertex D_00443B70[4] = {
    { 0.0f, 0.0f, 14.96f, 0xFF00FF15u },
    { 320.0f, 0.0f, 14.96f, 0xFF00FF15u },
    { 0.0f, 240.0f, 14.96f, 0xFF00FF15u },
    { 320.0f, 240.0f, 14.96f, 0xFF00FF15u }
};
