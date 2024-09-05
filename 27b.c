/*
============================================================================
File Name : 27b.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : Write a program to execute ls -Rl by the following system calls
                b. execlp
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


int main(int argc, char *argv[])
{
    /* code */
    // it will use environment variable PATH to run executable PATH .
    // it does not required entire file path as we did in execl().
    char *path="ls";
    execlp(path,path,"-Rl",NULL);
    return 0;
}
/*
$ ./ss
.:
total 336
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar  1272 Sep  1 20:42  10.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar  1259 Sep  1 20:44  11.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar  1053 Sep  1 20:44  12.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar  1001 Sep  1 20:46  13.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar  1277 Sep  1 20:48  14.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar  4250 Sep  1 20:49  15.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar   803 Sep  1 20:50  16a.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar   805 Sep  1 20:51  16b.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar  1002 Sep  6 00:50  17a.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar  1195 Sep  6 00:52  17b.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar  1588 Sep  6 01:17  18a.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar  1286 Sep  6 01:01  18b.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar  1425 Sep  6 01:01  18c.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar   919 Sep  6 01:22  19.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar   816 Sep  1 19:58  1a.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar   896 Sep  1 19:58  1b.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar   748 Sep  1 19:59  1c.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar   884 Sep  6 01:24  20.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar   753 Sep  6 01:27  21.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar   913 Sep  6 01:29  22.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar   887 Sep  6 01:43  23.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar   884 Sep  6 01:45  24.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar  1462 Sep  6 01:48  25.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar   697 Sep  6 01:55  26a.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar   794 Sep  6 01:58  26b.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar   651 Aug 31 19:58  27a.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar   785 Aug 31 19:59  27b.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar   723 Aug 31 19:59  27c.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar   638 Aug 31 20:00  27d.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar   719 Aug 31 20:00  27e.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar  1282 Aug 31 20:01  28.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar  2257 Aug 31 20:01  29.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar  2129 Sep  1 19:59  2.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar  1026 Aug 31 20:01  30.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar   734 Sep  1 19:59  3.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar   971 Sep  1 20:06  4.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar   955 Sep  1 20:13  5.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar   481 Sep  1 20:15  6.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar   991 Sep  1 20:19  7.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar  1052 Sep  1 20:38  8.c
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar  1680 Sep  1 20:39  9.c
-rwx------ 1 abhishek-kumar abhishek-kumar     0 Sep  1 20:11 'COLORTERM=truecolor'
-rwx------ 1 abhishek-kumar abhishek-kumar    27 Sep  1 20:17  copytofile7.txt
-rwx------ 1 abhishek-kumar abhishek-kumar     1 Sep  6 00:51  file17b.txt
-rwx------ 1 abhishek-kumar abhishek-kumar    13 Sep  6 00:51  file17.txt
-rwx------ 1 abhishek-kumar abhishek-kumar    90 Sep  6 01:03  file18.txt
-rwx------ 1 abhishek-kumar abhishek-kumar    60 Sep  6 01:28  file22.txt
-rwx------ 1 abhishek-kumar abhishek-kumar    90 Sep  6 01:19  mfile18.txt
-rwx------ 1 abhishek-kumar abhishek-kumar    30 Sep  1 20:40  myfile10.txt
-rwx------ 1 abhishek-kumar abhishek-kumar    12 Sep  1 20:50  myfile11.txt
-rw-rw-r-- 1 abhishek-kumar abhishek-kumar   124 Sep  1 20:37  myfile7.txt
-rwx------ 1 abhishek-kumar abhishek-kumar     5 Sep  1 20:54  myfile.txt
-rwx------ 1 abhishek-kumar abhishek-kumar     0 Sep  1 20:11 'QT_ACCESSIBILITY=1'
-rwxrwxr-x 1 abhishek-kumar abhishek-kumar 16168 Sep  1 20:21  run
-rwxrwxr-x 1 abhishek-kumar abhishek-kumar 15952 Sep  6 01:58  ss
-rwxrwxr-x 1 abhishek-kumar abhishek-kumar 16032 Sep  6 01:55  ss21
-rwxrwxr-x 1 abhishek-kumar abhishek-kumar 16264 Sep  6 01:53  ss25
-rwxrwxr-x 1 abhishek-kumar abhishek-kumar 16032 Sep  1 20:11  ss5
-rwxrwxr-x 1 abhishek-kumar abhishek-kumar 16040 Sep  1 20:14  ss6
-rwxrwxr-x 1 abhishek-kumar abhishek-kumar 16168 Sep  1 20:16  ss7
-rwxrwxr-x 1 abhishek-kumar abhishek-kumar 16168 Sep  1 20:37  ss8
*/