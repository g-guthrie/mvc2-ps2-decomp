#ifndef OWNER_EDGE_MOTION_H
#define OWNER_EDGE_MOTION_H
/* The update body defines these two native record views. */
typedef struct P1D3 P1D3;
typedef struct Q1D3 Q1D3;
typedef void (*OwnerEdgeMotionCallback)(P1D3 *,Q1D3 *);
void func_001D2F80(P1D3 *,Q1D3 *);
void func_001D30B0(P1D3 *,Q1D3 *);
#endif
