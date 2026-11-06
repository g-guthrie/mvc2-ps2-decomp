#include "objects.h"
extern float _builtin_fabsf(float),_builtin_sqrtf(float);
extern float func_0c1ebd40(int),func_0c1ec2c0(int);
extern int func_0c1ebc70(float,float);
extern void func_0c1ee730(int),func_0c1ee580(int),func_0c1ee7f0(void *);
struct LinkedActorVec3 func_0c023414(float radius,float latitude,float longitude)
{
 float zero=0.0f;
 int lat=(int)(latitude*65536.0f/360.0f+0.5f)&65535;
 int lon;
 float radius_clat,clon,clat,slon,slat;
 struct LinkedActorVec3 result;
 if(_builtin_fabsf(latitude)==90.0f)slat=zero;else slat=func_0c1ebd40(lat);
 lon=(int)(longitude*65536.0f/360.0f+0.5f)&65535;
 if(_builtin_fabsf(longitude)==90.0f)slon=zero;else slon=func_0c1ebd40(lon);
 if(_builtin_fabsf(latitude)==180.0f)clat=zero;else clat=func_0c1ec2c0(lat);
 if(_builtin_fabsf(longitude)==180.0f)clon=zero;else clon=func_0c1ec2c0(lon);
 radius_clat=radius*clat;result.x=radius_clat*clon;result.y=radius*slat;result.z=radius_clat*slon;
 return result;
}
struct LinkedActorVec3 func_0c023500(float radius,float latitude,float longitude)
{
 return func_0c023414(radius,90.0f-latitude,longitude);
}
void func_0c02351c(struct LinkedActorVec3 *v,float *length,int *latitude,int *longitude)
{
 float horizontal=_builtin_sqrtf(*length=v->x*v->x+v->z*v->z);
 if(horizontal==0 && v->y==0)*latitude=0;else *latitude=func_0c1ebc70(horizontal,v->y);
 *length=_builtin_sqrtf(*length+v->y*v->y);
 if(v->x==0 && v->z==0)*longitude=0;else *longitude=func_0c1ebc70(v->x,v->z);
}
void func_0c0235d0(struct LinkedActorVec3 *v,float *length,register int *latitude,int *longitude)
{
 func_0c02351c(v,length,latitude,longitude);*latitude+=-16384;
}
void func_0c0235e6(struct LinkedActorVec3 *v,void *target)
{
 float length;int latitude,longitude;
 func_0c0235d0(v,&length,&latitude,&longitude);
 func_0c1ee730(longitude);func_0c1ee580(latitude);func_0c1ee7f0(target);
}
void func_0c023612(struct LinkedActorVec3 *from,struct LinkedActorVec3 *to,void *target)
{
 struct LinkedActorVec3 difference;
 difference.x=to->x-from->x;difference.y=to->y-from->y;difference.z=to->z-from->z;
 func_0c0235e6(&difference,target);
}
