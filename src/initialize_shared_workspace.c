/* Reset the shared counters, scale, and buffer when the gate byte is clear. */
typedef signed char s8;
typedef unsigned char u8;
extern s8 D_004C27C8;
extern void *D_004C28B0;
extern float D_004C26C4;
extern int D_004C26C0,D_004C26C8,D_004C26BC,D_004C26B8;
extern void *D_004C26B4;
extern u8 D_004CB280[];
extern void *func_0011D8F8(void *,int,unsigned int);
void func_00174B60(void)
{
 if (D_004C27C8 != 0) return;
 D_004C26C4=1.0f;
 D_004C26C0=16;
 D_004C26C8=0;
 D_004C26BC=400;
 D_004C26B8=0;
 D_004C26B4=D_004CB280;
 func_0011D8F8(D_004C28B0,0,3072);
}
