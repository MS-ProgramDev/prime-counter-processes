
#include "my_libary_fun.h"

void report_primes(FILE* stream, const char* prog_name, int count, int lo, int hi)
{
fprintf(stream, "program %s found %d prime numbers in the range "
"%d - %d. (pid=%d)\n", prog_name, count, lo, hi, getpid());
}

bool is_prime(int num)
{
if(num<=1)
  return false;
int limit = sqrt(num);
for(int i=2; i<=limit;i++)
  {
    if(num%i==0)
      return false;
  }
  return true;
}


int count_primes_num(int min, int max, const char *prog_name)
{
int count=0;
for (int i=min; i<=max;i++)
{
  if(is_prime(i))
    count++;
}
report_primes(stdout, prog_name, count, min, max);
return count;
}


int childs_mode(int part, int min, int max, const char *prog_name)
{
int count=0;
int num_child= (max-min+1)/part;
int remainder= (max-min+1)%part;
if(remainder>0)
num_child+=1;
pid_t pids[num_child];

for(int i=0; i<num_child;i++)
{
  int range_min=min + i*part;
  int range_max=range_min+part -1;
  if(range_max>max)
    range_max=max;  

  pids[i]=fork();  
  if(pids[i]==0) //child
    exit(count_primes_num(range_min,range_max,prog_name));

}

for(int i=0;i<num_child;i++)
{
  int status_child;
  waitpid(pids[i], &status_child,0);
  count+=WEXITSTATUS(status_child);
}
report_primes(stdout, prog_name, count, min, max);
return count;
}


int exec_mode(int part, int min, int max, const char *prog_name)
{
int count=0;
int num_child= (max-min+1)/part;
int remainder= (max-min+1)%part;
if(remainder>0)
num_child+=1;
pid_t pids[num_child];
char range_min_str[16], range_max_str[16];
for(int i=0; i<num_child;i++)
{
  int range_min=min + i*part;
  int range_max=range_min+part -1;
  if(range_max>max)
    range_max=max;  
  sprintf(range_min_str, "%d", range_min);
  sprintf(range_max_str, "%d", range_max);  
  char *args[]={"./count_primes", range_min_str,range_max_str,NULL};
  pids[i]=fork();  
 
  if(pids[i]==0) //child
{    
    execv(args[0],args);
    perror("execv failed");
    exit(1);
}

}
for(int i=0;i<num_child;i++)
{
  int status_child;
  waitpid(pids[i], &status_child,0);
  count+=WEXITSTATUS(status_child);
}
report_primes(stdout, prog_name, count, min, max);
return count;
}
