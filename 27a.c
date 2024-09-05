/*
============================================================================
File Name : 27a.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : Write a program to execute ls -Rl by the following system calls
                a. execl
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


int main(int argc, char *argv[])
{
    /* code */
    char *path="bin/ls";
    execl(path,"ls","-Rl",NULL);
    return 0;
}
