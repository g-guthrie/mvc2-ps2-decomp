/* jtbl_00458E40: 12 void(u8 *) handlers (src/data/jtbl_00458E40.c), a 3x4 table
   indexed by row p[0x20b] and column p[6]. */
typedef unsigned char u8;typedef void (*Callback)(u8 *);
extern Callback const jtbl_00458E40[12];
void func_002B1DE0(u8 *p){p[0x1fe]=1;{unsigned int row=p[0x20b]*4;unsigned int col=p[6];unsigned int index=row+col;jtbl_00458E40[index](p);}}
