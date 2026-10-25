typedef unsigned char u8;typedef unsigned short u16;typedef short s16;typedef unsigned int u32;
typedef struct {u8 pre8[8];u32 dirty;u8 pre12[6];u16 flags[3];u8 tail[24];} Frame;
extern Frame D_004F54D0[];
void func_001B5A40(u8*p){
 u16 mask=0xF000,keep=0x9FFF;
 u8*owner=*(u8**)(p+0x18);
 Frame *f;
 p[6]++;p[0x13c]=0;
 f=&D_004F54D0[*(s16*)(owner+0x13e)+2];
 f->dirty=1;
 f->flags[0]|=mask;f->flags[1]|=mask;f->flags[2]|=mask;
 f->flags[0]&=keep;f->flags[1]&=keep;f->flags[2]&=keep;
}
