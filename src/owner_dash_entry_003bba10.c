typedef unsigned char u8;typedef unsigned short u16;typedef short s16;
typedef struct {u8 pad[0x7C];s16 count[2];} Counters;
extern Counters *D_004C2794 __attribute__((section(".sdata")));
extern void func_003BD840(u8*),func_003BD290(u8*);extern int func_001757E0(u8*,int,int);
void func_003BBA10(u8*p) {
 u8 *owner;float offset,speed;
 ++p[4];p[5]=0;p[6]=0;owner=*(u8**)(p+0x18);func_003BD840(p);
 *(float*)(p+0x34)=*(float*)(owner+0x34);*(float*)(p+0x38)=*(float*)(owner+0x38);*(s16*)(p+0x1C)=96;offset=106.66666412353516f;speed=3.3333332538604736f;
 if(!owner[0x1E6]) {offset=-offset;speed=-speed;}
 *(float*)(p+0x34)+=offset;*(float*)(p+0x5C)=speed;
 *(float*)(p+0x68)=0;*(float*)(p+0x60)=0;*(float*)(p+0x6C)=0;func_003BD290(p);
 p[0x1B5]=21;p[0x1B2]=*(u16*)(p+0x1C0)=0;*(int*)(p+0x1D8)=0;++D_004C2794->count[p[2]];
 func_001757E0(p,25,13);
}
