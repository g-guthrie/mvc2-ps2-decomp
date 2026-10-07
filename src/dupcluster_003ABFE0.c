/* Clamp the linked opponent height before the owner follow-up. */
typedef unsigned char u8;
extern void func_003AC020(u8 *);
void func_003ABFE0(u8 *p) {
 u8 *owner=*(u8 **)(p+0x18);
 u8 *other=*(u8 **)(owner+0x1dc);
 unsigned int other_height;
 float owner_y=*(float *)(owner+0x38);
 float other_y=*(float *)(other+0x38);
 other_height=(unsigned int)other+0x38;
 if (!(other_y<=0.54408478736877441406f+owner_y)) *(float *)other_height=owner_y;
 func_003AC020(p);
}
