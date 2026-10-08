typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

extern volatile u8 D_00630000[0x4380];
extern volatile s32 D_004C2538;
extern volatile s32 D_004C253C;
extern volatile s32 D_004C2BB4;
extern char D_004BF1A0[];

extern void func_00422CC0(void);
extern s32 func_00422D20(volatile u8 *buffer, u32 tag);
extern s32 func_00103DE0(void *request);
extern s32 func_0011EB60(const char *format, ...);

typedef struct {
    u32 reserved0;
    u32 maxCount;
    u32 initialCount;
    u32 reserved3;
    u32 reserved4;
    u32 option;
} SemaParam;

s32 func_00422DB0(void)
{
    SemaParam request;
    s32 status;

    if (D_004C2BB4 != 0)
        return 0;

    func_00422CC0();
    status = func_00422D20(D_00630000 + 0x4060, 0x54534400u);
    if (status < 0)
        return -1;
    status = func_00422D20(D_00630000 + 0x4030, 0x54534401u);
    if (status < 0)
        return -1;

    request.initialCount = 1;
    request.maxCount = 1;
    request.option = 0;

    if (D_004C2538 < 0) {
        status = func_00103DE0(&request);
        if (status <= 0)
            return -1;
        D_004C2538 = status;
    }
    if (D_004C253C < 0) {
        status = func_00103DE0(&request);
        if (status <= 0)
            return -1;
        D_004C253C = status;
    }

    D_004C2BB4 = 1;
    func_0011EB60(D_004BF1A0, 2, 0);
    return 0;
}
