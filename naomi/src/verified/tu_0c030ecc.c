#include "objects.h"
extern struct ActorFlags *dat_0c2d6f84;
extern void (*table_0c23b1ac[])(void);
extern unsigned char dat_0c2d7088[],dat_0c0261ec[];
extern struct Dat_13bb5c dat_0c2f8338;
extern void func_0c038fb8(void),func_0c0382a4(void),func_0c0377fc(void);
extern void func_0c026a28(void),func_0c0377d0(void),func_0c036568(void);
extern void func_0c037656(int),func_0c02c314(void *);
void func_0c030ecc(void)
{
 unsigned char *actor;
 dat_0c2d6f84->b46=1;
 dat_0c2d6f84->b128++;
 table_0c23b1ac[dat_0c2d6f84->b2]();
 actor=dat_0c2d7088;
 do {
 ((struct Actor *)actor)->w420=144;
 ((struct Actor *)actor)->w424=144;
 actor+=0x5a4;
 }while(actor<dat_0c2d7088+0x21d8);
 if(dat_0c2d6f84->i90!=-1)
 ++dat_0c2d6f84->i90;
 func_0c038fb8();
 dat_0c2f8338.b3b=(dat_0c2f8338.b3b+1)&15;
 if(dat_0c2d6f84->s8){func_0c0382a4();func_0c0377fc();}
 func_0c026a28();func_0c0377d0();
 if(dat_0c2d6f84->s8){
 func_0c036568();func_0c037656(3);func_0c037656(4);
 func_0c037656(1);func_0c037656(2);
 }
 func_0c02c314(dat_0c0261ec);
}
