typedef signed short s16;
typedef struct { s16 x; s16 y; } P2;

/* func_00381550 reads both signed halfwords of each four-byte motion pair: x at 0x0038159C/0x003815E0 and y through the +2 alias at 0x00381624. The signed selector comes from the source object's +0x150 field; its range is unproved. Only the six nonzero pairs are credited here. The final two zero pairs at 0x00464598 remain opaque until their selectors are shown to be used. The following callback table at 0x004645A0 is independently dispatched by native func_00381FD0 (base formed at 0x00381FD4-0x00381FE0). */
P2 data_u32_00464580[6] = {
    { -58, 83 },
    { -59, 82 },
    { -58, 83 },
    { -59, 82 },
    { -58, 83 },
    { -59, 82 },
};
