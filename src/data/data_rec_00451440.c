/* Descriptors for the move handlers at 0x00222C70-0x00222FA0 (all passed to
 * func_00189310). */
#include "mvc2_input_script.h"
typedef struct {
    InputScript16 d_451440; /* 0x00451440 */
    InputScript16 d_451450; /* 0x00451450 */
    InputScript16 d_451460; /* 0x00451460 */
    InputScript16 d_451470; /* 0x00451470 */
    InputScript16 d_451480; /* 0x00451480 */
} Data00451440;
typedef char data_rec_00451440_size_check[(sizeof(Data00451440) == 0x50) ? 1 : -1];

Data00451440 data_rec_00451440 = {
    { 0x0003, 0x0000, 0, { 0, 0, 0 }, { 0x1000, 0x1800, 0x0800, 0x0060 } },
    { 0x0003, 0x1000, 1, { 0, 0, 0 }, { 0x1000, 0x1800, 0x0800, 0x0300 } },
    { 0x0003, 0x2000, 4, { 0, 0, 0 }, { 0x1000, 0x1800, 0x0800, 0x0300 } },
    { 0x0003, 0x1000, 3, { 0, 0, 0 }, { 0x1000, 0x1400, 0x0400, 0x0300 } },
    { 0x0003, 0x8100, 2, { 0, 0, 0 }, { 0x1000, 0x1800, 0x0800, 0x0300 } }
};
