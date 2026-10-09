/* Select one of two byte-state presets and return success. */
typedef unsigned char u8;
extern int func_00417A40(void);
int func_00173590(u8 *p)
{
 if (func_00417A40() & 1) {
  p[0x544]=2;
  p[0x545]=0;
  p[0x546]=15;
 } else {
  p[0x544]=2;
  p[0x545]=14;
  p[0x546]=12;
 }
 p[0x547]=42;
 p[0x520]=7;
 return 0;
}
