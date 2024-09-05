/*
============================================================================
File Name : 26a.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : Write a program to execute an executable program.
                a. use some executable program.
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
    execv(argv[1],&argv[1]);
    return 0;
}
/*
$ ./ss ss21
Parent process pid:10539
Child process pid:10540
*/