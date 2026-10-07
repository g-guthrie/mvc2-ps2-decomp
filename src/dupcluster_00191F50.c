typedef struct { unsigned char prefix[0x38]; float y; unsigned char reserved[0x3f4]; float floor; } HeightState;
void func_00191F50(unsigned char *owner) {
 HeightState *p=(HeightState *)owner;
 if (p->y<=34.28571319580078125000f+p->floor)
  p->y=34.28571319580078125000f+p->floor;
}
