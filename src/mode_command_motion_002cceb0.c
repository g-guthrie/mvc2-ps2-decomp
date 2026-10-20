typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
typedef struct { u8 pad[0x7C]; s16 counts[8]; } Counters;
extern Counters *D_004C2794;
extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);
void func_002CCEB0(u8 *p)
{
    s8 result;
    switch(p[0x1FC]) {
    case 0:
    case 1:
        result = (s8)func_00175700(p);
        if(result < 0) {
            func_001843A0(p);
            break;
        }
        if(!*(s8 *)(p + 0x151)) break;
        p[0x151] = 0;
        p[0x1B5] = 0x19;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->counts[p[2]]++;
        break;
    case 2:
        result = (s8)func_00175700(p);
        if(result < 0) {
            func_001843A0(p);
            break;
        }
        if(!p[6]) break;
        if(*(s8 *)(p + 0x151)) {
            p[0x151] = 0;
            p[0x1B5] = 0x13;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            D_004C2794->counts[p[2]]++;
        }
        if(*(s8 *)(p + 0x150)) {
            f32 step;
            if(p[0x1E6]) step = 3.3333332538604736f;
            else step = -3.3333332538604736f;
            *(f32 *)(p + 0x34) += step;
        }
        break;
    }
}
