/*
============================================================================
File Name : 22.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the 
            parent processes. Check output of the file.
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

int main(int argc, char *argv[])
{
    int fd1=open(argv[1],O_CREAT | O_RDWR |O_APPEND,S_IRWXU);
    int p=fork();
    char buff[30];
    sprintf(buff,"Written by pid:%d \n",getpid());
    write(fd1,buff,sizeof(buff));
    return 0;
}
/*
$ ./ss file22.txt

$ cat file22.txt
Written by pid:7268 
Written by pid:7269
*/