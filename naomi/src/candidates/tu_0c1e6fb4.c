struct SaveFileParams {
 char title[18],description[34],icon[16];
 int i68,i72;short w76,w78;int i80;short w84;char pad86[2];
 void *payload;int size;
};
extern void *func_0c1fba00(void *,int,int),*func_0c1fb940(void *,const void *,int);
extern char *func_0c1fba54(char *,const char *);
extern int func_0c206030(void *,struct SaveFileParams *);
extern char dat_0c265f70[],dat_0c265f82[],dat_0c265fa4[];
extern char dat_0c26603c[],dat_0c26604e[],dat_0c266070[];
extern char dat_0c266080[],dat_0c266092[],dat_0c2660b4[];
extern char dat_0c265fb4[],dat_0c265fc6[],dat_0c265fe8[];
extern char dat_0c2fb920[],dat_0c2fc048[],dat_0c2fc094[],dat_0c2fca14[];
extern int dat_0c266164[],dat_0c266b78[];
int func_0c1e6fb4(char kind)
{
 struct SaveFileParams params; int size;
 func_0c1fba00(&params,0,96);
 switch(kind){
 case 0:
  func_0c1fba54(params.title,dat_0c265f70);
  func_0c1fba54(params.description,dat_0c265f82);
  func_0c1fb940(params.icon,dat_0c265fa4,16);
  params.payload=dat_0c2fb920;size=0x6000;goto store_size;
 case 3:
  func_0c1fba54(params.title,dat_0c26603c);
  func_0c1fba54(params.description,dat_0c26604e);
  func_0c1fb940(params.icon,dat_0c266070,16);
  params.payload=dat_0c2fc048;size=76;goto store_size;
 case 4:
  func_0c1fba54(params.title,dat_0c266080);
  func_0c1fba54(params.description,dat_0c266092);
  func_0c1fb940(params.icon,dat_0c2660b4,16);
  params.payload=dat_0c2fc094;params.size=0x980;break;
 case 2:break;
 case 1:default:
  func_0c1fba54(params.title,dat_0c265fb4);
  func_0c1fba54(params.description,dat_0c265fc6);
  func_0c1fb940(params.icon,dat_0c265fe8,16);
  params.payload=dat_0c2fb920;size=0x728;
store_size: params.size=size;break;
 }
 params.i68=dat_0c266164[kind];params.i72=dat_0c266b78[kind];
 params.w76=1;params.w78=5;params.i80=0;params.w84=0;
 return func_0c206030(dat_0c2fca14,&params);
}

struct VmuTimestamp { short year; char month,day,hour,minute,second,weekday; };
struct SdkTimestamp { short year; char month,day,hour,minute,second,weekday; char pad[4]; };
extern int func_0c1f8f60(struct SdkTimestamp *);
extern int func_0c205df0(int,const char *,void *,int,struct VmuTimestamp *,unsigned);
extern char dat_0c23336c[],dat_0c23335c[],dat_0c23339c[],dat_0c23338c[],dat_0c23337c[];
int func_0c1e7120(char kind,int device)
{
 int status,result;const char *filename;unsigned flags;
 struct SdkTimestamp clock;struct VmuTimestamp stamp;
 status=func_0c1e6fb4(kind);
 func_0c1f8f60(&clock);
 stamp.year=clock.year;stamp.month=clock.month;stamp.day=clock.day;
 stamp.hour=clock.hour;stamp.minute=clock.minute;stamp.second=clock.second;stamp.weekday=clock.weekday;
 switch(kind){
 case 0:filename=dat_0c23336c;goto common_flags;
 case 1:filename=dat_0c23335c;goto common_flags;
 case 2:filename=dat_0c23339c;goto common_flags;
 case 3:filename=dat_0c23338c;
common_flags: flags=0x80000000u;break;
 case 4:filename=dat_0c23337c;flags=0x800000ffu;break;
 default:return -256;
 }
 if(status!=-256)result=func_0c205df0(device,filename,dat_0c2fca14,status,&stamp,flags);
 else return status;
 return result;
}
