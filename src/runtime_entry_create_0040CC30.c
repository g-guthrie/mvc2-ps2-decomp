/* Allocate and initialize a runtime entry for the input queue interface.
 * The two virtual calls at vtable offset 0x24 query queue sizes 0 and 1.
 * The lock wrappers retain their context-pointer calling convention even
 * though this retail implementation uses only a global nesting counter. */
typedef unsigned char u8;
typedef signed int s32;
typedef struct Input Input;
typedef struct {u8 pad[0x24]; s32 (*size)(Input *,s32);} InputVtable;
struct Input {InputVtable *vtable;};
extern void func_0040D5A0(const char *,...);
extern char D_004BE280[],D_004BE2B0[];
extern void func_0040D548(s32 *);
extern void func_0040D568(void *);
extern u8 *func_0040CBD0(void);
u8 *func_0040CC30(Input *input){
 s32 context;u8 *p;s32 total,i;
 if(!input){func_0040D5A0(D_004BE280);return 0;}
 func_0040D548(&context);
 p=func_0040CBD0();
 if(!p){func_0040D5A0(D_004BE2B0);goto done;}
 p[1]=0;*(Input **)(p+8)=input;
 total=input->vtable->size(input,0);
 total+=input->vtable->size(input,1);
 *(s32 *)(p+0x18)=total;
 *(s32 *)(p+0x14)=(total*8)/10;
 for(i=15;i>=0;i--) *(s32 *)(p+0x70+i*0x40)=0;
 p[0]=1;
 done:func_0040D568(&context);return p;
}
