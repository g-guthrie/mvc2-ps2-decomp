/* Copy the selected pair from the signed frame-indexed table. */
typedef unsigned char u8;
typedef struct Pair { float x,y; } Pair;
extern Pair D_004B3F00[];
void func_00162610(u8 *p) {
 Pair *item=D_004B3F00; int index=*(short *)(p+0x1c);
 item+=index;
 { float y=item->y;float x=item->x; *(float *)(p+0xe0)=x;*(float *)(p+0xe4)=y; }
}
