/*
============================================================================
File Name : 27c.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : Write a program to execute ls -Rl by the following system calls
                c. execle
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


int main(int argc, char *argv[],char* env[])
{
    /* code */
    // we need to pass environment variables
    char *path="bin/ls";
    execle(path,path,"-Rl","example",NULL,env);
    return 0;
}
