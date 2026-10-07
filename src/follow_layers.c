/* Follow the active parent animation and clamp the derived layer to 0..7. */
typedef unsigned char u8;
extern void (*D_004C20F8[2])(u8 *,u8 *,int,u8 *);
extern void (*D_004C2100[2])(u8 *,u8 *,int,u8 *);
extern void (*D_004C2108[2])(u8 *,u8 *,int,u8 *);
extern void (*D_004C2110[2])(u8 *,u8 *,int,u8 *);
extern void (*D_004C2118[2])(u8 *,u8 *,int,u8 *);
extern void (*D_004C2128[2])(u8 *,u8 *,int,u8 *);

#define FOLLOW_LAYER(name,handlers) \
void name(u8 *p,u8 *parent) { \
 u8 *state=parent+0x2b8; \
 int animation; \
 if (parent[5]) ++p[4]; \
 else if ((animation=parent[0x169])!=22) ++p[4]; \
 else if (!state[12]) ++p[4]; \
 else { \
  handlers[p[5]](p,parent,animation,state); \
  p[0x24]=*(signed char *)(parent+0x24)+*(signed char *)(p+0x31); \
  if (*(signed char *)(p+0x24)>7) p[0x24]=7; \
  if (*(signed char *)(p+0x24)<0) p[0x24]=0; \
 } \
}

FOLLOW_LAYER(func_003C1BD0, D_004C20F8)
FOLLOW_LAYER(func_003C2260, D_004C2100)
FOLLOW_LAYER(func_003C26D0, D_004C2108)
FOLLOW_LAYER(func_003C2A70, D_004C2110)
FOLLOW_LAYER(func_003C2E30, D_004C2118)
FOLLOW_LAYER(func_003C35B0, D_004C2128)
