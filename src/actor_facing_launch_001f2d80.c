#pragma padloop on
typedef unsigned char u8;typedef short s16;
typedef struct {u8 pad[6];u8 phase;u8 pad7[0x15];s16 timer;u8 pad1E[0x3E];float vx,vy,vz,ax;u8 pad6C[0x17A];u8 facing;u8 pad1E7[0x82];u8 kind;u8 pad26A[0x19A];u8 flashValue,flashTimer;} Actor;
extern void func_001F0420(u8*),func_001906C0(u8*,s16,u8,u8);
extern int func_001757E0(u8*,int,int);
void func_001F2D80(u8*raw) {
 Actor *p=(Actor*)raw;
 if(p->kind==6){p->flashValue=255;p->flashTimer=16;}
 p->phase++;func_001F0420(raw);
 p->vx=6.6666665077209473f;p->ax=-0.1041666641831398f;
 if(!p->facing){p->vx=-p->vx;p->ax=-p->ax;}
 p->timer=40;
 func_001757E0(raw,15,35);func_001906C0(raw,10,50,60);
}
