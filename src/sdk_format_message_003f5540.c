/* Format into the native shared buffer using the PS2 EABI varargs save area. */
extern char D_0062C7E0[];extern int func_00122340(char*,const char*,char*);
int func_003F5540(const char*fmt,...){
 char*ap=(char*)__builtin_next_arg(fmt)-(__builtin_args_info(2)>=8?0:(8-__builtin_args_info(2))*8);
 func_00122340(D_0062C7E0,fmt,ap);return 1;
}
