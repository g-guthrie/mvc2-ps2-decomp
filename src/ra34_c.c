typedef unsigned char u8;
typedef signed int s32;
typedef unsigned int u32;

extern u8 D_004C2610;
extern u8 D_004C260C;
extern u8 D_004CAB0C[];
extern u8 D_004CAB5A[];
extern u8 D_004CAB5B[];
extern u8 D_004CAB7A[];
extern u8 D_004CAB7B[];
extern u8 D_004CAB0A[];
extern u8 D_004CAB0B[];
extern u8 D_004CAB70[];
extern u8 D_004CAB40[];
extern u8 D_004CAAF0[];
extern u8 D_004CAB20[];

void func_0012DD90(void) {
    extern s32 func_0012DE70(u8 *);
    extern s32 func_0012DF30(u8 *);
    extern void func_0012E1A0(u8 *);
    s32 r;
    u32 t;
    if (func_0012DE70(D_004CAB70) != 0) return;
    if (func_0012DF30(D_004CAB40) != 0) return;
    r = func_0012DF30(D_004CAAF0);
    if (r != 0) {
        if (r >= 0) return;
        if (D_004CAB0C[0] == 0) {
            t = D_004C2610;
            D_004C2610 = t | D_004C260C;
        }
        return;
    }
    if (D_004CAB5A[0] != D_004CAB5B[0]) return;
    if (D_004CAB7A[0] != D_004CAB7B[0]) return;
    if (D_004CAB0A[0] != D_004CAB0B[0]) return;
    func_0012E1A0(D_004CAB20);
}
