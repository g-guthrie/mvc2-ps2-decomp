typedef unsigned int u32;
typedef float f32;

/* Three zero words, four f32 pairs (box corners, symmetric about x=0), four u32 tail words. */
typedef struct {
    u32 zero[3];
    f32 pts[4][2];
    u32 tail[4];
} Rec_00472B74;
typedef char Rec_00472B74_size_check[(sizeof(Rec_00472B74) == 60) ? 1 : -1];
Rec_00472B74 data_u32_00472B74 = { { 0x00000000u, 0x00000000u, 0x00000000u }, { { 53.3333321f, 137.142853f }, { -53.3333321f, 137.142853f }, { 53.3333321f, 205.714279f }, { -53.3333321f, 205.714279f } }, { 0x00180800u, 0x00140C10u, 0x001C0400u, 0x00000000u } };
