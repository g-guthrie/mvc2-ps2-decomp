typedef float f32;
typedef struct { f32 value[3]; } F32Vector3;
/* Only constructors with modes0,1,2 call func_00135150. Its zeroed task
 * starts field0x1E at0; func_001352A0 advances it once after a fixed 15-step
 * interpolation. Modes0/1 consume row groups0..2 and3..5; mode2 consumes
 * rows6..8. The final zero vector at 0x43EAC0 supplies row8. */
F32Vector3 data_f32v3_0043EA60[8] = {
    { { -32.060001373291016f, 0.0f, -21.989999771118164f } },
    { { -1.3300000429153442f, 0.0f, -8.75f } },
    { { 10.979999542236328f, 0.0f, -3.0f } },
    { { 32.33000183105469f, 0.0f, -21.989999771118164f } },
    { { 1.1399999856948853f, 0.0f, -7.449999809265137f } },
    { { -11.180000305175781f, 0.0f, -1.7000000476837158f } },
    { { 0.0f, 0.0f, 0.0f } },
    { { 0.0f, 0.0f, -4.599999904632568f } },
};
