typedef float f32;
/* Per-step scale, indexed by h1c in 0..9 (func_0033F030, rb77_a.c: lwc1 for
 * f50/f54/f58; h1c wraps at 10); entry 0 is also read by the spawner (wave33b.c). */
f32 D_0045F8B0[10] = {
    0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.25f, 0.5f, 0.5f, 0.5f, 0.5f
};
