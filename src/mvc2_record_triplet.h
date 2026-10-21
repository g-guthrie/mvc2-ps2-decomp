#ifndef MVC2_RECORD_TRIPLET_H
#define MVC2_RECORD_TRIPLET_H
/* The unary adapter supplies actor, actor+D0 state, and its owner record. */
typedef void (*Mvc2RecordTriplet)(unsigned char *,unsigned char *,unsigned char *);
void func_0019FF60(unsigned char *,unsigned char *,unsigned char *);
void func_001A0010(unsigned char *,unsigned char *,unsigned char *);
void func_001A00D0(unsigned char *,unsigned char *,unsigned char *);
extern const Mvc2RecordTriplet jtbl_0044ADF0[3];
#endif
