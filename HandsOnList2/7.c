/*
============================================================================
Name : 7.c
Author : Abhishek Kumar
Description : Write a simple program to print the created thread ids.
Date: 21st September 2024
============================================================================
*/


#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
void print()
{
    printf("Printing from thread :%lu\n", pthread_self());
}

void main()
{
    pthread_t threadID1, threadID2, threadID3;
    int pstatus;
    pstatus = pthread_create(&threadID1, NULL, (void *)print, NULL);
    if (pstatus != 0)
    {
        perror("Error while creating thread");
        _exit(1);
    }

    pstatus = pthread_create(&threadID2, NULL, (void *)print, NULL);
    if (pstatus != 0)
    {
        perror("Error while creating thread");
        _exit(1);
    }

    pstatus = pthread_create(&threadID2, NULL, (void *)print, NULL);
    if (pstatus != 0)
    {
        perror("Error while creating thread");
        _exit(1);
    }

    pthread_exit(NULL);
}
/*$ ./ss
Printing from thread :128260664985280
Printing from thread :128260685956800
Printing from thread :128260675471040
*/