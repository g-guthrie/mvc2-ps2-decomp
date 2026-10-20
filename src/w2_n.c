typedef unsigned char u8;
typedef signed char s8;
#include "HtciFileRequest.h"
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_0040B220(HtciFileRequest *p)
{
    extern void func_00411288();
    extern void func_004112B0();
    extern s32 func_00407EC0();
    extern void func_00407C80();
    if (p->request_handle_2c != 0) {
        func_00411288();
        switch (func_00407EC0(p->request_handle_2c)) {
        case 9:
            p->operation_state = 3;
            func_00407C80(p->request_handle_2c);
            p->request_handle_2c = 0;
            break;
        case 3:
            p->raw_28_2b.word = p->requested_bytes_24;
            p->progress_1c += p->requested_bytes_24;
            p->operation_state = 1;
            func_00407C80(p->request_handle_2c);
            p->request_handle_2c = 0;
            break;
        case 0:
            p->operation_state = 0;
            func_00407C80(p->request_handle_2c);
            p->request_handle_2c = 0;
            break;
        case 1:
        case 2:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        default:
            break;
        }
        func_004112B0();
    }
}
