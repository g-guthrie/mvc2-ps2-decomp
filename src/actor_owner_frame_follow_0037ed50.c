#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef struct {u8 prefix[0x34];float x,y,z;} Position;
extern s16 D_004642C0[][3],D_004642C2[][3],D_004642C4[][3];
extern void *func_001BC660(void*,int);
extern void func_0037EF00(u8*,u8*);
void func_0037ED50(u8 *p,u8 *owner)
{
 Position *pos=(Position*)p;
 if(!*(s8*)(owner+0x151)||owner[0x1E4]!=21||owner[0x1FD]){++p[4];p[0x13C]=0;return;}
 if(!(*(s16*)(p+0x140)=*(s16*)(owner+0x140)))pos->x=*(float*)(owner+0x34)+1.6666666269302368f*(float)D_004642C0[*(s8*)(owner+0x150)][0];
 else pos->x=*(float*)(owner+0x34)-1.6666666269302368f*(float)D_004642C0[*(s8*)(owner+0x150)][0];
 pos->y=*(float*)(owner+0x38)+2.142857074737549f*(float)D_004642C2[*(s8*)(owner+0x150)][0];
 *(int*)(p+0x48)=D_004642C4[*(s8*)(owner+0x150)][0];
 if(*(s8*)(owner+0x151)==2){++p[5];p[0x24]=11;func_001BC660(owner,17);func_0037EF00(p,owner);}
}
