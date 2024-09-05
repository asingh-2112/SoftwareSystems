/*
============================================================================
File Name : 12.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : Write a program to find out the opening mode of a file. Use fcntl.
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
    int n=fcntl(fd1,F_GETFL);
    printf("output of fcntl--%d\n",n);
    int n1=n&O_ACCMODE;
    printf("Mode --%d\n",n1);
    switch (n1)
    {
    case O_RDONLY:
        printf("MODE--O_RDONLY\n");
        break;
    
    case O_WRONLY:
        printf("MODE--O_WRONLY\n");
        break;
    
    case O_RDWR:
        printf("MODE--O_RDWR\n");
        break;
    
    default:
        printf("error\n");
        break;
    }

    return 0;
}

/*
$ ./ss myfile11.txt
output of fcntl--33794
Mode --2
MODE--O_RDWR
*/
