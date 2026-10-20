typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
extern u8 *D_004C2794;
extern s8 D_004C279C[2];
typedef struct { u8 *list[94]; } ActorList;
extern ActorList D_004D3170[];
void func_001E7F60(u8 *p) {
 s32 slot,n;
 if(D_004C2794[6]!=0) return;
 p[0x1B3]=0;
 slot=p[2];
 n=D_004C279C[slot];
 if(n>=94) return;
 D_004D3170[slot].list[D_004C279C[slot]++]=p;
}
