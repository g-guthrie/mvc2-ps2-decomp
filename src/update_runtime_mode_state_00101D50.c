typedef signed int s32;
typedef unsigned char u8;

struct RuntimeModeState {
    u8 pad[8];
    s32 state;
    s32 parameter;
};

extern struct RuntimeModeState *func_00100468(void);
extern void func_001048C0(s32);
extern s32 func_00103AE0(s32, s32);
extern s32 func_00103AC0(s32, s32, s32);
extern void func_00104928(s32);

s32 func_00101D50(s32 nextState)
{
    struct RuntimeModeState *record = func_00100468();
    s32 previousState = record->state;

    if (nextState == 0) {
        func_001048C0(2);
        func_00103AE0(2, record->parameter);
        record->parameter = 0;
        record->state = 0;
    } else {
        if (previousState != 0) {
            func_001048C0(2);
            func_00103AE0(2, record->parameter);
        }
        record->state = nextState;
        record->parameter = func_00103AC0(2, nextState, -1);
        func_00104928(2);
    }
    return previousState;
}
