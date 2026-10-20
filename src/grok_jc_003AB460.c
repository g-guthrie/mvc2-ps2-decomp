typedef unsigned char u8;
extern void func_003AB430(u8 *);
void func_003AB460(u8 *p) {
 u8 *owner=*(u8 **)(p+0x18);
 u8 *other=*(u8 **)(owner+0x1dc);
 float owner_y=*(float *)(owner+0x38);
 float other_y=*(float *)(other+0x38);
 if (!(other_y<=139.28570556640625f+owner_y)) *(float *)(other+0x38)=owner_y;
 func_003AB430(p);
}
