#ifndef MVC2_SDK_FILE_TYPES_H
#define MVC2_SDK_FILE_TYPES_H

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;

typedef struct SdkFile {
    u8 *cursor;
    int readCount;
    int writeCount;
    u16 flags;
    s16 descriptor;
    u8 *buffer;
    int bufferSize;
    int lineBufferSize;
    void *cookie;
    int (*read)(void *, void *, int);
    int (*write)(void *, const void *, int);
    long long (*seek)(void *, long long, int);
    int (*close)(void *);
    u8 unknown48[32];
    int position;
    void *context;
} SdkFile;

#endif
