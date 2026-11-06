/* 0x0c09f0ec..0x0c09fd60: stance/switch handlers, 35 functions and their pools. */
#include "objects.h"
void func_0c09fc0c(struct Actor *);
extern void func_0c0442fa(struct Actor *);
extern void func_0c043352(struct Actor *),func_0c044df4(struct Actor *),func_0c0437b8(struct Actor *),func_0c0438de(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c0421f4(struct Actor *),func_0c0420f8(struct Actor *),func_0c042018(struct Actor *),func_0c0421b8(struct Actor *),func_0c044f1c(struct Actor *),func_0c043324(struct Actor *);
void func_0c09f482(struct Actor *),func_0c09f504(struct Actor *),func_0c09f526(struct Actor *),func_0c09f5c0(struct Actor *),func_0c09f686(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c14a9fe(struct Actor *,int,int,int);
void func_0c09f210(struct Actor *),func_0c09f2d4(struct Actor *),func_0c09f378(struct Actor *),func_0c09f3dc(struct Actor *),func_0c09f42c(struct Actor *),func_0c09f572(struct Actor *),func_0c09f890(struct Actor *);
void func_0c09fa80(struct Actor *),func_0c09fae4(struct Actor *),func_0c09fb7a(struct Actor *),func_0c09fcea(struct Actor *);
extern void (*table_0c2438ac[])(struct Actor *),(*table_0c2438b4[])(struct Actor *),(*table_0c2438c4[])(struct Actor *),(*table_0c2438e8[])(struct Actor *),(*table_0c2438d0[])(struct Actor *),(*table_0c2438d8[])(struct Actor *);
void func_0c09f0ec(struct Actor *a)
{
 func_0c043352(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c044df4(a);
 if((unsigned char)a->b1fe==1){if(a->b1f9==1)func_0c09f3dc(a);else func_0c09f378(a);}
 else if(a->b1f9==1)func_0c09f2d4(a);else func_0c09f42c(a);
}
void func_0c09f172(struct Actor *a)
{
 if(a->b1e8<3){
  a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c044df4(a);
 }
 if((unsigned char)a->b1fe==1){if(a->b1f9==1)func_0c09f3dc(a);else func_0c09f378(a);}
 else if(a->b1f9==1)func_0c09f2d4(a);else func_0c09f210(a);
}
void func_0c09f210(struct Actor *a)
{
 switch(a->b1e8){
 case 3:goto first;
 case 4:goto second;
 case 5:goto first;
 case 6:goto second;
 case 7:a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c09fae4(a);break;
 case 8:func_0c09fb7a(a);break;
 case 9:goto first;
 case 10:second:func_0c09fa80(a);return;
 case 11:first:func_0c09fa80(a);break;
 case 12:func_0c09fcea(a);break;
 case 2:if(a->w1fa&0x800){func_0c09f5c0(a);return;}
 case 0:case 1:if(func_0c02a026(a)<0)func_0c0437b8(a);break;
 }
}
void func_0c09f2d4(struct Actor *a)
{
 switch(a->b1e8){
 case 3:goto first;
 case 4:goto second;
 case 5:goto first;
 case 6:goto second;
 case 7:a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c09fae4(a);break;
 case 8:func_0c09fb7a(a);break;
 case 9:goto first;
 case 10:second:func_0c09fa80(a);return;
 case 11:first:func_0c09fa80(a);break;
 case 12:func_0c09fcea(a);break;
 case 0:case 1:case 2:if(func_0c02a026(a)<0)func_0c0437b8(a);break;
 }
}
void func_0c09f378(struct Actor *a)
{
 switch(a->b1e8){
 case 3:func_0c09fa80(a);return;
 case 4:func_0c09fa80(a);break;
 case 2:func_0c09f572(a);break;
 case 0:case 1:if(func_0c02a026(a)<0)func_0c0437b8(a);break;
 }
}
void func_0c09f3dc(struct Actor *a)
{
 switch(a->b1e8){
 case 3:func_0c09fa80(a);return;
 case 4:func_0c09fa80(a);return;
 case 0:case 1:case 2:if(func_0c02a026(a)<0)func_0c0437b8(a);break;
 }
}
void func_0c09f42c(struct Actor *a)
{
 switch(a->b1e8){
 case 2:func_0c09f890(a);return;
 case 0:case 1:if(func_0c02a026(a)<0)func_0c0437b8(a);break;
 }
}
void func_0c09f46c(struct Actor *a){func_0c0421f4(a);func_0c0420f8(a);func_0c09f482(a);}
void func_0c09f482(struct Actor *a)
{
 func_0c042018(a);func_0c0421b8(a);
 if((unsigned char)a->b1fe==1){
  func_0c09f526(a);
  switch(a->b1e8){case 2:if(a->w1fa&0x1000)return;break;case 0:case 1:break;default:break;}
 }else func_0c09f504(a);
 if(func_0c044e52(a))func_0c044f1c(a);
}
void func_0c09f504(struct Actor *a){if(func_0c02a026(a)<0)func_0c0438de(a);}
void func_0c09f526(struct Actor *a)
{
 switch(a->b1e8){case 2:if(a->w1fa&0x1000){func_0c09f686(a);return;}break;case 0:case 1:break;default:break;}
 if(func_0c02a026(a)<0)func_0c0438de(a);
}
void func_0c09f572(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c0437b8(a);
 if(a->b141==1){
  int zero=0;
  a->b141=zero;a->b1a1=23;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;
  dat_0c2f83f8->arr[a->b2]++;
 }
}
void func_0c09f5c0(struct Actor *a){table_0c2438ac[a->b7](a);}
void func_0c09f5f8(struct Actor *a)
{
 a->b7++;a->b1f9=2;a->f92=a->b1d2?4.28571415f:-4.28571415f;
 a->f104=0;a->f96=8.5714283f;a->f108=-1.07142854f;
}
void func_0c09f632(struct Actor *a)
{
 if(a->f56<a->f41c){
  func_0c043324(a);a->b1f9=0;a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->f56=a->f41c;
 }
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c09f686(struct Actor *a){table_0c2438b4[a->b7](a);}
void func_0c09f698(struct Actor *a)
{
 a->b1fc=0;func_0c02a026(a);
 if(a->b141){a->f92=0;a->f96=0;a->f104=0;a->f108=0;return;}
 a->b7++;a->f92=0;a->f104=0;a->f96=0;a->f108=-0.80357140303f;
}
void func_0c09f718(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(a->b19e){
  a->b7++;a->f92=4.16666651f;if(a->b1d2)a->f92=-a->f92;
  a->f104=0;a->f96=15.0f;a->f108=-1.07142854f;a->b1d3=1;func_0c02a0c4(a,20,20);return;
 }
 if(a->f56<a->f41c){
  a->b7=3;a->b1f9=0;a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->f56=a->f41c;
  func_0c043324(a);func_0c02a0c4(a,20,21);
 return;}func_0c02a026(a);
}
void func_0c09f7f2(struct Actor *a)
{
 if(a->f56<a->f41c){
  a->b7++;a->b1f9=0;a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->f56=a->f41c;
  func_0c043324(a);func_0c02a0c4(a,20,21);
 return;}func_0c02a026(a);
}
void func_0c09f848(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c09f890(struct Actor *a){table_0c2438c4[a->b7](a);}
void func_0c09f8a2(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c0437b8(a);
 if(!(a->b19e&1)){goto L;L:if(a->b19e){struct Actor *o=a->p1b0;if(!o->b411){a->b7++;a->b1f5=2;a->s28=10;}}}
}
void func_0c09f8ea(struct Actor *a)
{
 goto again; again:
 if(a->b141==1){a->b141=0;a->f104*=4.0f;}
 if(a->b141==2){a->b141=0;a->f104*=4.0f;}
 if(a->f92*a->f104>0){a->f92=0;a->f96=0;a->f104=0;a->f108=0;}
 a->b1f5=2;
 if(a->s28--<=0&&(a->w348&0x100)){
  a->b7++;
  a->b1f5=2;
  goto call; call:
  func_0c0442fa(a);
  a->b1a1=22;
  a->w1ac=0;
  a->b19e=0;
  a->p1c4=0;
  dat_0c2f83f8->arr[a->b2]++;
  func_0c02a0c4(a,20,4);
 }
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c09f9ec(struct Actor *a)
{
 if(a->b141==1){a->f92=0;a->f96=0;a->f104=0;a->f108=0;}
 if(a->f92*a->f104>0){a->f92=0;a->f96=0;a->f104=0;a->f108=0;}
 if(a->b141==2){a->b141=0;a->f92=a->b1d2?15.83333302f:-15.83333302f;a->f104=a->b1d2?-0.625f:0.625f;}
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c09fa80(struct Actor *a)
{
 if(a->b141)a->f52 += a->b1d2 ? (float)a->b141 * 1.66666663f : -((float)a->b141 * 1.66666663f);
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c09fae4(struct Actor *a){table_0c2438d0[a->b7](a);}
void func_0c09fb1c(struct Actor *a)
{
 if(a->b19e){a->b7++;func_0c14a9fe(a,3,0,0);}
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c09fb58(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c09fb7a(struct Actor *a)
{
 struct Actor *target=a->p20c;
 table_0c2438d8[a->b7](a);
 if(target->b233==10&&target->p1b4==a)target->b236=0;
}
void func_0c09fbb4(struct Actor *a)
{
 a->b7++;a->f92=a->b1d2?3.3333333f:-3.3333333f;
 a->f104=0;a->f96=34.2857132f;a->f108=-1.60714281f;a->b1f9=2;func_0c09fc0c(a);
}
void func_0c09fc0c(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(a->f56<a->f41c){
  a->b7++;a->b1f9=0;a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->f56=a->f41c;func_0c043324(a);
 }
 func_0c02a026(a);
}
void func_0c09fc8c(struct Actor *a)
{
 if(a->b19e){a->b7++;func_0c14a9fe(a,5,0,0);}
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c09fcc8(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c09fcea(struct Actor *a){table_0c2438e8[a->b7](a);}
void func_0c09fcfc(struct Actor *a)
{
 a->b7++;a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->f96=17.142857f;a->f108=-1.07142854f;
 func_0c02a0c4(a,20,18);
}
