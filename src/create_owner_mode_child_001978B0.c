typedef unsigned char u8;
typedef short s16;
extern void *func_003DA750(void *,int,int);
extern void func_00197920(u8 *);
extern void func_001B6830(u8 *);
void func_001978B0(u8 *owner,u8 mode){
 u8 *p=func_003DA750(0,3,1);
 if(p){
 *(void (**)(u8 *))(p+16)=func_00197920;
 *(u8 **)(p+24)=owner;
 p[1]=owner[1];
 p[32]=mode;
 *(s16 *)(p+38)=771;
 }
}

void func_001B6750(u8 *owner,u8 mode){
 u8 *p=func_003DA750(0,3,0);
 if(p){
 *(void (**)(u8 *))(p+16)=func_001B6830;
 *(u8 **)(p+24)=owner;
 p[32]=mode;
 p[1]=owner[1];
 *(s16 *)(p+38)=5377;
 }
}

extern unsigned int D_0044FDE0[];
extern unsigned int D_0044FE20[];
extern void func_00176160(u8 *, int, int, int);
extern void func_001757E0(u8 *, int, int);

void func_001FE580(u8 *p) {
    p[6]++;
    p[0x13C] = 1;
    func_001978B0(p, 0);
    func_00176160(p, 2, D_0044FDE0[p[0x25]], 1);
    func_001757E0(p, 18, 0);
}

void func_001FFF00(u8 *p) {
    p[0x2C4] = 7;
    p[6]++;
    func_001978B0(p, 1);
    *(s16 *)(p + 0x1C) = 60;
    *(unsigned int *)(p + 0x5C) = 0;
    *(unsigned int *)(p + 0x60) = 0;
    *(unsigned int *)(p + 0x68) = 0;
    *(unsigned int *)(p + 0x6C) = 0;
    *(unsigned int *)(p + 0x60) = 0x40092492;
    *(unsigned int *)(p + 0x6C) = 0xBD892492;
    func_00176160(p, 0, D_0044FE20[p[0x25]], 1);
    func_001757E0(p, 20, 5);
}
