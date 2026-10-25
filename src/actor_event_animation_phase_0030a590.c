#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
extern int func_00175700(u8*),func_001757E0(u8*,int,int);
extern void func_0030A4F0(u8*);
extern u8 *D_004C28DC __attribute__((section(".sdata")));
typedef unsigned int u32;
typedef float f32;
extern f32 D_0045CE50[];
typedef struct {u8 prefix[0x151];s8 frame;} FrameFlag;
static void func_0030A450(u8 *p) {
    FrameFlag *flag=(FrameFlag*)p;
    if (flag->frame < 0) {
        u32 i; p[0x209] = 1; i = flag->frame & 0x7F;
        if (i != 0) {
            f32 x; flag->frame = -0x80; x = D_0045CE50[i & 0xFF];
            if (p[0x1E6] == 0) x = -x;
            *(f32 *)(p + 0x34) += x;
        }
    }
}

void func_0030A590(u8 *p)
{
 func_0030A4F0(p);
 if((s8)func_00175700(p)<0){++p[6];if(D_004C28DC[8])func_001757E0(p,2,6);else func_001757E0(p,2,7);}
 func_0030A450(p);
}
