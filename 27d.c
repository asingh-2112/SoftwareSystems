/*
============================================================================
File Name : 27d.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : Write a program to execute ls -Rl by the following system calls
                d. execv
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
    char *path="bin/ls";
    char *argv[]={path,"-Rl",NULL};
    execv(path,argv);
    return 0;
}
