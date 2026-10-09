typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;
typedef float f32;
typedef union { f32 value; u32 bits; } FloatBits;
typedef struct { u8 prefix[0x60]; FloatBits f60; u8 padding[8]; FloatBits f6c; } ActorView;
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern int func_001864A0(u8 *);
extern int func_002F8EB0(u8 *);
extern void func_001845F0(u8 *);
extern void func_001843A0(u8 *);
void func_002F4FC0(u8 *p, void *q)
{
    s8 result;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5c);
    *(f32 *)(p + 0x5c) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6c);
    result = (s8)func_00175700(p);
    if (result < 0) {
        if (*(u16 *)q != 0) {
            p[0x1ea] = 17;
            func_001845F0(p);
        } else {
            func_001843A0(p);
        }
    }
}

void func_002F8E40(u8 *p)
{
    if (p[0x20d] != 2)
        return;

    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5c);
    *(f32 *)(p + 0x5c) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6c);
    func_001864A0(p);
}

void func_002F94A0(u8 *p)
{
    s8 result;

    result = (s8)func_00175700(p);
    if (result < 0) {
        if (*(f32 *)(p + 0x430) < *(f32 *)(p + 0x38))
            goto set_transition;
        p[0x20d] = 0;
        goto finish;
    set_transition:
        p[0x20d] = 2;
        p[0x1ea] = 17;
    finish:
        func_002F8EB0(p);
    }
}

void func_002F89B0(u8 *p)
{
    s8 result;

    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5c);
    *(f32 *)(p + 0x5c) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6c);
    result = (s8)func_00175700(p);
    if (result < 0) {
        p[6]++;
        *(s16 *)(p + 28) = 16;
    }
}

void func_002F8A40(u8 *p)
{
    s16 timer;
    ActorView *actor = (ActorView *)p;

    func_00175700(p);
    timer = *(s16 *)(p + 28) - 1;
    *(s16 *)(p + 28) = timer;
    if (timer == 0) {
        p[6]++;
        actor->f60.bits = 0xC09A4924;
        actor->f6c.bits = 0xBE092492;
        func_001757E0(p, 18, 1);
    }
}

void func_002F8AC0(u8 *p)
{
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5c);
    *(f32 *)(p + 0x5c) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6c);
    if (*(f32 *)(p + 0x430) < *(f32 *)(p + 0x38))
        return;
    p[6]++;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    func_001757E0(p, 18, 2);
}
