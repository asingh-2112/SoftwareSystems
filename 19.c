/*
============================================================================
File Name : 19.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
============================================================================
*/

#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/select.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
unsigned long long rdtsc(){
    unsigned long long tsc;
    __asm__ __volatile__("rdtsc":"=A"(tsc));
    return tsc;
}

int main(int argc, char *argv[])
{
    long long start,end;
    start=rdtsc();
    printf("Process id=%d\n",getpid());
    end=rdtsc();
    printf("Time taken for getpid() to execute is %llu",end-start);
    return 0;
}
/*
$ ./ss
Process id=6736
Time taken for getpid() to execute is 197349
*/