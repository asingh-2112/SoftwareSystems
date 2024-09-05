/*
============================================================================
File Name : 9.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : Write a program to print the following information about a given file.
                a. inode
                b. number of hard links
                c. uid
                d. gid
                e. size
                f. block size
                g. number of blocks
                h. time of last access
                i. time of last modification
                j. time of last change
============================================================================
*/

#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<time.h>


int main(int argc, char *argv[])
{
    /* code */
    struct stat info;
    stat("mfile1.txt\n",&info);
    printf("inode--%ld\n",info.st_ino);
    printf("number of hard links--%ld\n",info.st_nlink);
    printf("uid--%d\n",info.st_uid);
    printf("gid--%d\n",info.st_gid);
    printf("size--%ld\n",info.st_size);
    printf("Block size--%ld\n",info.st_blksize);
    printf("No. of Block--%ld\n",info.st_blocks);
    printf("Time of last access--%s\n",ctime(&info.st_atime));
    printf("Time of last modification--%s\n",ctime(&info.st_mtime));
    printf("Time of last change--%s\n",ctime(&info.st_ctime));
    return 0;
}
/*
$ ./ss
inode--4849664
number of hard links--49152
uid--0
gid--9699328
size--49152
Block size--140728013505880
No. of Block--601295421446
Time of last access--Thu Jan  1 05:30:00 1970

Time of last modification--Thu Jan  1 05:30:00 1970

Time of last change--Thu Jan  1 05:30:00 1970

*/