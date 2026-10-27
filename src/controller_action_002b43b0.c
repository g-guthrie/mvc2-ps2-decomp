/* Provisional: side index bounds and action table ownership require proof. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef struct {u16 buttons;u8 remainder[18];} ControllerInput;
extern ControllerInput D_004F4480[];
void func_002B43B0(u8 *p)
{
    p[7]++;
    p[0x21]=0;
    if (*(s8 *)(p+0x539)==0 && (D_004F4480[p[2]].buttons & 0x200))
        p[0x21]=1;
}
