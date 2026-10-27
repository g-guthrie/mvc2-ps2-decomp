/* Placeholder: actor ownership, script bounds, and DATA callback type remain unproved. */
#pragma padloop on
typedef unsigned char u8; typedef unsigned short u16;
typedef struct SA37_R {u8 *buf;u16 pos;u8 pad6,b7;} SA37_R;
typedef struct SA37_J0 {u8 pad0[0x454];u8 b454;u8 pad455[0x4C8-0x455];union {int integer;float real;} w4c8;} SA37_J0;
extern void func_0016B0C0(SA37_J0 *,SA37_R *,int);
extern int func_00174170(void);
extern short D_004D1802;
int func_00166FC0(u8 *actor,u8 *cursor) {
 SA37_J0 *p=(SA37_J0 *)actor; SA37_R *script=(SA37_R *)cursor;
 u8 *choices; int i;
 func_0016B0C0(p,script,0);
 choices=script->buf;
 choices+=script->pos;script->pos+=7;
 for(i=0;i<3;i++,choices+=2) {if(choices[1]>D_004D1802)break;}
 p->pad455[0x492-0x455]=choices[0];p->pad455[0x494-0x455]=1;p->pad0[0x451]=0;p->pad0[0x452]=0;p->pad0[0x453]=0;
 return 1;
}
