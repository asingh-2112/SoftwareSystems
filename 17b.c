/*
============================================================================
File Name : 17b.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : Write a separate program, to open the file, implement write lock, read the ticket number, increment 
            the number and print the new ticket number then close the file.
============================================================================
*/

#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/select.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>


int main(int argc, char *argv[])
{
    struct flock lock={F_WRLCK,0,0,0,0};
    int fd1=open(argv[1],O_CREAT | O_RDWR, S_IRWXU);
    if(fd1==-1){
        printf("error in opening the file\n");
    }
    fcntl(fd1,F_SETLK,&lock);
    printf("File is locked\n");
    char buff[50];
    int n=read(fd1,buff,50);
    int t=atoi(buff);
    t=t+1;
    printf("New ticket number--%d\n",t);
    sprintf(buff,"%d",t);
    write(fd1,buff,strlen(buff));
    lock.l_type=F_UNLCK;
    fcntl(fd1,F_SETLK,&lock);
    return 0;
}
/*
$ cat file17.txt
123456

$ ./ss file17.txt
File is locked
New ticket number--123457
*/