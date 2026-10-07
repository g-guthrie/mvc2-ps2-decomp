/* Apply the stance flip, clear planar motion, and spawn the launch effect. */
typedef unsigned char u8;
extern void func_001757E0(u8 *,int,int);
extern void func_0015D010(u8 *,float *);
extern void func_0018C6E0(u8 *);
void func_00247AD0(u8 *p) {
 float position[3];
 if (p[0x22]&1) {p[0x1e6]^=1; *(short *)(p+0x140)=p[0x1e6];}
 p[0x1b4]=10; func_001757E0(p,15,2);
 *(float *)(p+0x5c)=0.0f; *(float *)(p+0x60)=0.0f;
 *(float *)(p+0x68)=0.0f; *(float *)(p+0x6c)=0.0f;
 position[0]=-238.33332824707031250000f; position[1]=184.28570556640625000000f; position[2]=0.0f;
 func_0015D010(p,position); func_0018C6E0(p);
}
void func_00247B70(u8 *p) {
 float position[3];
 if (p[0x22]&1) {p[0x1e6]^=1; *(short *)(p+0x140)=p[0x1e6];}
 p[0x1b4]=10; func_001757E0(p,15,4);
 *(float *)(p+0x5c)=0.0f; *(float *)(p+0x60)=0.0f;
 *(float *)(p+0x68)=0.0f; *(float *)(p+0x6c)=0.0f;
 position[0]=-238.33332824707031250000f; position[1]=147.85713195800781250000f; position[2]=0.0f;
 func_0015D010(p,position); func_0018C6E0(p);
}
void func_00247C10(u8 *p) {
 float position[3];
 if (p[0x22]&1) {p[0x1e6]^=1; *(short *)(p+0x140)=p[0x1e6];}
 p[0x1b4]=10; func_001757E0(p,15,3);
 *(float *)(p+0x5c)=0.0f; *(float *)(p+0x60)=0.0f;
 *(float *)(p+0x68)=0.0f; *(float *)(p+0x6c)=0.0f;
 position[0]=-238.33332824707031250000f; position[1]=147.85713195800781250000f; position[2]=0.0f;
 func_0015D010(p,position); func_0018C6E0(p);
}
void func_002FF580(u8 *p) {
 float position[3];
 if (p[0x22]&2) {p[0x1e6]^=1; *(short *)(p+0x140)=p[0x1e6];}
 p[0x1b4]=10; func_001757E0(p,15,6);
 *(float *)(p+0x5c)=0.0f; *(float *)(p+0x60)=0.0f;
 *(float *)(p+0x68)=0.0f; *(float *)(p+0x6c)=0.0f;
 position[0]=-166.66665649414062500000f; position[1]=32.14285659790039062500f; position[2]=0.0f;
 func_0015D010(p,position); func_0018C6E0(p);
}
