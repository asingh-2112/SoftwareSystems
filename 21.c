/*
============================================================================
File Name : 21.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : Write a program, call fork and print the parent and child process id.
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
    int p=fork();
    if(p==0){
        printf("Child process pid:%d\n",getpid());
    }
    else{
        printf("Parent process pid:%d\n",getpid());
    }
    return 0;
}
/*
$ ./ss
Parent process pid:7216
Child process pid:7217
*/