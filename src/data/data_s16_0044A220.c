/* func_00194E40 uses the selector at object +0x21 only when it is <4, then reads this row’s signed halfwords at offsets 0,2,4. The first pair is scaled into object coordinates; the last halfword selects an 8-byte sample in the row’s pointer target. */
typedef signed short s16;
s16 data_s16_0044A220[3] = { -22, 77, 0 };
