typedef short s16;
typedef float f32;
/* Header halfwords followed by f32 values (-13.3333 / 0 / +-6.4286 / -10.8333 style coordinates). Layout inferred from value decoding. */
typedef struct {
    s16 h[8];
    f32 f[8];
} Data00472A50;
typedef char Data00472A50_size_check[(sizeof(Data00472A50) == 48) ? 1 : -1];
Data00472A50 data_raw_00472A50 = {
    { 58, 94, 37, 118, 52, 70, 0, 0 },
    { -13.333333f, 0.0f, -13.333333f, 6.42857122f, -13.333333f, -6.42857122f, 0.0f, 0.0f },
};
