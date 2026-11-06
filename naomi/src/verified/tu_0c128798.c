#include "objects.h"
extern int func_0c037d54(struct Actor *);
extern unsigned int func_0c02849a(void);
extern char table_0c24da60[][2];
int func_0c128798(struct Actor *a)
{
 int stance=a->b1f9,result;
 if(stance && stance!=2)goto invalid;
 goto inputs;inputs:if(!((*(unsigned short *)&a->sub2a4.s10=a->w1fa)&0xc00)||!a->b1a3)goto invalid;
 if(!(result=func_0c037d54(a)))return 0;
 if((unsigned char)a->b1fe==1){if(a->b1f9==2)goto invalid;goto flag_two;}
 if(a->b1f9==2)goto flag_one;
 goto random_gate;random_gate:if(a->sub2a4.b7)goto flag_two;
 goto random_value;random_value:a->sub2a4.b6=func_0c02849a()&3;a->b1f7=table_0c24da60[*(char *)&a->sub2a4.b6][0];goto done;
flag_two:a->b1f7=2;goto done;
flag_one:a->b1f7=1;goto done;
invalid:result=0;
done:return result;
}
