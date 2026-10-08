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
extern int func_0011EB60(const char *format, ...);

typedef struct {
    u32 word0;
    u32 word1;
    u32 word2;
    u32 word3;
    u32 word4;
    u32 word5;
} RuntimeRequest;

s32 func_00422DB0(void)
{
    RuntimeRequest request;
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

    request.word2 = 1;
    request.word1 = 1;
    request.word5 = 0;

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
