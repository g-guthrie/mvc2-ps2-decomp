/* MWCCPS2: ./try.sh src/grok_u3_3d90a0.c "-O3 -sdatathreshold 8" */
typedef int (*DispatchFn)(int);

extern DispatchFn jtbl_004C21E0[2];

int func_003D90A0(int i) { return jtbl_004C21E0[i](i); }
