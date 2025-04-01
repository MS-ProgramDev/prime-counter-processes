#include "my_libary_fun.h"

int main(int argc, char *argv[])
{
if(argc!=3)
{
  printf("ERROR");
  return -1;
}
int min= atoi(argv[1]);
int max= atoi(argv[2]);

if(min>max)
{
 int temp=min;
 min=max;
 max=temp;
 printf("# note the 1st argument bigger then 2nd");
} 
int count= count_primes_num(min,max,argv[0]);
exit(count);

}
