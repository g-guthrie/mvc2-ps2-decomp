typedef unsigned char u8; typedef unsigned int u32; typedef unsigned long long u64;
extern u8 *func_003DBAF0(u8 *,u32,int,int);
extern void *func_003DBBD0(int *,u32);
void func_003DC120(void *data,int value) {
 u8 *p=data; func_003DBAF0(p,3,value,0);func_003DBBD0((int *)(p+16),2);
 *(u64 *)(p+0x20)=0x1000000000008001ULL;
 *(u64 *)(p+0x28)=14;*(u64 *)(p+0x30)=0;*(u64 *)(p+0x38)=63;
}
