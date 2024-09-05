
/*
============================================================================
File Name : 18b.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : Write a program to perform Record locking.
                b. Implement read lock
============================================================================
*/

#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/select.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>


int main(int argc, char *argv[])
{
    
    int fd1=open("/home/abhishek-kumar/Documents/SOftwareSystemsHandsheet1/mfile18.txt",O_RDWR);
    struct flock lck={F_RDLCK,SEEK_SET,0,30};
    printf("Enter the employee id:\n");
    int eid;
    scanf("%d",&eid);
    switch (eid)
    {
    case 1:
        /* code */
        lck.l_start=0;
        break;
    case 2:
        /* code */
        lck.l_start=30;
        break;
    case 3:
        /* code */
        lck.l_start=60;
        break;
    
    default:
        printf("Wrong employee id entered\n");
        break;
    }
    fcntl(fd1,F_SETLK,&lck);
    printf("File is locked\t enter to unlock\n");
    getchar();
    getchar();
    lck.l_type=F_UNLCK;
    fcntl(fd1,F_SETLK,&lck);
    printf("File is unlocked\n");
    return 0;
}
