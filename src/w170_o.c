#include "mvc2_character_action_record_0044F2E0.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x18]; u8 *ent[2][3]; u8 pad1[0x8A - 0x18 - 24]; u8 b8A[2]; } GO;
typedef struct { u8 pad[0x58]; s8 f58; } HO;
extern GO *D_004C2794;
extern HO *D_004C2840;
extern u8 D_004D1070[];

void func_00180360(void) {
    extern void func_001757E0();
    extern void func_00180890();
    extern void func_0015C5C0();
    u8 *s0;
    u8 i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            s0 = D_004C2794->ent[i][j];
            *s0 = j ? 0 : 1;
            if (D_004C2840->f58 != 0 && !j) {
                s0[0x427] = 1;
                D_004C2794->b8A[i] = s0[0x1B8];
            }
            s0[0x13C] = *s0;
            func_001757E0(s0, 0, 0);
            *(Mvc2CharacterActionRecord112View **)(s0 + 0x43C) = (Mvc2CharacterActionRecord112View *)(D_004D1070 + s0[0x1B8] * 128);
            func_00180890(s0);
            *(u8 **)(s0 + 0x220) = D_004C2794->ent[i][0];
        }
    }
    func_0015C5C0();
}
