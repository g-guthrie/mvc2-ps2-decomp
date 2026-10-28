/* Descriptors for the move handlers at 0x0023F140-0x0023F520 (all passed to
 * func_00189310). */
#include "mvc2_input_script.h"
typedef struct {
    InputScript16 d_452870; /* 0x00452870 */
    InputScript16 d_452880; /* 0x00452880 */
    InputScript32 d_452890; /* 0x00452890 */
    InputScript16 d_4528B0; /* 0x004528B0 */
    InputScript16 d_4528C0; /* 0x004528C0 */
} Data00452870;
typedef char data_rec_00452870_size_check[(sizeof(Data00452870) == 0x60) ? 1 : -1];

Data00452870 data_rec_00452870 = {
    { 0x0003, 0x9100, 3, { 0, 0, 0 }, { 0x1000, 0x1800, 0x0800, 0x0300 } },
    { 0x0003, 0x9100, 4, { 0, 0, 0 }, { 0x1000, 0x1800, 0x0800, 0x0060 } },
    { 0x0005, 0x1000, 2, { 0, 0, 0 }, { 0x0800, 0x1800, 0x1000, 0x1400, 0x0400, 0x0300, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 } },
    { 0x0003, 0x0000, 0, { 0, 0, 0 }, { 0x1000, 0x1800, 0x0800, 0x0300 } },
    { 0x0003, 0x1000, 1, { 0, 0, 0 }, { 0x1000, 0x1800, 0x0800, 0x0060 } }
};
