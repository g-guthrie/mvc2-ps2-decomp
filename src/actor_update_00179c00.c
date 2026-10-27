/* Provisional: live character action record ownership and callback ABI remain unresolved. */
typedef struct { unsigned char pad[0x38]; float y; } PositionView;
typedef unsigned char u8; typedef signed char s8; typedef unsigned short u16;
extern u8 D_004D18A0[];
extern int func_00179E50(u8 *);
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_00179F60(u8 *);
extern void func_0017A060(u8 *);
extern u8 func_00186120(u8 *);
extern int func_00186CE0(u8 *, u8);
void func_00179C00(u8 *p) {
    if (D_004D18A0[0] >= 6) {
        s8 x = *(s8 *)(p+0x20c);
        if (x >= 0) {
            p[0x20c] = ((x+1)&15) & (x&128);
            func_00186CE0(p,22);
            return;
        }
    }
    if (func_00179E50(p)) {
        if (p[0x217] && ((PositionView *)p)->y < *(float *)(p+0x430) + 34.28571319580078f)
            *(float *)(p+0x38) = *(float *)(p+0x21c);
        return;
    }
    if (*(u16 *)(p+0x168) == 0x1803) {
        if ((s8)func_00175700(p) < 0) func_001757E0(p,0,0);
    } else {
        if ((s8)func_00175700(p) < 0) func_00179F60(p);
        if (p[0x214] && (s8)func_00175700(p) < 0) func_00179F60(p);
    }
    if (*(s8 *)(p+0x2b0) != 0) {
        if (p[0x217] && *(float *)(p+0x38) < *(float *)(p+0x430) + 34.28571319580078f)
            ((PositionView *)p)->y = *(float *)(p+0x21c);
        func_001757E0(p,24,3);
    }
    if (*(u16 *)(p+0x168) != 0x1803 && p[0x217]) {
        func_0017A060(p);
        if (p[0x214]) func_0017A060(p);
        if (*(float *)(p+0x38) < *(float *)(p+0x430) + 34.28571319580078f) {
            *(float *)(p+0x64) = *(float *)(p+0x38);
            ((PositionView *)p)->y = *(float *)(p+0x21c);
            func_00186120(p);
            *(float *)(p+0x38) = *(float *)(p+0x64);
            return;
        }
    }
    if (p[1] == 11) (*(int (**)(u8 *))(*(u8 **)(p+0x43c)+0x60))(p);
    func_00186120(p);
}
