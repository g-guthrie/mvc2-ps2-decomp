typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned int u32;
typedef struct {float x,y,z;} Float3;
extern s16 short_values_00472850[];
extern s16 data_00472854[];
extern void func_0039EE60(u8 *);
#define OWNER (*(u8 **)(p+24))
void residual_0039ED60(u8 *p) {
 int n;
 u32 *d,*s;
 p[4]++;
 d=(u32 *)(p+236);s=(u32 *)(OWNER+236);
 for(n=49;n>0;n--)*d++=*s++;
 p[316]=1;
 p[2]=OWNER[2];p[1]=OWNER[1];
 *(float *)(p+80)=*(float *)(OWNER+80);
 *(float *)(p+84)=*(float *)(OWNER+84);
 p[439]=OWNER[439];p[440]=OWNER[440];*(s8 *)(p+48)=*(s8 *)(OWNER+48);
 *(Float3 *)(p+80)=*(Float3 *)(OWNER+80);
 *(s8 *)(p+36)=*(s8 *)(OWNER+36);p[316]=0;
 {u8 *o=OWNER;*(float *)(p+52)=*(float *)(o+52);*(float *)(p+56)=*(float *)(o+1072);}
 *(s16 *)(p+30)=short_values_00472850[0];
 *(s16 *)(p+28)=short_values_00472850[1];
 *(s16 **)(p+160)=data_00472854;
 func_0039EE60(p);
}
