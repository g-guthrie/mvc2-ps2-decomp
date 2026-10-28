typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef f32 F32Vec[3];
/* Provisional: this vector view differs from the owned float[8][2][3] table. */
extern f32 data_f32_004B1940[8][2][3];

void func_0013E760(u8 *p)
{
    F32Vec *a = (F32Vec *)((u8 *)&data_f32_004B1940 + (p[0x20]*sizeof(data_f32_004B1940[0])));
    F32Vec *b = (F32Vec *)((u8 *)&data_f32_004B1940 + ((p[0x20]*2+1)*sizeof(F32Vec)));
    f32 d, e;
    e = (*a)[0];
    d = ((*b)[0] - e) / 30.0f;
    *(f32 *)(p + 0x34) = e + (f32)*(s16 *)(p + 0x1C) * d;
    e = (*a)[1];
    d = ((*b)[1] - e) / 30.0f;
    *(f32 *)(p + 0x38) = e + (f32)*(s16 *)(p + 0x1C) * d;
    e = (*a)[2];
    d = ((*b)[2] - e) / 30.0f;
    *(f32 *)(p + 0x3C) = e + (f32)*(s16 *)(p + 0x1C) * d;
}
extern f32 *D_004F1F4C;
extern V3 D_00440820[];

void func_0013FB40(u8 *p)
{
    V3 *a;
    f32 *b;
    f32 d, e;
    p[0x13C] = 1;
    if (*(s16 *)(p + 0x1E) == 0) return;
    *(s16 *)(p + 0x1E) -= 1;
    a = &D_00440820[p[0x22]];
    b = (f32*)&D_004F1F4C;
    e = a->x;
    d = (b[0] - e) / 30.0f;
    *(f32 *)(p + 0x34) = e + (f32)*(s16 *)(p + 0x1E) * d;
    e = a->y;
    d = (b[1] - e) / 30.0f;
    *(f32 *)(p + 0x38) = e + (f32)*(s16 *)(p + 0x1E) * d;
    e = a->z;
    d = (b[2] - e) / 30.0f;
    *(f32 *)(p + 0x3C) = e + (f32)*(s16 *)(p + 0x1E) * d;
}
