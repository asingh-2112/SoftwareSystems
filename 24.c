/*
============================================================================
File Name : 24.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : Write a program to create an orphan process.
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
    if(pid>0){
        sleep(10);
        printf("Parent Process id:%d\t",getppid());
    }
    else{
        sleep(30);
        printf("Parent Process inside child id:%d\t",getppid());
        printf("Inside child Process id:%d\t",getpid());
    }
    return 0;
}
/*
$ ./ss
Parent Process id:4177   Parent Process inside child id:2460	Inside child Process id:9594
*/