/*
============================================================================
File Name : 25.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : Write a program to create three child processes. The parent should wait for a particular child (use 
            waitpid system call).
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


int main()
{
    int cid1,cid2,cid3;
    int c=0;
    
        cid1=fork();
        if(cid1==0){
            printf("child 1 with pid:%d\n",getpid());
            sleep(2);
        }
        cid2=fork();
        if(cid2==0){
            printf("child 2 with pid:%d\n",getpid());
            sleep(4);
        }
        cid3=fork();
        if(cid3==0){
            printf("child 3 with pid:%d\n",getpid());
            sleep(6);
        }
    int id,status;
    printf("Pick child for which parent should wait from 1 to 3\n");
    scanf("%d",&id);
    waitpid(id,&status,0);
    printf("Child with pid %d has finished",id);
    return 0;
}
/*
$ ./ss
child 1 with pid:9784
child 2 with pid:9785
child 3 with pid:9786
child 2 with pid:9788
child 3 with pid:9789
child 3 with pid:9790
child 3 with pid:9791
Pick child for which parent should wait from 1 to 3
2
Child with pid 2 has finished
*/