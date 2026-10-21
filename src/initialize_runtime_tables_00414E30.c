/* Reset packed-handle storage, bounded runtime slots, and byte lookup state. */
extern unsigned int D_0057FB70[];
struct RuntimeEntrySlot { int handle; unsigned int state; };
extern struct RuntimeEntrySlot D_0057E570[];
extern unsigned char D_0057ED70[];
extern int D_004C28A8;
extern int D_004C28A4;
extern void *func_0011D8F8(void *,int,unsigned int);
void func_00414E30(void)
{
 int i;
 for(i=0;i<4096;i++) D_0057FB70[i]=-1;
 for(i=0;i<256;i++) {D_0057E570[i].handle=-1;D_0057E570[i].state=0;}
 D_004C28A8=0;
 D_004C28A4=0;
 func_0011D8F8(D_0057ED70,-1,0xe00);
}
