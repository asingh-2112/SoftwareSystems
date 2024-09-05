/*
============================================================================
File Name : 3.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
============================================================================
*/

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(){
	int fd=creat("/home/abhishek-kumar/Documents/myFiles.txt", S_IRUSR | S_IWUSR);
	if(fd==-1)
		printf("Unsuccessful");
	else
		printf("%d",fd);
	return 0;
}
/*
~/Documents/SOftwareSystemsHandsheet1$ gcc -o ss3 3.c
~/Documents/SOftwareSystemsHandsheet1$ ./ss3
File successfully created
File Descriptor is:3
*/