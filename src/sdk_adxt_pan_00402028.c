/* Preserve the native store-before-channel-check ordering. */
typedef unsigned char u8;typedef signed char s8;typedef signed short s16;typedef signed int s32;
extern char gAdxtDiagnostic_004BC188[],gAdxtDiagnostic_004BC1B8[];extern void func_003FB128(void*),func_003FF270(s32*,s32,s32);
void func_00402028(void*object,s32 index,s32 value){u8*p=(u8*)object;
 if(!p){func_003FB128(gAdxtDiagnostic_004BC188);return;}
 *(s16*)(p+0x42+index*2)=value;
 if(index<*(s8*)(p+3))func_003FF270(*(s32**)(p+0x0C),index,value);
 else func_003FB128(gAdxtDiagnostic_004BC1B8);
}
