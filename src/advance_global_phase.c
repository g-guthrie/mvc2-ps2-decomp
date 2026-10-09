/* Advance the global phase after either gate, otherwise run its idle handler. */
typedef signed char s8;
extern s8 *D_004C2840;
extern void func_0032C880(void);
void func_00171640(void)
{
 if (D_004C2840[0x9e] != 0 || D_004C2840[0x8f] != 0) {
  D_004C2840[3]++;
  D_004C2840[4]=0;
  D_004C2840[5]=0;
  D_004C2840[6]=0;
  D_004C2840[7]=0;
  D_004C2840[0x9e]=0;
  D_004C2840[0x19]=1;
 } else {
  func_0032C880();
 }
}
