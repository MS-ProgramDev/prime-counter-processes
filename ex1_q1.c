#include "my_libary_fun.h"
#include <string.h>


int main(int argc, char *argv[])
{
int count=0;
if(strcmp(argv[1],"single")==0)
  {
   int min = atoi(argv[2]);
   int max = atoi(argv[3]);
    if(min>max)
   {
   int temp=min;
   min=max;
   max=temp;
   } 
   count=count_primes_num(min,max,argv[0]);

  }
  else if(strcmp(argv[1],"child")==0)
   {
   int part= atoi(argv[2]);
   int min = atoi(argv[3]);
   int max = atoi(argv[4]);
   
  if(min>max)
  {
  int temp=min;
  min=max;
  max=temp;
  } 
   
   count=childs_mode(part,min,max,argv[0]);
   }
    else if(strcmp(argv[1],"exec")==0)
    {
    int part= atoi(argv[2]);
    int min = atoi(argv[3]);
    int max = atoi(argv[4]);
    if(min>max)
   {
   int temp=min;
   min=max;
   max=temp;
   } 
    count=exec_mode(part,min,max,argv[0]);
  }
exit(count);
}






