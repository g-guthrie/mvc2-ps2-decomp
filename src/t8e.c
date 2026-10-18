/* t8 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { float x, y, z; } Float3;
typedef struct { u8 pad[0x18]; u32 t[2][3]; } S18;
extern S18 D_004D18A0;
extern void func_001E86B0();
extern u8 *func_003DA750(s32, s32, s32);
extern void func_001505F0();
extern u32 D_004C27E8;
extern void func_00134E40();
extern Float3 D_0043E950[];
extern u32 D_004C2834;
extern u8 *D_004C2840;
extern void func_00135140();
extern void func_0018A920();

void func_001E85F0(void) {
    s32 i, j, k;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                func_001E86B0(D_004D18A0.t[i][j], D_004D18A0.t[i ^ 1][k]);
            }
        }
    }
}
