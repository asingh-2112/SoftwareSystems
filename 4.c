/*
============================================================================
File Name : 4.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also. 
============================================================================
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main(){
	int fd=open("/home/abhishek-kumar/Documents/SOftwareSystemsHandsheet1/myFiles.txt", O_RDWR | O_CREAT | O_EXCL, S_IRUSR);
	if(fd==-1){
		if(errno == EEXIST)
			printf("FILE ALREADY EXISTS\n");
		else
			printf("error\n");}
	else
		printf("Opened Successfully\n");

	if(close(fd)==-1)
		printf("error in closing\n");
	else
		printf("closed successfully\n");
	return 0;
}
/*
~/Documents/SOftwareSystemsHandsheet1$ ./gcc -o ss4 4.c
~/Documents/SOftwareSystemsHandsheet1$ ./ss4
Opened Successfully
closed successfully
*/