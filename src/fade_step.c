/* Decrease the active fade value and release the object at zero. */
typedef unsigned char u8;
extern void func_003DAA40(u8 *);
void func_001356A0(u8 *p) {
 float value;
 p[0x13c]=1;
 value=*(float *)(p+0x74)-0.100000001490116119384765625f;
 *(float *)(p+0x74)=value;
 if(value<=0.0f) func_003DAA40(p);
}
