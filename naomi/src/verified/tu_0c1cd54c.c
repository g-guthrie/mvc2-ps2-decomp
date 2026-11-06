/* Exact 0x0c1cd54c..0x0c1cd5e4: interpolate position over 90 frames and scale each coordinate. */
#include "objects.h"
extern struct Vec3_tu5_03 table_0c231e9c[];
void func_0c1cd54c(struct Actor *a)
{
 struct Vec3_tu5_03 *start=&table_0c231e9c[a->b32*2];
 struct Vec3_tu5_03 *end=(struct Vec3_tu5_03 *)((char *)&table_0c231e9c[a->b32*2]+12);
 a->f52=start->x+(end->x-start->x)*a->s28/90.0f;
 a->f56=start->y+(end->y-start->y)*a->s28/90.0f;
 a->f60=start->z+(end->z-start->z)*a->s28/90.0f;
 a->f52/=10.0f;a->f56/=10.0f;a->f60/=10.0f;
}
