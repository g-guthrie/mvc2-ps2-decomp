typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;
typedef struct { u8 state; u8 pad[3]; u32 channel, sound; f32 gain, scale; } SoundSlot;
extern SoundSlot D_004CBE80[36];
extern int D_004C2720 __attribute__((section(".sdata")));
extern int func_00422FB0(u32);
void func_001E5070(int channel, int sound, int gain, f32 scale)
{
    int result;
    int state = D_004CBE80[D_004C2720].state;
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
    D_004CBE80[D_004C2720].state = 3;
    D_004CBE80[D_004C2720].channel = (u8)channel;
    D_004CBE80[D_004C2720].sound = (u8)sound;
    D_004CBE80[D_004C2720].gain = gain;
    D_004CBE80[D_004C2720].scale = scale;
    D_004C2720++;
    if (D_004C2720 >= 36) D_004C2720 = 0;
}
