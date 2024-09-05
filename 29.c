/*
============================================================================
File Name : 29.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO, SCHED_RR).
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


int main()
{
    
    int pid=getpid();
    printf("pid:%d\n",pid);
    int policy=sched_getscheduler(pid);
    if(policy==-1){
        printf("error\n");
    }
    else{
        switch(policy){
            case SCHED_FIFO:
                printf("Scheduling policy: FIFO\n");
                break;
            case SCHED_RR:
                printf("Scheduling policy: RR\n");
                break;
            case SCHED_OTHER:
                printf("Scheduling policy: OTHER\n");
                break;
        }
    }

    int choice;
    printf("Select to change the scheduling policy\n1.FIFO\n2.RR\n3.OTHER\n");
    scanf("%d",&choice);
    struct sched_param sched;
    sched.sched_priority=99;
    switch(choice){
        case 1:
            sched_setscheduler(pid,SCHED_FIFO,&sched);
            break;
        case 2:
            sched_setscheduler(pid,SCHED_RR,&sched);
            break;
        case 3:
            sched_setscheduler(pid,SCHED_OTHER,&sched);
            break;
    }
    pid=getpid();
    policy=sched_getscheduler(pid);
    if(policy==-1){
        printf("error\n");
    }
    else{
        switch(policy){
            case SCHED_FIFO:
                printf("After modification the scheduling policy for process id: %d has chnaged to Scheduling policy: FIFO\n",pid);
                break;
            case SCHED_RR:
                printf("After modification the scheduling policy for process id: %d has chnaged to Scheduling policy: RR\n",pid);
                break;
            case SCHED_OTHER:
                printf("After modification the scheduling policy for process id: %d has chnaged to Scheduling policy: OTHER\n",pid);
                break;
        }
    }
    return 0;
}

/*
$ ./ss
pid:11014
Scheduling policy: OTHER
Select to change the scheduling policy
1.FIFO
2.RR
3.OTHER
2
After modification the scheduling policy for process id: 11014 has chnaged to Scheduling policy: OTHER
*/