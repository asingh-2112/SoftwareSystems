
/*
============================================================================
File Name : 7.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : Write a program to copy file1 into file2 ($cp file1 file2).
============================================================================
*/

#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    int fd1=open(argv[1],O_RDONLY);
    if(fd1==-1){
        printf("error in opening file");
    }
    int fd2=open(argv[2],O_WRONLY | O_CREAT,S_IRWXU);
    if(fd2==-1){
        printf("error in opening and creating file");
    }
    char cnt;
    while(read(fd1,&cnt,1)){
        write(fd2,&cnt,1);
    }
    printf("File copied successfully");
    close(fd1);
    close(fd2);
    return 0;
}
/*
$ ./ss7 myfile7.txt copytofile7.txt
File copied successfully

$ cat myfile7.txt
Hello, File for question 7.

$ cat copytofile7.txt 
Hello, File for question 7.
*/
