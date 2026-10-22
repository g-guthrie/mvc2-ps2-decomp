typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 state; u8 pad[3]; u32 channel, sound; f32 gain, scale; } SoundSlot2;
typedef struct { s16 v; s16 w; } Tab2;

extern SoundSlot2 D_004CBE80[36];
extern s32 D_004C2720 __attribute__((section(".sdata")));
extern Tab2 D_0044F1C0[];

void func_001E4A10(s32 a, s32 b, s32 c, s32 d, f32 f)
{
    extern s32 func_00422FB0(u32);
    extern s32 func_00422EA0(u32, s32, s32, s32);
    s32 state;
    s32 result;
    u32 s0;
    state = D_004CBE80[D_004C2720].state;
    if (state) {
        if (state >= 4)
            result = func_00422FB0(((D_004CBE80[D_004C2720].channel & 127) << 16) |
                ((D_004CBE80[D_004C2720].sound & 127) << 8) | (D_004C2720 & 127));
        else
            result = func_00422FB0(((D_004CBE80[D_004C2720].channel & 127) << 16) |
                ((D_004CBE80[D_004C2720].sound & 127) << 8) | 1);
        if (result < 0) {
            D_004C2720++;
            if (D_004C2720 >= 36) D_004C2720 = 0;
            return;
        }
    }
    d = D_0044F1C0[(s16)d].v;
    s0 = (((u8)a & 127) << 16) | (((u8)b & 127) << 8);
    func_00422EA0(s0 | (D_004C2720 & 127), (s8)c, (s8)d, -1);
    D_004CBE80[D_004C2720].state = 4;
    D_004CBE80[D_004C2720].channel = (u8)a;
    D_004CBE80[D_004C2720].sound = (u8)b;
    D_004CBE80[D_004C2720].gain = (f32)c;
    D_004CBE80[D_004C2720].scale = 60.0f * f;
    D_004C2720++;
    if (D_004C2720 >= 36) D_004C2720 = 0;
}
