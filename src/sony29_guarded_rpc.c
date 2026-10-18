typedef unsigned int u32;
extern int D_00438318;
extern char D_004C6CC0[];
extern u32 D_004C6D00[],D_004C6D40[];
extern int func_00106E68(void *,int,int,void *,int,void *,int,void (*)(void *),void *);
u32 func_0010ACD0(u32 value){if(D_00438318<0)return 0;D_004C6D40[0]=value;if(func_00106E68(D_004C6CC0,1,0,D_004C6D40,4,D_004C6D00,4,0,0)<0)return 0;return D_004C6D00[0];}
u32 func_0010AF48(void){if(D_00438318<0)return 0;if(func_00106E68(D_004C6CC0,5,0,0,0,D_004C6D00,4,0,0)<0)return 0xFFFFFFFFu;return D_004C6D00[0];}
u32 func_0010AFB8(void){if(D_00438318<0)return 0;if(func_00106E68(D_004C6CC0,6,0,0,0,D_004C6D00,4,0,0)<0)return 0xFFFFFFFFu;return D_004C6D00[0];}
u32 func_0010B028(void){if(D_00438318<0)return 0;if(func_00106E68(D_004C6CC0,7,0,0,0,D_004C6D00,4,0,0)<0)return 0xFFFFFFFFu;return D_004C6D00[0];}
