/* Descriptors for the move handlers at 0x00215DD0-0x00216510 (all passed to
 * func_00189310). */
#include "mvc2_input_script.h"
typedef struct {
    InputScript16 d_450DE0; /* 0x00450DE0 */
    InputScript16 d_450DF0; /* 0x00450DF0 */
    InputScript16 d_450E00; /* 0x00450E00 */
    InputScript16 d_450E10; /* 0x00450E10 */
    InputScript16 d_450E20; /* 0x00450E20 */
    InputScript16 d_450E30; /* 0x00450E30 */
    InputScript16 d_450E40; /* 0x00450E40 */
} Data00450DE0;
typedef char data_rec_00450DE0_size_check[(sizeof(Data00450DE0) == 0x70) ? 1 : -1];

Data00450DE0 data_rec_00450DE0 = {
    { 0x0003, 0x1000, 0, { 0, 0, 0 }, { 0x0800, 0x1000, 0x1800, 0x0300 } },
    { 0x0003, 0x1000, 2, { 0, 0, 0 }, { 0x1000, 0x1800, 0x0800, 0x0300 } },
    { 0x0003, 0x1000, 3, { 0, 0, 0 }, { 0x1000, 0x1400, 0x0400, 0x0300 } },
    { 0x0003, 0x9100, 4, { 0, 0, 0 }, { 0x0800, 0x1000, 0x1800, 0x0300 } },
    { 0x0003, 0x9100, 5, { 0, 0, 0 }, { 0x1000, 0x1800, 0x0800, 0x0300 } },
    { 0x0003, 0x8100, 6, { 0, 0, 0 }, { 0x0800, 0x1000, 0x1800, 0x0060 } },
    { 0x0003, 0x9100, 7, { 0, 0, 0 }, { 0x1000, 0x1800, 0x0800, 0x0060 } }
};
