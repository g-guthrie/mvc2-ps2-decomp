typedef signed int s32;
typedef struct SonyEeSemaParams {
    s32 count;
    s32 max_count;
    s32 init_count;
    s32 wait_threads;
    unsigned int attr;
    unsigned int option;
} SonyEeSemaParams;
extern s32 D_00438304;
extern s32 func_00103DE0(SonyEeSemaParams *params);
void func_00107A68(void) {
    if (D_00438304 == -1) {
        SonyEeSemaParams params;
        params.init_count = 1;
        params.max_count = 1;
        params.option = 0;
        D_00438304 = func_00103DE0(&params);
    }
}
