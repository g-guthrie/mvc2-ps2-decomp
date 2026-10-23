/* Initialize contact-lane motion and dispatch its four unary phases. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef struct {u8 pad[0x7C];s16 counters[];} SharedCounters;
extern SharedCounters *D_004C2794 __attribute__((section(".sdata")));
extern const u8 D_004C1820[] __attribute__((section(".sdata")));
extern const u8 D_004C1824[] __attribute__((section(".sdata")));
extern const float D_0045E030[][2],D_0045E034[][2];
extern void func_0018C4B0(u8 *,int),func_00185490(u8 *),func_00183D10(u8 *);
struct Event;
extern struct Event *func_001E0A60(void *,u8);
extern int func_001757E0(u8 *,int,int);
void func_00325120(u8 *p)
{
 unsigned int frame;
 unsigned int mode;
 p[6]++;func_0018C4B0(p,5);func_00185490(p);func_00183D10(p);
 mode=p[0x1B7];frame=8;
 p[0x1B5]=D_004C1820[mode];
 p[0x1B2]=*(u16*)(p+0x1C0)=0;
 *(int*)(p+0x1D8)=0;
 D_004C2794->counters[p[2]]++;
 p[0x20D]=0;*(s16*)(p+0x1E)=D_004C1824[mode];p[0x22]=0;
 *(float*)(p+0x5C)=D_0045E030[mode][0];*(float*)(p+0x68)=D_0045E034[mode][0];
 if(func_001E0A60(p,0))p[0x13C]=0;
 else {frame+=3;p[0x13C]=1;}
 func_001757E0(p,21,(u8)frame);
}

extern void (*const jtbl_0045E020[4])(u8 *);
void func_003250F0(u8 *p)
{
 *(float*)(p+0x38)=*(float*)(p+0x430);
 jtbl_0045E020[p[6]](p);
}
