#ifndef MVC2_RUNTIME_STREAM_QUERY_H
#define MVC2_RUNTIME_STREAM_QUERY_H

/* Query/context at +0x78/+0x7C, commit/context at +0x80/+0x84. */
typedef int (*RuntimeStreamQuery)(unsigned char *, int *, int *, int *);
typedef void (*RuntimeStreamCommit)(unsigned char *, int, int);
typedef void (*StreamGroupObserver)(void *);
typedef void (*StreamGroupSpanObserver)(void *, int, int, int);
struct StreamGroup;
int func_003F7BE8(unsigned char *, int *, int *, int *);
void func_003F7C18(unsigned char *, int, int);

void func_003F80F8(unsigned char *engine, RuntimeStreamQuery query, void *context);
int func_003FF810(unsigned char *context, int *position, int *available, int *remaining);
void func_003F8108(unsigned char *engine, RuntimeStreamCommit commit, void *context);
void func_003FFF10(struct StreamGroup *, StreamGroupSpanObserver, void *);
void func_003FFF20(struct StreamGroup *, StreamGroupObserver, void *);
int func_003F81C0(void *);
int func_003F81E0(void *);
int func_003F8140(unsigned char *);
int func_003FFFA8(void *);
int func_00400038(void *);
int func_00400080(void *);

#endif
