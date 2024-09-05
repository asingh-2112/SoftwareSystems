/*
============================================================================
File Name : 28.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : Write a program to get maximum and minimum real time priority.
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
    
    int max_priority,min_priority;
    //FIFO
    max_priority=sched_get_priority_max(SCHED_FIFO);
    min_priority=sched_get_priority_min(SCHED_FIFO);
    printf("Maximum priority of FIFO is %d\n",max_priority);
    printf("Minimum priority of FIFO is %d\n",min_priority);
    //RR
    max_priority=sched_get_priority_max(SCHED_RR);
    min_priority=sched_get_priority_min(SCHED_RR);
    printf("Maximum priority of RR is %d\n",max_priority);
    printf("Minimum priority of RR is %d\n",min_priority);
    //OTHERS
    min_priority=sched_get_priority_min(SCHED_OTHER);
    max_priority=sched_get_priority_max(SCHED_OTHER);
    printf("Maximum priority of OTHER is %d\n",max_priority);
    printf("Minimum priority of OTHER is %d\n",min_priority);
    return 0;
}
/*
$ ./ss
Maximum priority of FIFO is 99
Minimum priority of FIFO is 1
Maximum priority of RR is 99
Minimum priority of RR is 1
Maximum priority of OTHER is 0
Minimum priority of OTHER is 0
*/