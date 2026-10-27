/* Facing-dependent horizontal exit tests.  Negating <= retains unordered results. */
typedef unsigned char u8;
typedef signed short s16;
typedef struct {
    u8 unknown00[0x34];
    float x;
    u8 unknown38[0x108];
    s16 facing;
} HorizontalBoundsActor;
extern float D_004F1FD8;
extern float D_004F1FDC;



int func_0037BDE0(u8 *actor_data)
{
    HorizontalBoundsActor *actor = (HorizontalBoundsActor *)actor_data;
    if (actor->facing == 0) {
        if (!(D_004F1FD8 - 160.0f <= actor->x))
            return 1;
    } else {
        if (160.0f + D_004F1FDC < actor->x)
            return 1;
    }
    return 0;
}
