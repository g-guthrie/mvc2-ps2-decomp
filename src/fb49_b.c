typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u32 D_004CA000[8];
extern u32 D_004C9FE0[8];
extern u32 D_004C9FC0[8];

void func_00126AB0(u32 a, u32 b) {
    u32 A[8] = {a, a + 0x3F0000, a + 0x150000, a + 0x540000, a + 0x2A0000, a + 0x690000, b, a};
    u32 B[8] = {a + 0x141000, a + 0x531000, a + 0x291000, a + 0x681000, a + 0x3E1000, a + 0x7D1000, b + 0x141000, a + 0x141000};
    u32 C[8] = {a + 0x141000, a + 0x531000, a + 0x291000, a + 0x681000, a + 0x3E1000, a + 0x7D1000, b + 0x141000, a + 0x141000};
    D_004CA000[0] = A[0];
    D_004C9FE0[0] = B[0];
    D_004C9FC0[0] = C[0];
    D_004CA000[1] = A[1];
    D_004C9FE0[1] = B[1];
    D_004C9FC0[1] = C[1];
    D_004CA000[2] = A[2];
    D_004C9FE0[2] = B[2];
    D_004C9FC0[2] = C[2];
    D_004CA000[3] = A[3];
    D_004C9FE0[3] = B[3];
    D_004C9FC0[3] = C[3];
    D_004CA000[4] = A[4];
    D_004C9FE0[4] = B[4];
    D_004C9FC0[4] = C[4];
    D_004CA000[5] = A[5];
    D_004C9FE0[5] = B[5];
    D_004C9FC0[5] = C[5];
    D_004CA000[6] = A[6];
    D_004C9FE0[6] = B[6];
    D_004C9FC0[6] = C[6];
    D_004CA000[7] = A[7];
    D_004C9FE0[7] = B[7];
    D_004C9FC0[7] = C[7];
}
