typedef unsigned char u8;
extern signed char func_00175700(u8 *);
extern void func_003DAA40(u8 *),func_001E7F60(u8 *);
void func_003C52B0(u8 *p,u8 *owner) {
 *(signed char *)(p+0x24)=*(signed char *)(owner+0x24);
 *(signed char *)(p+0x31)=-1;
 if(func_00175700(p)<0) func_003DAA40(p); else func_001E7F60(p);
}
