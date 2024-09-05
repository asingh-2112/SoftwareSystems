/*
============================================================================
File Name : 27e.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : Write a program to execute ls -Rl by the following system calls
                e. execvp
============================================================================
*/
#include<fcntl.h>
#include<sys/types.h>
#include<sys/resource.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>


int main()
{
    /* code */
    // it will use environment variable PATH to run executable PATH 
    char *path="ls";
    char *argv[]={path,"-Rl",NULL};
    execv(path,argv);
    return 0;
}
