typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef struct {s16 x,y;s8 effect;u8 animation;} AnimationStateRecord;
extern AnimationStateRecord D_0044C0E0[22];
extern void func_001BDDE0(u8 *,void *);
extern int func_00175580(u8 *,int,int,int);
void func_001BDDB0(u8 *p,void *owner_context)
{
    u8 *owner=(u8*)owner_context;
    p[5]++;
    *(float*)(p+0x38)=*(float*)(*(u8**)(owner+0x18)+0x430);
    *(float*)(p+0x54)=1.5f;
    func_001BDDE0(p,owner_context);
}
void func_001BC990(u8 *p,void *owner_context)
{
    u8 *owner=(u8*)owner_context;
    AnimationStateRecord *row;
    int facing;
    if(owner[0x1E4]!=0x15 || owner[0x1FD]!=2 || *(u16*)(owner+0x168)!=0x1502 || *(s8*)(owner+0x150)==0) {
        p[4]++;
        p[0x13C]=0;
        return;
    }
    row=&D_0044C0E0[p[0x20]];
    facing=*(s16*)(owner+0x140);
    *(s16*)(p+0x140)=facing;
    if(facing==0)
        *(float*)(p+0x34)=*(float*)(owner+0x34)+1.66666662693023681640625f*(float)row->x;
    else
        *(float*)(p+0x34)=*(float*)(owner+0x34)-1.66666662693023681640625f*(float)row->x;
    *(float*)(p+0x38)=*(float*)(owner+0x38)+2.142857074737548828125f*(float)row->y;
    func_00175580(p,0x1B,row->animation,*(s8*)(owner+0x150)&0xF);
}

extern s16 D_0044C170[14][2];
extern void func_001BDB70(u8 *,void *);
void func_001BDA80(u8 *p,void *owner_context)
{
 u8 *owner=(u8*)owner_context;
 p[5]++;
 p[0x13C]=1;
 *(float*)(p+0x118)=1.0f;
 if(*(s16*)(p+0x140)==0)
  *(float*)(p+0x34)=*(float*)(owner+0x34)+1.66666662693023681640625f*(float)D_0044C170[p[0x23]][0];
 else
  *(float*)(p+0x34)=*(float*)(owner+0x34)-1.66666662693023681640625f*(float)D_0044C170[p[0x23]][0];
 *(float*)(p+0x38)=*(float*)(owner+0x38)+2.142857074737548828125f*(float)D_0044C170[p[0x23]][1];
 func_001BDB70(p,owner_context);
}
