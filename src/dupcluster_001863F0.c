/* Clear acceleration and velocity when they share an accelerating direction. */
typedef struct { unsigned char prefix[0x5c]; float velocity; unsigned char reserved[8]; float acceleration; } MotionState;
void func_001863F0(unsigned char *owner) {
 MotionState *p=(MotionState *)owner;
 if (p->acceleration && !(p->acceleration*p->velocity<=0.0f)) {
  p->acceleration=0.0f; p->velocity=0.0f;
 }
}
