typedef unsigned char u8;

typedef struct {
    u8 pad[0x34];
    float position;
    u8 pad2[0x13C - 0x38];
    u8 active;
} Object;

extern float D_004F1F4C;
extern float D_004F1F40[];

void func_00177CE0(Object *object) {
    float low = D_004F1F4C - 320.0f - 140.0f;
    float high;
    float *table = D_004F1F40;

    if (object->position <= low) {
        object->active = 0;
        return;
    }
    high = table[3] + 320.0f + 140.0f;
    if (object->position < high)
        return;
    object->active = 0;
}
