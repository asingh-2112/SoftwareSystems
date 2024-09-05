/*
============================================================================
File Name : 30.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : Write a program to run a script at a specific time using a Daemon process.
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
#include<sched.h>
#include<time.h>


int main(int argc, char *argv[])
{
    time_t start,end;
    struct tm *limit;
    time(&start);
    limit=localtime(&start);
    limit->tm_hour=atoi(argv[1]);
    limit->tm_min=argv[2]==NULL?0:atoi(argv[2]);
    limit->tm_sec=argv[3]==NULL?0:atoi(argv[3]);
    end=mktime(limit);
    int cid=fork();
    if(cid==0){
        setsid();
        do{
            time(&start);
        }while(difftime(end,start)>0);
        system("echo current user=$USER");
    }
    else{
        exit(0);
    }

}
/*
$ ./ss 0 0 10
$ current user=abhishek-kumar
*/