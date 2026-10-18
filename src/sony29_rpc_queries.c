extern char D_004C8380[];
extern int D_004C85C0[];
extern int func_00106E68(void *,int,int,void *,int,void *,int,void (*)(void *),void *);
int func_0010E440(void){D_004C85C0[0]=12;if(func_00106E68(D_004C8380,1,0,D_004C85C0,128,D_004C85C0,128,0,0)<0)return 0;return D_004C85C0[3];}
int func_0010E510(void){D_004C85C0[0]=18;if(func_00106E68(D_004C8380,1,0,D_004C85C0,128,D_004C85C0,128,0,0)<0)return 0;return D_004C85C0[3];}
int func_0010E4A8(int value){D_004C85C0[1]=value;D_004C85C0[0]=13;if(func_00106E68(D_004C8380,1,0,D_004C85C0,128,D_004C85C0,128,0,0)<0)return 0;return D_004C85C0[3];}
int func_0010E578(int value){D_004C85C0[1]=value;D_004C85C0[0]=20;if(func_00106E68(D_004C8380,1,0,D_004C85C0,128,D_004C85C0,128,0,0)<0)return 0;return D_004C85C0[2];}
