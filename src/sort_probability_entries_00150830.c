#pragma padloop on
typedef struct {short priority;short value;} Entry;
void func_00150830(Entry *entries,int count) {
 int position; unsigned int limit=count-1; int pass; Entry temporary;
 for(pass=0;pass<limit;pass++) {
  for(position=0;position<limit-pass;position++) {
   if(entries[position].priority<entries[position+1].priority) {
    temporary=entries[position+1]; entries[position+1]=entries[position]; entries[position]=temporary;
   }
  }
 }
}
