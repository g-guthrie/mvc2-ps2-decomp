typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
extern void func_001741D0(const float *point, float *output);
extern int fptosi(float);
int func_00174470(const void *actor_data) {
    const u8 *actor = (const u8 *)actor_data;
    float projected[2];
    float left, right, selected;
    int edge, limit;
    func_001741D0((const float *)(actor + 0x34), projected);
    left = (1.6666666269302368f * (float)(unsigned int)actor[0x14E]) * *(const float *)(actor + 0x50);
    right = (1.6666666269302368f * (float)(unsigned int)actor[0x14F]) * *(const float *)(actor + 0x50);
    if (*(const s16 *)(actor + 0x140) != 0) selected = left;
    else selected = right;
    left = 213.3333282470703125f + (left + right);
    projected[0] += 106.66666412353515625f;
    edge = (u16)fptosi(projected[0] + selected);
    limit = (u16)fptosi(640.0f + left);
    if (limit < edge) return 0;
    return 1;
}
