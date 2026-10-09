typedef unsigned char u8;
typedef signed int s32;

extern u8 *D_004C2840;
extern s32 func_00175910(u8 *state, s32 animation, s32 strength, s32 frame);

void func_0041B0E0(u8 *state)
{
	if ((*(s32 *)(D_004C2840 + 0x1C) & 1) == 0)
		func_00175910(state, 0x16, 0x1D, 0);
	else
		func_00175910(state, 0x16, 0x1D, 1);
}
