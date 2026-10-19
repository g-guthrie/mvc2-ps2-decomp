/* Preserve the native far/near signs and ordered single-precision operations. */
extern float func_003DE790(float);
extern float func_003DE710(float);
extern void func_003DD260(float *);
void func_003DD360(float *m, float far_plane, float near_plane, float fov, float aspect) {
    float cosine, sine, cotangent;
    fov *= 0.5f;
    sine = func_003DE790(fov);
    cosine = func_003DE710(fov);
    func_003DD260(m);
    cotangent = cosine / sine;
    m[0] = cotangent / aspect;
    m[5] = cotangent;
    m[10] = -(far_plane + near_plane) / (far_plane - near_plane);
    m[11] = -1.0f;
    m[14] = -(2.0f * far_plane * near_plane) / (far_plane - near_plane);
    m[15] = 0.0f;
}
