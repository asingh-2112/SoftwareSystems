/*
============================================================================
File Name : 16b.c
Author : Abhishek Kumar
Roll No : MT2024005
Description :  Write a program to perform mandatory locking.
                b. Implement read lock
============================================================================
*/

#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/select.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<time.h>


int main(int argc, char *argv[])
{
    int fd1=open(argv[1],O_RDWR);
    struct flock flk;
    flk.l_type=F_RDLCK;
    flk.l_len=0;
    flk.l_pid=0;
    flk.l_start=0;
    flk.l_whence=0;
    fcntl(fd1,F_SETLK,&flk);
    printf("Read Lock creadted File locked\n");
}
/*
$ ./ss myfile11.txt
Read lock created File locked

*/