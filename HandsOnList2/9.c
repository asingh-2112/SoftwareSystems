/*
============================================================================
Name : 9.c
Author : Abhishek Kumar
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - Use signal system call.
Date: 21st September 2024
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
void main()
{
    __sighandler_t status;

    printf("ignoring the SIGINT signal for 5 seconds\n");
    status=signal(SIGINT, SIG_IGN);
    if (status == SIG_ERR)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        sleep(5); // SIGINT will be ingnored for 5 seconds
    }

    printf("reseting the default action of the SIGINT signal\n");
    status = signal(SIGINT, SIG_DFL);
    if (status == SIG_ERR)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        sleep(5); 
    }
}

/*$ ./ss
ignoring the SIGINT signal for 5 seconds
reseting the default action of the SIGINT signal
*/