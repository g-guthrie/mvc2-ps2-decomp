typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u8 *D_004C2840 __attribute__((section(".sdata")));
extern void func_0012E6B0(void),func_001E40E0(void),func_001E4140(void);
extern void func_003DA650(u8),func_00170160(int),func_001E4480(u16,u32);
extern void func_001E3F50(s8),func_001E4340(u32),func_001E3FE0(void),func_001E3CE0(int);
extern void func_0013E820(int),func_0013E330(void),func_003DA6F0(u8),func_0012E780(u32);

void func_0016E990(void)
{
 func_0012E6B0();
 (*(s8*)(D_004C2840+0x92))++;
 *(s16*)(D_004C2840+8)=300;
 *(s16*)(D_004C2840+0xE)=5;
 func_001E40E0();
 func_001E4140();
 func_003DA650(13);
 func_003DA650(14);
 func_003DA650(18);
 func_00170160(8);
 func_001E4480(6,1);
 func_001E3F50(24);
 func_001E4340(1);
 func_001E3FE0();
 func_001E3CE0(47);
 func_0013E820(0);
 func_0013E820(2);
 func_0013E820(4);
 func_0013E820(6);
 func_0013E820(1);
 func_0013E820(3);
 func_0013E820(5);
 func_0013E820(7);
 func_0013E330();
 func_003DA6F0(18);
 func_0012E780(11);
 func_0012E780(12);
}
