#ifndef MVC2_SONY29_FILEIO_DESCRIPTOR_TYPES_H
#define MVC2_SONY29_FILEIO_DESCRIPTOR_TYPES_H
typedef struct SonyFileDescriptor {
    int handle, active, word8, word12;
} SonyFileDescriptor;
typedef struct SonyFileDescriptorRequest {
    int semaphore;
    int *completion;
    int completion_size, handle, value;
} SonyFileDescriptorRequest;
typedef char SonyFileDescriptor_size[sizeof(SonyFileDescriptor)==16 ? 1 : -1];
typedef char SonyFileDescriptorRequest_size[sizeof(SonyFileDescriptorRequest)==20 ? 1 : -1];
extern SonyFileDescriptor D_004C6A00[32];
void func_00107588(void);
SonyFileDescriptor *func_001075E8(void);
SonyFileDescriptor *func_00107670(unsigned int descriptor);
#endif
