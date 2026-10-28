typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
/* Three runs of u32 slots: a leading 0, 17 even ids 802..834 (0x322..0x342),
 * three zero slots, 17 odd ids 801..833 (0x321..0x341), three zero slots.
 * Ends where the resource record pair D_004468B0 begins. */
u32 data_u32_0044680C[41] = {
    0, 802, 804, 806, 808, 810, 812, 814, 816, 818, 820, 822, 824, 826, 828, 830, 832, 834, 0, 0, 0, 801, 803, 805, 807, 809, 811, 813, 815, 817, 819, 821, 823, 825, 827, 829, 831, 833, 0, 0, 0
};
