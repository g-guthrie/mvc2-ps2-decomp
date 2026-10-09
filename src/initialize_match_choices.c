/* Clear the 32-byte workspace and set its two observed signed-halfword fields. */
typedef signed char s8;
typedef signed short s16;
extern s8 *D_004C2840;
typedef struct { s16 first; s16 second; unsigned char unknown[28]; } Workspace;
extern Workspace D_004D1800;
extern int func_00174170(void);
extern void *func_0011D8F8(void *,int,unsigned int);
void func_00170F60(void)
{
 Workspace *choices=&D_004D1800;
 func_0011D8F8(choices,0,sizeof(D_004D1800));
 D_004D1800.first=D_004C2840[0x87];
 if ((func_00174170() & 127) == 0) choices->first=0;
 if (D_004C2840[0x2e] != 0) choices->second=31;
}
