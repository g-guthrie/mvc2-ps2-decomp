typedef float f32;
typedef struct { f32 x, y, z; } Vec3f;

/* Float tables read by func_00341C20's spawner (index * 12 stride):
   a 3-entry Vec3f table at 0x460560 (copied to +0x34/+0x38/+0x3C of the object)
   and a 3-entry table at 0x460590 (x at +0, y at 0x460594, z at 0x460598).
   Followed by a 4-float table at 0x4605B8. */
typedef struct {
    Vec3f pos[3];      /* 0x460560 */
    f32   gap0[3];
    Vec3f ang[3];      /* 0x460590 */
    f32   gap1;
    f32   scale[4];    /* 0x4605B8 */
} Data00460560;
typedef char Data00460560_size_check[(sizeof(Data00460560) == 0x68) ? 1 : -1];

Data00460560 data_raw_00460560 = {
    {
        { -9321.08984f, 17368.1992f, -46053.1992f },
        { -10.9779997f, 17752.1406f, -45790.0f },
        { 6646.78711f, 17524.1895f, -49964.5f },
    },
    { 0.0f, 0.0f, 0.0f },
    {
        { -15.0f, -40.0f, -5.0f },
        { -15.0f, 5.0f, -12.0f },
        { -20.0f, 8.0f, -12.0f },
    },
    0.0f,
    { 1.0f, 0.75f, 0.5f, 0.0f },
};
