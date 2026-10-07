typedef unsigned char u8;
extern void func_001757E0(u8 *,int,int);
void func_0038DDA0(u8 *p) {
 u8 *owner=*(u8 **)(p+0x18);
 u8 *record=owner+0x2b8;
 ++p[5];func_001757E0(p,21,13);
 if(p[1]==owner[1]) record[2]=0;
}

void func_0038E0B0(u8 *p) {
 u8 *owner=*(u8 **)(p+0x18);
 u8 *record=owner+0x2b8;
 ++p[5];func_001757E0(p,21,18);
 if(p[1]==owner[1]) record[2]=0;
}

void func_0039BF30(u8 *p) {
 u8 *owner=*(u8 **)(p+0x18);
 u8 *record=owner+0x2b8;
 ++p[5];func_001757E0(p,21,13);
 if(p[1]==owner[1]) record[2]=0;
}

void func_0039C2B0(u8 *p) {
 u8 *owner=*(u8 **)(p+0x18);
 u8 *record=owner+0x2b8;
 ++p[5];func_001757E0(p,21,18);
 if(p[1]==owner[1]) record[2]=0;
}
