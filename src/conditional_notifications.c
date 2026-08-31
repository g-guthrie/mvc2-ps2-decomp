typedef unsigned char u8;

extern void func_001E9C40(u8 *state); extern void func_001EF380(u8 *state);
extern void func_001F8100(u8 *state); extern void func_00204310(u8 *state);
extern void func_00209290(u8 *state); extern void func_002111A0(u8 *state);
extern void func_00216AF0(u8 *state); extern void func_0021DBA0(u8 *state);
extern void func_00223650(u8 *state); extern void func_0022D940(u8 *state);
extern void func_002340B0(u8 *state); extern void func_0023AA90(u8 *state);
extern void func_0023FB00(u8 *state); extern void func_0024E750(u8 *state);
extern void func_00256A30(u8 *state); extern void func_0025D0B0(u8 *state);
extern void func_002632B0(u8 *state); extern void func_0026BC10(u8 *state);
extern void func_0026FAB0(u8 *state); extern void func_00274270(u8 *state);
extern void func_00281FA0(u8 *state); extern void func_002871E0(u8 *state);
extern void func_0028EAB0(u8 *state); extern void func_00295ED0(u8 *state);
extern void func_002A1980(u8 *state); extern void func_002A7E40(u8 *state);
extern void func_002B3640(u8 *state); extern void func_002B9030(u8 *state);
extern void func_002CC940(u8 *state); extern void func_002D20A0(u8 *state);
extern void func_002DCEF0(u8 *state); extern void func_002E4CB0(u8 *state);
extern void func_002F2D40(u8 *state); extern void func_002F7A90(u8 *state);
extern void func_002FCDD0(u8 *state); extern void func_003098F0(u8 *state);
extern void func_003104D0(u8 *state); extern void func_0031BEE0(u8 *state);

#define NOTIFY(name, callee) \
    void name(u8 *state) { \
        u8 enabled = state[0x212]; \
        if (!enabled) { \
            if (((signed char)state[0x1EA] & 0x0F) != 0) { \
                callee(state); \
                return; \
            } \
        } \
        if (enabled) { \
            if (((signed char)state[0x1EA] & 0xF0) != 0) { \
                callee(state); \
            } \
        } \
    }

NOTIFY(func_001E9F90, func_001E9C40) NOTIFY(func_001EF3C0, func_001EF380)
NOTIFY(func_001F80A0, func_001F8100) NOTIFY(func_002042B0, func_00204310)
NOTIFY(func_00209230, func_00209290) NOTIFY(func_00211140, func_002111A0)
NOTIFY(func_00216A90, func_00216AF0) NOTIFY(func_0021DB40, func_0021DBA0)
NOTIFY(func_002239B0, func_00223650) NOTIFY(func_0022D980, func_0022D940)
NOTIFY(func_00234050, func_002340B0) NOTIFY(func_0023AA30, func_0023AA90)
NOTIFY(func_0023FAA0, func_0023FB00) NOTIFY(func_0024E6F0, func_0024E750)
NOTIFY(func_002569D0, func_00256A30) NOTIFY(func_0025D050, func_0025D0B0)
NOTIFY(func_00263250, func_002632B0) NOTIFY(func_0026BBB0, func_0026BC10)
NOTIFY(func_0026FA50, func_0026FAB0) NOTIFY(func_00274210, func_00274270)
NOTIFY(func_00281F40, func_00281FA0) NOTIFY(func_00287180, func_002871E0)
NOTIFY(func_0028EA50, func_0028EAB0) NOTIFY(func_00296210, func_00295ED0)
NOTIFY(func_002A1920, func_002A1980) NOTIFY(func_002A7DE0, func_002A7E40)
NOTIFY(func_002B35E0, func_002B3640) NOTIFY(func_002B8FD0, func_002B9030)
NOTIFY(func_002CCC80, func_002CC940) NOTIFY(func_002D2040, func_002D20A0)
NOTIFY(func_002DCE90, func_002DCEF0) NOTIFY(func_002E4C50, func_002E4CB0)
NOTIFY(func_002F2CE0, func_002F2D40) NOTIFY(func_002F7A30, func_002F7A90)
NOTIFY(func_002FCD70, func_002FCDD0) NOTIFY(func_00309890, func_003098F0)
NOTIFY(func_00310470, func_003104D0) NOTIFY(func_0031BE80, func_0031BEE0)
