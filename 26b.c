/*
============================================================================
File Name : 26b.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : Write a program to execute an executable program.
                b. pass some input to an executable program. (for example execute an executable of $./a.out name).
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
    char *path=argv[1];
    argv++;
    execv(path,argv);
    return 0;
}
/*
 ./ss ss21 a
Parent process pid:10699
Child process pid:10700
*/