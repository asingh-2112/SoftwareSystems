/*
============================================================================
File Name : 11.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the 
            descriptors and check whether the file is updated properly or not.
                a. use dup
                b. use dup2
                c. use fcntl
============================================================================
*/

#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<time.h>


int main(int argc, char *argv[])
{
    int fd1=open(argv[1],O_CREAT |O_APPEND | O_RDWR, S_IRWXU);
    //1. using dup
    int d1=dup(fd1);
    write(fd1,"Using File descriptor of open\n",30);
    write(d1,"Using File descriptor of dup\n",29);
    //2. using dup2
    int d2=dup2(fd1,10);
    write(d2,"Using File descriptor of dup2\n",30);
    //3. using fcntl
    int d3=fcntl(fd1,F_DUPFD);
    write(d2,"Using File descriptor of fcntl\n",31);
    return 0;
}
/*
$ ./ss myfile11.txt

$ cat myfile11.txt 
Using File descriptor of open
Using File descriptor of dup
Using File descriptor of dup2
Using File descriptor of fcntl

*/