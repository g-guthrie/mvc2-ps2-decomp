/* Exact 68-byte indexed callback dispatch family. */
typedef unsigned char u8;
typedef struct DispatchState_5 { u8 pad00[5]; u8 index; } DispatchState_5;
typedef struct DispatchState_6 { u8 pad00[6]; u8 index; } DispatchState_6;
extern void (*D_0044BD10[])(DispatchState_5 *);
extern void (*D_0044BD50[])(DispatchState_5 *);
extern void (*D_0044BDC0[])(DispatchState_5 *);
extern void (*D_004518A0[])(DispatchState_6 *);
extern void (*D_004518E0[])(DispatchState_6 *);
extern void (*D_00451940[])(DispatchState_6 *);
extern void (*D_00451960[])(DispatchState_6 *);
extern void (*D_004519A8[])(DispatchState_6 *);
extern void (*D_004519D0[])(DispatchState_6 *);
extern void (*D_00451A00[])(DispatchState_6 *);
extern void (*D_00451A80[])(DispatchState_6 *);
extern void (*D_00451AC0[])(DispatchState_6 *);
extern void (*D_00451AE0[])(DispatchState_6 *);
extern void (*D_00451C00[])(DispatchState_6 *);
extern void (*D_00457DF0[])(DispatchState_6 *);
extern void (*D_00457E00[])(DispatchState_6 *);
extern void (*D_00464B98[])(DispatchState_6 *);
extern void (*D_00464BA8[])(DispatchState_6 *);
extern void func_001B3E20(void *);
extern void func_001B53D0(void *);
extern void func_001B5F90(void *);
extern void func_0022C720(void *);
extern void func_0022C720(void *);
extern void func_0022C720(void *);
extern void func_0022C720(void *);
extern void func_0022C720(void *);
extern void func_0022C720(void *);
extern void func_0022C720(void *);
extern void func_0022C720(void *);
extern void func_0022C720(void *);
extern void func_0022C720(void *);
extern void func_0022C720(void *);
extern void func_00183D90(void *);
extern void func_00183D90(void *);
extern void func_001E7F60(void *);
extern void func_001E7F60(void *);
void func_001B3640(DispatchState_5 *state) { D_0044BD10[state->index](state); func_001B3E20(state); }
void func_001B3FB0(DispatchState_5 *state) { D_0044BD50[state->index](state); func_001B53D0(state); }
void func_001B5570(DispatchState_5 *state) { D_0044BDC0[state->index](state); func_001B5F90(state); }
void func_00227E80(DispatchState_6 *state) { D_004518A0[state->index](state); func_0022C720(state); }
void func_002281E0(DispatchState_6 *state) { D_004518E0[state->index](state); func_0022C720(state); }
void func_00228A10(DispatchState_6 *state) { D_00451940[state->index](state); func_0022C720(state); }
void func_00228DD0(DispatchState_6 *state) { D_00451960[state->index](state); func_0022C720(state); }
void func_002290E0(DispatchState_6 *state) { D_004519A8[state->index](state); func_0022C720(state); }
void func_00229470(DispatchState_6 *state) { D_004519D0[state->index](state); func_0022C720(state); }
void func_00229E40(DispatchState_6 *state) { D_00451A00[state->index](state); func_0022C720(state); }
void func_0022A7E0(DispatchState_6 *state) { D_00451A80[state->index](state); func_0022C720(state); }
void func_0022AF60(DispatchState_6 *state) { D_00451AC0[state->index](state); func_0022C720(state); }
void func_0022B420(DispatchState_6 *state) { D_00451AE0[state->index](state); func_0022C720(state); }
void func_0022BCE0(DispatchState_6 *state) { D_00451C00[state->index](state); func_0022C720(state); }
void func_002969F0(DispatchState_6 *state) { D_00457DF0[state->index](state); func_00183D90(state); }
void func_00296BD0(DispatchState_6 *state) { D_00457E00[state->index](state); func_00183D90(state); }
void func_00389610(DispatchState_6 *state) { D_00464B98[state->index](state); func_001E7F60(state); }
void func_00389770(DispatchState_6 *state) { D_00464BA8[state->index](state); func_001E7F60(state); }
