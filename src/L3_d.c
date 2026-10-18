typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_006336E8[];
extern s32 D_006336EC[];
extern s32 D_006336F0[];
extern s32 D_004D17CC[];
extern s32 D_004C2620;
extern s32 D_004C2624;

s32 func_0012FD70(void) {
    extern void func_0041DF20(void);
    func_0041DF20();
    if (D_006336E8[0] != 0) D_004C2620 = D_006336E8[0];
    if (D_006336EC[0] != 0) D_004C2624 = D_006336EC[0];
    switch (D_004C2620) {
    case 4:
        D_004D17CC[0] = 0;
        return 2;
    case 3:
        switch (D_004C2624) {
        case 4:
            D_004D17CC[0] = 1;
            return 2;
        case 2: case 1: case 5: case 3:
            D_004D17CC[0] = 0;
            return 3;
        }
        break;
    case 2:
        switch (D_004C2624) {
        case 4:
            D_004D17CC[0] = 1;
            return 2;
        case 2: case 1: case 5:
            D_004D17CC[0] = 0;
            return 3;
        case 3:
            D_004D17CC[0] = 1;
            return 3;
        }
        break;
    case 1:
        switch (D_004C2624) {
        case 1:
            if (D_006336F0[0] != 0) {
                D_004D17CC[0] = 0;
                return 10;
            }
            D_004D17CC[0] = 0;
            return 5;
        case 2:
            D_004D17CC[0] = 1;
            return 3;
        case 4:
            D_004D17CC[0] = 1;
            return 2;
        case 3:
            D_004D17CC[0] = 1;
            return 3;
        case 5:
            D_004D17CC[0] = 1;
            return 11;
        }
        break;
    case 5:
        switch (D_004C2624) {
        case 1:
            D_004D17CC[0] = 0;
            return 11;
        case 5:
            D_004D17CC[0] = 0;
            return 11;
        case 4:
            D_004D17CC[0] = 1;
            return 2;
        case 3:
            D_004D17CC[0] = 1;
            return 3;
        case 2:
            D_004D17CC[0] = 1;
            return 3;
        }
        break;
    }
    return 5;
}
