/*
============================================================================
File Name : 5.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : Write a program to create five new files with infinite loop. Execute the program in the background 
and check the file descriptor table at /proc/pid/fd.
============================================================================
*/
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
void main(int argv,char *argc[]){
	int pid=getpid();
	printf("pid:%d\n",pid);
	int f1=creat(argc[1],S_IRWXU);
	int f2=creat(argc[2],S_IRWXU);
	int f3=creat(argc[3],S_IRWXU);
	int f4=creat(argc[4],S_IRWXU);
	int f5=creat(argc[5],S_IRWXU);
	printf("f1=%d\tf2=%d\tf3=%d\tf4=%d\tf5=%d\t\n",f1,f2,f3,f4,f5);
	while(1);
}
/*
$ ./ss5
pid:7689
f1=-1	f2=-1	f3=-1	f4=3	f5=4

$ cd /proc/7689/fd
abhishek-kumar@abhishek-kumar-HP-Laptop-14s-dr2xxx:/proc/7689/fd$ ls
0  1  2  3  4

*/