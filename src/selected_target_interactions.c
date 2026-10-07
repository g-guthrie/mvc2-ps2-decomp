/* Start the accepted interaction using the selected live target. */
typedef unsigned char u8;
extern int func_00189310(u8 *,void *,u8 *);
extern void func_00185640(u8 *,u8 *);
extern u8 D_0044F660[];
extern u8 *func_001E7FD0(u8 *);
int func_001EE750(u8 *p) {
 u8 *target;
 if (!func_00189310(p,D_0044F660,p+0x3C8)) return 0;
 target=func_001E7FD0(p);
 if (!target) return 0;
 p[0x20b]=0xC9; func_00185640(p,target);
 return 1;
}
extern u8 D_00450AC0[];
extern u8 *func_001E7FD0(u8 *);
int func_00210870(u8 *p) {
 u8 *target;
 if (!func_00189310(p,D_00450AC0,p+0x3B8)) return 0;
 target=func_001E7FD0(p);
 if (!target) return 0;
 p[0x20b]=0x43; func_00185640(p,target);
 return 1;
}
extern u8 D_00457D30[];
extern u8 *func_001E7FD0(u8 *);
int func_00295140(u8 *p) {
 u8 *target;
 if (!func_00189310(p,D_00457D30,p+0x3D8)) return 0;
 target=func_001E7FD0(p);
 if (!target) return 0;
 p[0x20b]=0xC4; func_00185640(p,target);
 return 1;
}
