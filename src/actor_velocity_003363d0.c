/* Provisional: native callback ownership and selector bounds remain unresolved. */
typedef unsigned char u8;typedef float f32;
void func_003363D0(u8 *p){
 p[7]++;
 *(f32 *)(p+0x60)=30.0f;
 *(f32 *)(p+0x6c)=-1.0f;
}
