/* Provisional: captured target lifetime and slot bounds require proof. */
typedef unsigned char u8; typedef signed char s8;
void func_0035BDF0(u8 *p, void *context) {
u8 *owner=context;
u8 *work = owner + 0x2b8;
 u8 *parent = *(u8 **)(p + 0x14);
 parent[0x13c]=1;
if (*(s8 *)(parent+0x1b3)) { work[p[0x23]+1] |= 128; }
 p[4]=2; p[0x13c]=0;
}
