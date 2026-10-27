/* Provisional: callback-table types and both selector bounds need proof. */
typedef unsigned char u8;typedef void (*Callback)(u8 *);
extern Callback const jtbl_00458E40[];
void func_002B1DE0(u8 *p){p[0x1fe]=1;{unsigned int row=p[0x20b]*4;unsigned int col=p[6];unsigned int index=row+col;jtbl_00458E40[index](p);}}
