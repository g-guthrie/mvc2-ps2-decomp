#ifndef MVC2_SONY29_FILEIO_PATH_REQUESTS_H
#define MVC2_SONY29_FILEIO_PATH_REQUESTS_H
/* The lock accepts the file-service operation number; its current native
 * body uses a common semaphore and does not inspect that argument. */
int func_00107AB8(int operation);
int func_00108F48(const char *path, int operation);
int func_00109110(const char *path, int mode);
int func_00109550(int value);
int func_00109A18(const char *path, int mode);
int func_0010A008(const char *path, int value);
int func_0010A8A0(const char *first, const char *second);
int func_001090F0(const char *path);
int func_001092C0(const char *path);
int func_00109670(const char *path);
int func_00109FE8(const char *path);
int func_0010A410(const char *path);
#endif
