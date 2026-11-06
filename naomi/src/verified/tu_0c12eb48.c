#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c042018(struct Actor *),func_0c0421b8(struct Actor *),func_0c0438de(struct Actor *),func_0c044f1c(struct Actor *),func_0c0421f4(struct Actor *),func_0c0420f8(struct Actor *),func_0c044df4(struct Actor *),func_0c13150c(struct Actor *),func_0c18b864(struct Actor *,int),func_0c043352(struct Actor *);
extern void (*table_0c24e084[])(struct Actor *);
void func_0c12eb48(struct Actor *a)
{
 func_0c042018(a);func_0c0421b8(a);if(func_0c02a026(a)<0){func_0c0438de(a);return;}if(func_0c044e52(a))func_0c044f1c(a);
}
void func_0c12eb8a(struct Actor *a){func_0c0421f4(a);func_0c0420f8(a);func_0c12eb48(a);}
void func_0c12eba2(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c044df4(a);
 if(func_0c02a026(a)<0)func_0c13150c(a);
 else{if(a->b141){func_0c18b864(a,a->b141-1);a->b141=0;}
  if(a->b14b){float offset=-6.66666651f;if(a->w130)offset=6.66666651f;a->f52+=offset;}}
}
void func_0c12ec3a(struct Actor *a){func_0c043352(a);func_0c12eba2(a);}
void func_0c12ec4a(struct Actor *a){table_0c24e084[a->b1ff](a);}
