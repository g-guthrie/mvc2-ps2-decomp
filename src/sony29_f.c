#include "sony_pad_slot.h"
extern int func_0010E1B0(int, int, int);

int func_0010E318(int a0, int a1) {
    if (D_004C83D0[a0][a1].enabled == 0) {
        return 0;
    }
    return func_0010E1B0(a0, a1, 0);
}
