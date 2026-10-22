/* Signed 16-bit lookup table. Element type settled by the reader in src/h8q.c:
   func_00191770 indexes D_00449230[i] for i in 0..10 (i = a1[0] / 5, clamped to 10). */
typedef short s16;
s16 data_raw_00449230[48] = {
    256, 256, 512, 768, 1280, 4096, 5376, 8192,
    9472, 12288, 20480, 0, 0, 0, 0, 0,
    0, 1, 3, 5, 16, 32, 64, 96,
    128, 256, 0, 0, 0, 48, 96, 144,
    256, 0, 0, 0, 0, 0, 0, 0,
    2072, 24, 3088, 20, 1024, 28, 0, 0,
};
