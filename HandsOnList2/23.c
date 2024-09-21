/*
============================================================================
Name : 23.c
Author : Abhishek Kumar
Description : . Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 21st September 2024
============================================================================
*/

#define _GNU_SOURCE 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

int main() {
    // Maximum number of files that can be opened within a process
    long max_files = sysconf(_SC_OPEN_MAX);
    if (max_files == -1) {
        perror("Error getting maximum number of open files");
    } else {
        printf("Maximum number of files that can be opened within a process: %ld\n", max_files);
    }

    // Create a pipe to check the size of its buffer
    int pipe_fds[2];
    if (pipe(pipe_fds) == -1) {
        perror("Error creating pipe");
        exit(EXIT_FAILURE);
    }

    // Get the pipe size
    #ifdef F_GETPIPE_SZ
    int pipe_size = fcntl(pipe_fds[0], F_GETPIPE_SZ);
    if (pipe_size == -1) {
        perror("Error getting pipe size");
        close(pipe_fds[0]);
        close(pipe_fds[1]);
        exit(EXIT_FAILURE);
    } else {
        printf("Size of the pipe (circular buffer): %d bytes\n", pipe_size);
    }
    #else
        printf("F_GETPIPE_SZ is not defined on this system. Cannot retrieve pipe buffer size.\n\n");
    #endif

    // Close the pipe file descriptors
    close(pipe_fds[0]);
    close(pipe_fds[1]);

    return 0;
}
/* ./ss
Maximum number of files that can be opened within a process: 1024
Size of the pipe (circular buffer): 65536 bytes
*/
