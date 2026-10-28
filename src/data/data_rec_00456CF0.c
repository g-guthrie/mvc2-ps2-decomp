/* Descriptors for the move handlers at 0x0028DC70-0x0028E4D0 (all passed to
 * func_00189310; D_00456D50/60/70 are then passed on to func_0018A990). */
#include "mvc2_input_script.h"
typedef struct {
    InputScript16 d_456CF0; /* 0x00456CF0 */
    InputScript16 d_456D00; /* 0x00456D00 */
    InputScript16 d_456D10; /* 0x00456D10 */
    InputScript16 d_456D20; /* 0x00456D20 */
    InputScript16 d_456D30; /* 0x00456D30 */
    InputScript16 d_456D40; /* 0x00456D40 */
    InputScript16 d_456D50; /* 0x00456D50 */
    InputScript16 d_456D60; /* 0x00456D60 */
    InputScript16 d_456D70; /* 0x00456D70 */
} Data00456CF0;
typedef char data_rec_00456CF0_size_check[(sizeof(Data00456CF0) == 0x90) ? 1 : -1];

Data00456CF0 data_rec_00456CF0 = {
    { 0x0003, 0x0000, 0, { 0, 0, 0 }, { 0x1000, 0x1800, 0x0800, 0x0300 } },
    { 0x0003, 0x0000, 2, { 0, 0, 0 }, { 0x0800, 0x1000, 0x1800, 0x0300 } },
    { 0x0003, 0x8100, 7, { 0, 0, 0 }, { 0x1000, 0x1800, 0x0800, 0x0300 } },
    { 0x0003, 0x9100, 4, { 0, 0, 0 }, { 0x1000, 0x1800, 0x0800, 0x0060 } },
    { 0x0003, 0x9100, 5, { 0, 0, 0 }, { 0x1000, 0x1400, 0x0400, 0x0060 } },
    { 0x0003, 0x0000, 6, { 0, 0, 0 }, { 0x1000, 0x1400, 0x0400, 0x0300 } },
    { 0x0003, 0x1000, 12, { 0, 0, 0 }, { 0x1000, 0x1800, 0x0800, 0x0060 } },
    { 0x0003, 0x1000, 12, { 0, 0, 0 }, { 0x0800, 0x1000, 0x1800, 0x0060 } },
    { 0x0003, 0x1000, 12, { 0, 0, 0 }, { 0x1000, 0x1400, 0x0400, 0x0060 } }
};
