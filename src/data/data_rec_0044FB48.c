/* Descriptors for func_001F7490-func_001F7A20: D_0044FB48/58 go to
 * func_00189660, D_0044FB68/80/90/A0 to func_00189310. */
#include "mvc2_input_script.h"
typedef struct {
    InputScript16 d_44FB48; /* 0x0044FB48 */
    InputScript16 d_44FB58; /* 0x0044FB58 */
    InputScript24 d_44FB68; /* 0x0044FB68 */
    InputScript16 d_44FB80; /* 0x0044FB80 */
    InputScript16 d_44FB90; /* 0x0044FB90 */
    InputScript16 d_44FBA0; /* 0x0044FBA0 */
} Data0044FB48;
typedef char data_rec_0044FB48_size_check[(sizeof(Data0044FB48) == 0x68) ? 1 : -1];

Data0044FB48 data_rec_0044FB48 = {
    { 0x0028, 0x1000, 0, { 0, 0, 0 }, { 0x0400, 0x0800, 0x0300, 0x0000 } },
    { 0x0028, 0x1000, 1, { 0, 0, 0 }, { 0x1000, 0x2000, 0x0060, 0x0000 } },
    { 0x0002, 0x2000, 2, { 0, 0, 0 }, { 0x1000, 0x2000, 0x0060, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 } },
    { 0x0003, 0x9100, 3, { 0, 0, 0 }, { 0x1000, 0x1400, 0x0400, 0x0060 } },
    { 0x0003, 0x9100, 4, { 0, 0, 0 }, { 0x1000, 0x1800, 0x0800, 0x0300 } },
    { 0x0003, 0xA100, 7, { 0, 0, 0 }, { 0x1000, 0x1800, 0x0800, 0x0060 } }
};
