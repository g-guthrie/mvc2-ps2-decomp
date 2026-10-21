typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern int func_00174170(void);
extern int func_001757E0(u8 *,int,int);
typedef struct {u8 prefix[0x5C];f32 vx,vy;} Motion;
void func_001DD020(u8 *p) {
 Motion *m=(Motion *)p;
 s16 speed=func_00174170()&0xF0;
 if(!(m->vx<=0.0f)) speed=-speed;
 m->vx=(1.6666666269302368f*speed)/256.0f;
 m->vy=(2.142857074737549f*(f32)((func_00174170()&0xFFu)-0x80u))/256.0f;
 *(s16 *)(p+0x1C)=(func_00174170()&31)+16;
 func_001757E0(p,23,7);
}
