typedef unsigned char u8;typedef signed short s16;typedef float f32;
extern int func_001757E0(u8 *,int,int);
typedef struct {u8 gap[0x5c];f32 vx,vy,vz,ax,ay;} Motion;
void func_0027F3D0(u8 *p) {
 Motion *m=(Motion *)p;
 f32 offset;
 p[7]++;offset=1066.6666259765625f;*(f32 *)(p+0x34)=*(f32 *)(*(u8 **)(p+0x220)+0x34);m->vx=-13.333333015441895f;
 if (*(s16 *)(p+0x140)!=0) {offset=-offset;m->vx=-m->vx;}
 m->vy=34.28571319580078f;m->ax=0.0f;m->ay=-2.142857074737549f;
 *(s16 *)(p+0x1c)=28;*(s16 *)(p+0x1e)=4;*(f32 *)(p+0x34)+=offset;*(f32 *)(p+0x38)=*(f32 *)(p+0x430);func_001757E0(p,19,4);
}
