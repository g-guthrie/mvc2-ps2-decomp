typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C2840;
extern void func_00154650();
extern void func_001E40E0();
extern void func_001E4140(void);

void func_00183DF0(u8 *unused, s32 a) {
    if (*(s32 *)(D_004C2840 + 0x1C) % a == 0) func_00154650();
}

void func_00128650(void) {
    D_004C2840[2] = 5;
    D_004C2840[3] = 0;
    D_004C2840[0x19] = 1;
    func_001E40E0();
    func_001E4140();
}

extern u8 *D_004C2794;
extern u8 D_004C260C;
extern u8 D_004C2610;
extern u32 D_004CAB10[];
extern void func_003FCCF0();
extern void func_0012E4C0();
extern void func_001754A0();
extern void func_001757E0();
extern void func_00134850();
extern u8 *D_004D36CC[];
extern u32 (*D_004C1860[2])(u8 *);

void func_0031E720(u8 *p) {
    u32 offset;
    p[0x1B5] = *(s8 *)(p + 0x22) + 82;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    offset = p[2] * 2;
    offset += (u32)D_004C2794;
    ++*(s16 *)(offset + 0x7C);
    p[0x2BA] = p[0x286];
}


void func_0012E720(void) {
    if (*(s8 *)(D_004C2840 + 0x88) == 0) {
        D_004C260C = 0;
        D_004C2610 = 0;
        if (D_004CAB10[0]) {
            func_003FCCF0(D_004CAB10[0]);
            D_004CAB10[0] = 0;
        }
        func_0012E4C0();
    }
}

void func_0036CA80(u8 *p) {
    p[0x13C] = 1;
    *(float *)(p + 0x34) = *(float *)(*(u8 **)(p + 0x18) + 0x34);
    *(float *)(p + 0x38) = *(float *)(*(u8 **)(p + 0x18) + 0x38);
    *(float *)(p + 0x3C) = *(float *)(*(u8 **)(p + 0x18) + 0x3C);
    p[0x24] = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    p[0x169] = 0x17;
    func_001757E0(p, p[0x169], 0x24);
}

extern u8 D_0045EEA8[];
extern s32 D_004C283C;
extern u32 (*D_004C1E70[2])(u8 *);
extern void func_0039E450();



void func_0033D270(u8 *p) {
    s16 n;
    *(s16 *)(p + 0xCC) = (s8)D_0045EEA8[*(s16 *)(p + 0x1C)] + 5;
    *(s32 *)(p + 0x84) = D_004C283C;
    n = *(s16 *)(p + 0x1C) + 1;
    *(s16 *)(p + 0x1C) = n;
    if ((u32)n >= 15) *(s16 *)(p + 0x1C) = 0;
}

void func_001EC280(u8 *p) {
    u8 v = p[0x15B];
    u32 offset;
    if (v) {
        p[0x15B] = 0;
        p[0x1B5] = v;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        offset = p[2] * 2;
        offset += (u32)D_004C2794;
        ++*(s16 *)(offset + 0x7C);
        *(u16 *)(p + 0x1C0) = 0x10;
    }
}
