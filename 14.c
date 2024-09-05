/*
============================================================================
File Name : 14.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : Write a program to find the type of a file.
            a. Input should be taken from command line.
            b. program should be able to identify any type of a file. 
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysmacros.h>
#include <fcntl.h>
#include <linux/stat.h>


int main(int argc, char *argv[])
{
    struct stat s;
    int n=stat(argv[1],&s);
    switch (s.st_mode & S_IFMT)
    {
    case S_IFBLK:
        printf("block device\n");
        break;
    case S_IFCHR:
        printf("character device\n");
        break;
    case S_IFDIR:
        printf("directory\n");
        break;
    case S_IFIFO:
        printf("FIFO/pipe\n");
        break;
    case S_IFLNK:
        printf("symlink\n");
        break;
    case S_IFREG:
        printf("regular file\n");
        break;
    case S_IFSOCK:
        printf("socket\n");
        break;
    default:
        printf("unknown?\n");
        break;
    }
    return 0;
}

/*
./ss myfile11.txt
regular file

*/
