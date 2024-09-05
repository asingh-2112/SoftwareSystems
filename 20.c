/*
============================================================================
File Name : 20.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : Find out the priority of your running program. Modify the priority with nice command.
============================================================================
*/

#include<fcntl.h>
#include<sys/types.h>
#include<sys/resource.h>
#include<sys/stat.h>
#include<sys/select.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>

int main()
{
    int pid=getpid();
    // printf("Enter process id:\n");
    // scanf("%d",&pid);
    printf("Nice value of process:%d\n",getpriority(PRIO_PROCESS,pid));
    printf("After modification Nice Value of process:%d\n",10+getpriority(PRIO_PROCESS,pid));
    return 0;
}
/*
$ ./ss
Nice value of process:0
After modification Nice Value of process:10
*/