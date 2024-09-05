/*
============================================================================
File Name : 17a.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : Write a program to simulate online ticket reservation. Implement write lock 
            Write a program to open a file, store a ticket number and exit.
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
    printf("Enter the ticket number \t");
    int fd1=open(argv[1],O_CREAT | O_RDWR, S_IRWXU);
    if(fd1==-1){
        printf("error in opening the file\n");
    }
    char buff[50];
    int n=read(0,buff,50);
    write(fd1,buff,n);
    printf("\nTicket number stored Successfully\n");
    return 0;
}
/*
$ ./ss file17.txt
123456
Enter the ticket number 	
Ticket number stored Successfully

$ cat file17.txt
123456
*/