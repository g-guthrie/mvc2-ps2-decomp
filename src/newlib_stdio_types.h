/* Shared Newlib 1.10 stdio ABI types used by recovered routines. */
#ifndef NEWLIB_STDIO_TYPES_H
#define NEWLIB_STDIO_TYPES_H

typedef signed int s32;

typedef struct __sbuf {
    unsigned char *_base;
    int _size;
} SBuf;

typedef struct __sFILE FILE;
struct _Bigint;

/* Prefix through dtoa's verified _result_k access; this is not a full _reent. */
typedef struct _reent {
    int _errno;
    FILE *_stdin;
    FILE *_stdout;
    FILE *_stderr;
    int _inc;
    char _emergency[25];
    int _current_category;
    const char *_current_locale;
    int __sdidinit;
    void (*__cleanup)(struct _reent *);
    struct _Bigint *_result;
    int _result_k;
} Reent;

struct __sFILE {
    unsigned char *_p;
    int _r;
    int _w;
    short _flags;
    short _file;
    SBuf _bf;
    int _lbfsize;
    void *_cookie;
    int (*_read)(void *, char *, int);
    int (*_write)(void *, const char *, int);
    long long (*_seek)(void *, long long, int);
    int (*_close)(void *);
    SBuf _ub;
    unsigned char *_up;
    int _ur;
    unsigned char _ubuf[3];
    unsigned char _nbuf[1];
    SBuf _lb;
    int _blksize;
    int _offset;
    Reent *_data;
};

#endif
