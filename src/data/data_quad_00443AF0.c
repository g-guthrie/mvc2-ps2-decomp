typedef unsigned int u32;
typedef float f32;
/* func_00149020 rewrites x/y (D_00443AF0..D_00443B24) then calls func_00417AE0(4, D_00443AF0);
   func_00417AE0 walks 16-byte vertices: lwc1 0x0/0x4/0x8 and lw 0xC (packed colour). */
typedef struct { f32 x, y, z; u32 color; } QuadVertex;
typedef char QuadVertex_size[(sizeof(QuadVertex) == 16) ? 1 : -1];
QuadVertex data_quad_00443AF0[4] = {
    { 0.0f, 0.0f, 14.98f, 0xFFFFFFFFu },
    { 320.0f, 0.0f, 14.98f, 0xFFFFFFFFu },
    { 0.0f, 240.0f, 14.98f, 0xFFFFFFFFu },
    { 320.0f, 240.0f, 14.98f, 0xFFFFFFFFu },
};
