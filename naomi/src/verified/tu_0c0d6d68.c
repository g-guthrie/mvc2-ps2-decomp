#include "objects.h"
extern unsigned int dat_0c2488ac[];
extern unsigned char dat_0c248850[],dat_0c24885e[],dat_0c24886c[],dat_0c24887c[],dat_0c24888c[],dat_0c24889c[];
extern unsigned char func_0c0465cc(struct Actor *),func_0c046b6c(struct Actor *),func_0c0469f4(struct Actor *),func_0c046d3c(struct Actor *),func_0c047068(struct Actor *,unsigned char *,unsigned char *),func_0c046e7e(struct Actor *,unsigned char *,unsigned char *),func_0c046dd0(struct Actor *,int);
extern int func_0c046d54(struct Actor *);
extern void func_0c045f1c(struct Actor *),func_0c0463fc(struct Actor *),func_0c047aac(struct Actor *,unsigned char *),func_0c045248(struct Actor *,int);
unsigned char func_0c0d6e1a(struct Actor *),func_0c0d6ea4(struct Actor *),func_0c0d6eea(struct Actor *),func_0c0d6f48(struct Actor *),func_0c0d6fc4(struct Actor *),func_0c0d7014(struct Actor *);
int func_0c0d7064(struct Actor *),func_0c0d70a4(struct Actor *);
void func_0c0d6d68(struct Actor *a){register unsigned int i;register unsigned int limit=112;register unsigned int *out=(unsigned int *)a->p428;register unsigned int *in=dat_0c2488ac;i=0;copy_next:*(unsigned int *)((char *)out+i)=*(unsigned int *)((char *)in+i);i+=4;if(i<limit)goto copy_next;}
void func_0c0d6d84(struct Actor *a){if(func_0c0465cc(a))return;if(func_0c046b6c(a))return;if(func_0c0469f4(a))return;if(func_0c046d3c(a))return;if(func_0c0d7014(a))return;if(func_0c0d6fc4(a))return;if(func_0c0d6e1a(a))return;if(func_0c0d6ea4(a))return;if(func_0c0d6eea(a))return;if(func_0c0d6f48(a))return;if(func_0c0d7064(a))return;if(func_0c0d70a4(a))return;func_0c045f1c(a);func_0c0463fc(a);}
unsigned char func_0c0d6e1a(struct Actor *a){struct ActorSub2a4 *context=&a->sub2a4;
 if(!func_0c047068(a,dat_0c248850,a->x36c))goto failed_state;if(context->b2){failed_state:return 0;}
 func_0c047aac(a,a->x36c);a->b5=0;a->b7=0;a->b6=0;a->b1e9=0;func_0c045248(a,21);return 1;}
unsigned char func_0c0d6ea4(struct Actor *a){if(!func_0c047068(a,dat_0c24885e,a->x374))return 0;func_0c047aac(a,a->x374);a->b5=0;a->b7=0;a->b6=0;a->b1e9=1;func_0c045248(a,21);return 1;}
unsigned char func_0c0d6eea(struct Actor *a){if(!func_0c046e7e(a,dat_0c24886c,a->x37c))goto failed_input;func_0c047aac(a,a->x37c);
 if(a->b1d4){if(!a->b1fc){failed_input:return 0;}}a->b1d4++;a->b5=0;a->b7=0;a->b6=0;a->b1e9=6;func_0c045248(a,21);return 1;}
unsigned char func_0c0d6f48(struct Actor *a){if(!func_0c046e7e(a,dat_0c24887c,a->x384))goto fail;if(!*a->p40c){fail:return 0;}func_0c047aac(a,a->x384);a->b5=0;a->b7=0;a->b6=0;a->b1e9=2;func_0c045248(a,29);return 1;}
unsigned char func_0c0d6fc4(struct Actor *a){if(!func_0c046e7e(a,dat_0c24888c,a->x38c))goto fail;if(!*a->p40c){fail:return 0;}func_0c047aac(a,a->x38c);a->b5=0;a->b7=0;a->b6=0;a->b1e9=4;func_0c045248(a,29);return 1;}
unsigned char func_0c0d7014(struct Actor *a){if(!func_0c046e7e(a,dat_0c24889c,a->x394))goto fail;if(!*a->p40c){fail:return 0;}func_0c047aac(a,a->x394);a->b5=0;a->b7=0;a->b6=0;a->b1e9=3;func_0c045248(a,29);return 1;}
int func_0c0d7064(struct Actor *a){if(!func_0c046d54(a))goto fail;if(!*a->p40c){fail:return 0;}a->b1e9=11;a->b5=0;func_0c045248(a,29);a->b6=a->b7=0;return 1;}
int func_0c0d70a4(struct Actor *a){if(!func_0c046dd0(a,7))return 0;a->b1e9=7;a->b5=0;func_0c045248(a,21);a->b6=a->b7=0;return 1;}
