/*
============================================================================
File Name : 13.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to 
            verify whether the data is available within 10 seconds or not (check in $man 2 select).
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
    struct timeval tv;
    fd_set fd;
    FD_SET(0,&fd);
    tv.tv_sec=10;
    int n=select(1,&fd,NULL,NULL,&tv);
    if(n==-1){
        printf("\nerror occured");
    }
    else if(n==0){
        printf("\nTime out");
    }
    else{
        printf("\nData entered successfully");
    }
    return 0;
}
/*
$ ./ss
Abhishek

Data entered successfully

$ ./ss

Time out
*/
