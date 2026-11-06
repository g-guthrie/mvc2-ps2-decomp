extern float _builtin_sqrtf(float);
#pragma section N1ebbb0
float func_0c1ebbb0(float value)
{
 if(value<0.0f){
  value=-value;
  value=_builtin_sqrtf(value);
  return -value;
 }
 value=_builtin_sqrtf(value);
 return value;
}
