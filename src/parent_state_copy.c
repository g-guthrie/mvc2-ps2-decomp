/* Copy the parent state block and inherited fields before applying child defaults. */
typedef unsigned char u8;
typedef struct Vector3 { float x,y,z; } Vector3;
static inline void copy_words(int count,int *dst,int *src) { for (;count>0;--count) *dst++=*src++; }

#define COPY_PARENT_STATE(name) \
void name(u8 *p) { \
 copy_words(49,(int *)(p+0xec),(int *)(*(u8 **)(p+0x18)+0xec)); \
 p[0x13c]=1; \
 p[2]=(*(u8 **)(p+0x18))[2]; \
 p[1]=(*(u8 **)(p+0x18))[1]; \
 *(float *)(p+0x50)=*(float *)(*(u8 **)(p+0x18)+0x50); \
 *(float *)(p+0x54)=*(float *)(*(u8 **)(p+0x18)+0x54); \
 p[0x1b7]=(*(u8 **)(p+0x18))[0x1b7]; \
 p[0x1b8]=(*(u8 **)(p+0x18))[0x1b8]; \
 p[0x30]=*(signed char *)(*(u8 **)(p+0x18)+0x30); \
 *(Vector3 *)(p+0x50)=*(Vector3 *)(*(u8 **)(p+0x18)+0x50); \
 p[0x24]=*(signed char *)(*(u8 **)(p+0x18)+0x24); \
 p[0x14d]=32;p[0x14c]=32;p[0x14f]=36;p[0x14e]=36;p[0x24]=11; \
}

COPY_PARENT_STATE(func_00345BD0)
COPY_PARENT_STATE(func_0038E1F0)
COPY_PARENT_STATE(func_0039C3F0)
COPY_PARENT_STATE(func_003B9220)
COPY_PARENT_STATE(func_003BA140)
COPY_PARENT_STATE(func_003BD840)
