extern char D_004C8900[],D_004C8980[];
extern int D_004C9EC0[];
extern const char gCdDvdDiagnostic_004AB640[];
extern int func_00105E80(const char *,...);
extern int func_00106E68(void *,int,int,void *,int,void *,int,void (*)(void *),void *);
int func_00110A70(void){if(func_00106E68(D_004C8900,53,0,D_004C8980,48,D_004C9EC0,4,0,0)){func_00105E80(gCdDvdDiagnostic_004AB640);return -1;}return D_004C9EC0[0];}
