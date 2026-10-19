/* Resolve resource-relative section addresses and initialize its runtime slot. */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
struct RuntimeObject;
struct RuntimeObjectInit;
extern u8 D_00632480[];
extern void func_00413DA0(struct RuntimeObject *);
extern void func_00413D50(struct RuntimeObjectInit *,s32);
void func_0016F1B0(u8 *p,s32 index) {
 u32 base=*(u32 *)(p+0x53C);
 u8 *object=D_00632480+index*20;
 *(u32 *)(p+0x16C)=base+*(u32 *)(base+0x0);
 *(s32 *)(p+0x170)=index;
 *(u32 *)(p+0x174)=base+*(u32 *)(base+0x8);
 *(u32 *)(p+0x188)=base+*(u32 *)(base+0xC);
 *(u32 *)(p+0x18C)=base+*(u32 *)(base+0x10);
 *(u32 *)object=*(u32 *)(p+0x16C);
 func_00413DA0((struct RuntimeObject *)object);
 func_00413D50((struct RuntimeObjectInit *)object,1);
 *(u32 *)(p+0x17C)=base+*(u32 *)(base+0x18);
 *(u32 *)(p+0x180)=base+*(u32 *)(base+0x1C);
 *(u32 *)(p+0x184)=base+*(u32 *)(base+0x20);
 *(u32 *)(p+0x178)=base+*(u32 *)(base+0x14);
 *(u32 *)(p+0x198)=base+*(u32 *)(base+0x24);
 *(u32 *)(p+0x19C)=base+*(u32 *)(base+0x28);
 *(u32 *)(p+0x1A4)=base+*(u32 *)(base+0x30);
 *(u32 *)(p+0x1A0)=base+*(u32 *)(base+0x2C);
 *(u32 *)(p+0x1A8)=base+*(u32 *)(base+0x34);
 *(u32 *)(p+0x1AC)=base+*(u32 *)(base+0x38);
}
