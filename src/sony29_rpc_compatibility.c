extern char D_0043824C[];
extern char D_004C70A8[];
extern void *D_00438324;
extern int func_0011D6A8(const void *, const void *, unsigned int);
int func_0010B298(void)
{
 const void *reference = D_0043824C;
 const void *current = D_004C70A8;
 return func_0011D6A8(current,reference,4) &&
        func_0011D6A8(current,D_00438324,4) &&
        func_0011D6A8(reference,D_00438324,4);
}
typedef unsigned int u32;
extern int func_0010B198(void);
extern char D_004C7080[];
extern u32 D_004C6E80[];
extern int func_00106E68(void *,int,int,void *,int,void *,int,void (*)(void *),void *);
int func_0010B770(u32 value)
{
 if(func_0010B198()<0)return -65536;
 if(func_0010B298())return -65540;
 D_004C6E80[0]=value;
 if(func_00106E68(D_004C7080,8,0,D_004C6E80,4,D_004C6E80,4,0,0)<0)return -65537;
 return D_004C6E80[0];
}
int func_0010B8A0(u32 value)
{
 if(func_0010B198()<0)return -65536;
 if(func_0010B298())return -65540;
 D_004C6E80[0]=value;
 if(func_00106E68(D_004C7080,10,0,D_004C6E80,4,D_004C6E80,4,0,0)<0)return -65537;
 return D_004C6E80[0];
}

extern char D_004C6C28[];
extern void *D_00438310;
int func_00107DC8(void)
{
 const void *reference = D_0043824C;
 const void *current = D_004C6C28;
 return func_0011D6A8(current,reference,4) &&
        func_0011D6A8(current,D_00438310,4) &&
        func_0011D6A8(reference,D_00438310,4);
}