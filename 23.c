/*
============================================================================
File Name : 23.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : Write a program to create a Zombie state of the running program.
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
    int pid=fork();
    if(pid==0){
        printf("Inside Child Process id:%d\t",getpid());
        printf("Parent Process id:%d\t",getppid());
        exit(0);
    }
    else{
        sleep(20);
        printf("Inside Parent Process id:%d\t",getpid());
    }
    return 0;
}
/*
$ ./ss
Inside Child Process id:7597	Parent Process id:7596	Inside Parent Process id:7596
*/