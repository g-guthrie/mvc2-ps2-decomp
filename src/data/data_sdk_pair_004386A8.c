/* func_0010C2F8 loads service ID 0x5A and passes this symbolic handler address to its syscall wrapper. */
typedef unsigned int u32;
typedef void (*SdkHandler)(void);
typedef struct { u32 service; SdkHandler handler; } SdkRegistration;
extern void func_0010C2A0(void);
SdkRegistration data_sdk_pair_004386A8[1] = { { 0x5Au, func_0010C2A0 } };
