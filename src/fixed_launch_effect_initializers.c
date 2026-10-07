typedef unsigned char u8;
/* Retail offsets occupy a 16-byte-aligned stack slot; the helper reads x/y. */
typedef float PlanarOffset[2] __attribute__((aligned(16)));
extern void func_0015D010(u8 *,float *),func_0018C6E0(u8 *),func_001757E0(u8 *,int,int);
void func_00214B00(u8 *p) {
 PlanarOffset position;position[0]=-53.33333206176757812500f;position[1]=171.42855834960937500000f;
 func_0015D010(p,position);p[0x1b4]=10;func_0018C6E0(p);func_001757E0(p,15,1);
}
void func_00214B60(u8 *p) {
 PlanarOffset position;position[0]=-53.33333206176757812500f;position[1]=171.42855834960937500000f;
 func_0015D010(p,position);p[0x1b4]=10;func_0018C6E0(p);func_001757E0(p,15,2);
}
void func_00214BC0(u8 *p) {
 PlanarOffset position;position[0]=-53.33333206176757812500f;position[1]=171.42855834960937500000f;
 func_0015D010(p,position);p[0x1b4]=10;func_0018C6E0(p);func_001757E0(p,15,3);
}
void func_00214CB0(u8 *p) {
 PlanarOffset position;position[0]=-53.33333206176757812500f;position[1]=171.42855834960937500000f;
 func_0015D010(p,position);p[0x1b4]=10;func_0018C6E0(p);func_001757E0(p,15,8);
}
