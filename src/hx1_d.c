typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004F1F45[];
extern u8 D_004F1F46[];

s32 func_00175700(u8 *p);
void func_00158C70(f32 *v, u8 x);
void func_001E3A40(u8 *p);
void func_001757E0(u8 *p, s32 a, s32 b);
void func_001843A0(u8 *p);
void func_001266A0(u8 *p, s32 a, s32 b);

void func_0029A7C0(u8 *p)
{
    f32 v[3];
    f32 c;

    if (p[6] == 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        func_00175700(p);
        if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
            p[6]++;
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            v[0] = *(f32 *)(p + 0x34);
            v[1] = *(f32 *)(p + 0x38);
            v[2] = *(f32 *)(p + 0x3C);
            if (p[0x1E6] != 0) {
                c = 13.333333f;
            } else {
                c = -13.333333f;
            }
            v[0] += c;
            func_00158C70(v, *(u8 *)(*(u8 **)(p + 0x1DC) + 2));
            D_004F1F45[0] = 2;
            D_004F1F46[0] = 1;
            func_001E3A40(*(u8 **)(p + 0x1DC));
            func_001757E0(p, 0xF, 5);
        }
    } else {
        if ((s8)func_00175700(p) < 0) {
            func_001843A0(p);
        } else if (*(s8 *)(p + 0x151) != 0) {
            u8 *s1;
            p[0x151] = 0;
            s1 = *(u8 **)(p + 0x1DC);
            *(u8 **)(s1 + 0x1C8) = p;
            s1[0x20A] = 1;
            s1[0x20D] = 2;
            func_001266A0(p, 0, 0);
            s1[0x1B5] = 0x24;
            s1[0x1E6] = p[0x1E6];
        }
    }
}
