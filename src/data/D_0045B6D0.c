extern unsigned int data_u32_004C11C0[];
extern unsigned int data_ff_004C11CC[];
extern unsigned int data_u32_004C11D4[];
extern unsigned int data_ff_004C11D8[];

/* Targets of w191_n's D_0045B6D0 selector table. */
const void * const D_0045B6D0[6] = {
    &data_u32_004C11C0[2],
    data_ff_004C11CC,
    &data_ff_004C11CC[1],
    data_u32_004C11D4,
    data_ff_004C11D8,
    &data_ff_004C11D8[1],
};
