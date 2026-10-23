/* Entry callbacks for actor-local scratch state supplied by their dispatchers. */
typedef unsigned char u8;
extern void func_00185490(u8 *), func_00183D10(u8 *);
extern int func_001757E0(u8 *, int, int);
extern u8 D_004D18D8;
extern u8 *func_001B53E0(u8 *, int, int);
extern void func_001E3210(u8 *, int), func_001E2490(int, int), func_00191210(u8 *);

void func_002CA050(u8 *p,u8 *state)
{
 if(p[0x269]==6) {p[0x404]=255;p[0x405]=16;}
 p[7]++;
 func_00185490(p);
 *(float*)(p+0x38)=*(float*)(p+0x430);
 p[0x20D]=0;
 *(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;
 *(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
 state[8]=0;state[6]=0;state[7]=0;state[9]=0;
 func_00183D10(p);
 func_001757E0(p,21,21);
}

void func_002678B0(u8 *p,u8 *state)
{
 p[7]++;
 *(float*)(state+12)-=0.02f;
 *(float*)(state+20)-=0.02f;
 *(float*)(p+0x50)=*(float*)(state+12);
 *(float*)(p+0x54)=*(float*)(state+20);
 func_001757E0(p,22,67);
 if(!(D_004D18D8&(1<<p[2])))func_001B53E0(p,1,1);
 func_001E3210(p,35);
 func_001E2490(6,76);
 p[0x216]|=128;
 p[0x1FF]=2;
 func_00191210(p);
}
