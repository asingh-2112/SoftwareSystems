/*
============================================================================
File Name : 18c.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : Write a program to perform Record locking.
                c. Create three records in a file. Whenever you access a particular record, first lock it then 
                modify/access to avoid race condition.
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
typedef struct record{
    int eid;  //employee id
    int salary;  //salary
}record;

int main(int argc, char *argv[])
{
    record r1={1,10000};
    record r2={2,20000};
    record r3={3,30000};
    int fd1=open(argv[1],O_CREAT | O_RDWR, S_IRWXU);
    char buff[30];

    //record 1
    sprintf(buff,"id=%d Salary=%d ",r1.eid,r1.salary);
    write(fd1,buff,sizeof(buff));
    memset(buff,0,sizeof(buff));

    //record 2
    sprintf(buff,"id=%d Salary=%d ",r2.eid,r2.salary);
    write(fd1,buff,sizeof(buff));
    memset(buff,0,sizeof(buff));

    // record 3
    sprintf(buff,"id=%d Salary=%d ",r3.eid,r3.salary);
    write(fd1,buff,sizeof(buff));
    memset(buff,0,sizeof(buff));
    
    return 0;
}

/*
$ ./ss file18.txt
$ cat file18.txt
id=1 Salary=10000 id=2 Salary=20000 id=3 Salary=30000 
*/
