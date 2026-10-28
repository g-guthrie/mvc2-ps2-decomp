/* Descriptors for the move handlers at 0x001EE1F0-0x001EE900: D_0044F5C0/5E0/610/
 * 630/640/660 are passed to func_00189310 and D_0044F5D0/5F8/620/650 to
 * func_00189B90, each by its own address. */
#include "mvc2_input_script.h"
typedef struct {
    InputScript16 d_44F5C0; /* 0x0044F5C0 */
    InputScript16 d_44F5D0; /* 0x0044F5D0 */
    InputScript24 d_44F5E0; /* 0x0044F5E0 */
    InputScript24 d_44F5F8; /* 0x0044F5F8 */
    InputScript16 d_44F610; /* 0x0044F610 */
    InputScript16 d_44F620; /* 0x0044F620 */
    InputScript16 d_44F630; /* 0x0044F630 */
    InputScript16 d_44F640; /* 0x0044F640 */
    InputScript16 d_44F650; /* 0x0044F650 */
    InputScript16 d_44F660; /* 0x0044F660 */
} Data0044F5C0;
typedef char data_rec_0044F5C0_size_check[(sizeof(Data0044F5C0) == 0xB0) ? 1 : -1];

Data0044F5C0 data_rec_0044F5C0 = {
    { 0x0003, 0x1000, 2, { 0, 0, 0 }, { 0x0800, 0x1000, 0x1800, 0x0300 } },
    { 0x0004, 0x0000, 3, { 0, 0, 0 }, { 0x0300, 0x0000, 0x0000, 0x0000 } },
    { 0x0005, 0x1000, 4, { 0, 0, 0 }, { 0x0400, 0x1400, 0x1000, 0x1800, 0x0800, 0x0060, 0x0000, 0x0000 } },
    { 0x0004, 0x9100, 5, { 0, 0, 0 }, { 0x0300, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 } },
    { 0x0003, 0x1000, 6, { 0, 0, 0 }, { 0x0800, 0x1000, 0x1800, 0x0060 } },
    { 0x0004, 0x9100, 17, { 0, 0, 0 }, { 0x0060, 0x0000, 0x0000, 0x0000 } },
    { 0x0003, 0x1100, 18, { 0, 0, 0 }, { 0x0400, 0x1000, 0x1400, 0x0040 } },
    { 0x0003, 0x1000, 19, { 0, 0, 0 }, { 0x1000, 0x1800, 0x0800, 0x0300 } },
    { 0x0004, 0x9100, 20, { 0, 0, 0 }, { 0x0060, 0x0000, 0x0000, 0x0000 } },
    { 0x0003, 0x1000, 0, { 0, 0, 0 }, { 0x1000, 0x1400, 0x0400, 0x0200 } }
};
