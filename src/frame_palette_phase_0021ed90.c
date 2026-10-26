/* Two adjacent 48-byte native frames; attribute zero is not modified. */
typedef unsigned char u8;typedef unsigned short u16;typedef short s16;typedef unsigned int u32;
typedef struct {u8 pre8[8];u32 dirty;u8 pre10[4];u16 attributes[16];} Frame;
extern Frame D_004F54D0[];
static void func_0021D280(u8*p){
 int palette=0xC000;
 Frame *frames=D_004F54D0,*first=frames,*f;
 int index=*(s16*)(p+0x13e)+1;
 u8*work=p+0x2b8;
 s16 column,row;
 first+=index;
 if((first->attributes[1]&0xF000)!=0xC000){
  work[14]=1;
  for(row=0;row<2;row++){
   f=frames;
   f+=*(s16*)(p+0x13e)+1+row;
   f->dirty=1;
   for(column=1;column<16;column++){
    u16 attribute=f->attributes[column];
    attribute&=0xFFF;attribute|=(u16)palette;f->attributes[column]=attribute;
   }
  }
 }
}

extern u8 D_004D18A0 __attribute__((section(".bss")));
void func_0021ED90(u8*p) {
 func_0021D280(p);
 if(D_004D18A0<2) p[0x13C]=0;
 else { ++p[6]; p[0x13C]=1; }
}
