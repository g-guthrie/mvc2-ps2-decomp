/* Native core actor-state initialization callbacks. */
typedef unsigned char u8;
typedef signed short s16;
extern void func_00185490(u8 *);
extern int func_001757E0(u8 *,int,int);
extern void func_00175C00(u8 *,int);
void func_0017C390(u8 *p) {
 p[6]++;
 *(s16 *)(p+0x1C)=16;
 *(float *)(p+0x38)=*(float *)(p+0x430);
 p[0x20D]=0;
 func_00185490(p);
 func_001757E0(p,24,0);
}
void func_0017CB70(u8 *p) {
 p[0x404]=255;
 p[0x405]=16;
 p[6]++;
 p[0x211]=0;
 p[0x13C]=1;
 p[0x1F5]=80;
 func_001757E0(p,1,1);
 func_00175C00(p,1);
}
void func_0017CE90(u8 *p) {
 p[0x404]=255;
 p[0x405]=16;
 p[6]++;
 p[0x211]=0;
 p[0x13C]=1;
 p[0x1F5]=80;
 func_001757E0(p,1,1);
 func_00175C00(p,1);
}

extern void func_00186900(u8 *);
extern void func_001866A0(u8 *);
extern void func_00163930(u8 *,int);
extern void func_001E3710(u8 *,int);
void func_0017CCF0(u8 *p) {
 p[6]++;
 p[0x211]=0;
 p[0x13C]=1;
 func_00186900(p);
 p[0x1F5]=80;
 func_001757E0(p,1,1);
 func_00175C00(p,1);
}
void func_0017C8F0(u8 *p) {
 p[0x404]=255;
 p[0x405]=16;
 p[6]++;
 p[0x211]=0;
 p[0x13C]=1;
 func_001866A0(p);
 p[0x1F5]=80;
 func_001757E0(p,1,1);
 func_00175C00(p,1);
 *(s16 *)(p+0x1C)=(p[0x425]-1)*10;
}
typedef struct { float x,y; } Vec2;
typedef struct { Vec2 xy; float z; } Vec3;
void func_0017CAA0(u8 *p) {
 Vec3 position;
 p[6]++;
 *(float *)(p+0x38)=*(float *)(p+0x430);
 p[0x20D]=0;
 func_001757E0(p,24,1);
 p[0x268]=3;
 position.xy=*(Vec2 *)(p+0x260);
 position.z=*(float *)(p+0x3C);
 func_00163930((u8 *)&position,*(s16 *)(p+0x140));
 func_001E3710(p,63);
}
