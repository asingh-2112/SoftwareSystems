
/*
============================================================================
File Name : 18a.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : Write a program to perform Record locking.
                a. Implement write lock
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
    
    int fd1=open(argv[1],O_RDWR);
    struct flock lck={F_WRLCK,SEEK_SET,0,30,getpid()};
    printf("Enter the employee id:\n");
    int eid;
    scanf("%d",&eid);
    switch (eid)
    {
    case 1:
        /* code */
        lck.l_start=0;
        lseek(fd1,0,SEEK_SET);
        break;
    case 2:
        /* code */
        lck.l_start=30;
        lseek(fd1,30,SEEK_SET);
        break;
    case 3:
        /* code */
        lck.l_start=60;
        lseek(fd1,60,SEEK_SET);
        break;
    
    default:
        printf("Wrong employee id entered\n");
        break;
    }
    fcntl(fd1,F_SETLKW,&lck);
    printf("File locked\n");
    char buff[30];
    int n=read(fd1,buff,30);
    printf("Before Modidification: %s\n",buff);
    memset(buff,0,n);
    printf("Enter the new salary number for eid:%d\n",eid);
    int t_no;
    scanf("%d",&t_no);
    sprintf(buff,"id=%d Salary=%d\n",eid,t_no);
    write(fd1,buff,sizeof(buff));
    getchar();
    lck.l_type=F_UNLCK;
    fcntl(fd1,F_SETLKW,&lck);
    printf("File unlocked\n");
    return 0;
}
