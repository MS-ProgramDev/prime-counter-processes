#ifndef __MY_LIBARY_FUN_H
#define __MY_LIBARY_FUN_H

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void report_primes(FILE* stream, const char* prog_name, int count, int lo, int hi);

int count_primes_num(int min, int max, const char *prog_name);

bool is_prime(int num);

int childs_mode(int part, int min, int max, const char *prog_name);

int exec_mode(int part, int min, int max, const char *prog_name);

#endif
