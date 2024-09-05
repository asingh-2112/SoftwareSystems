/*
============================================================================
File Name : 1a.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : 1.Create the following types of a files using (i) shell command (ii) system call
				a. soft link (symlink system call)
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main(){

	char *target="/home/abhishek-kumar/Documents/slFile.txt";
	char *pathlink="/home/abhishek-kumar/Downloads/slt";
	int r=symlink(target,pathlink);
	if(r==-1)
		printf("Not created");
	else
		printf("Created");
	return 0;
}

/*
/Documents/SOftwareSystemsHandsheet1$ ./ss1a
Soft Link Created
5516951 lrwxrwxrwx 1 abhishek-kumar abhishek-kumar 41 Aug 31 22:48 slt -> /home/abhishek-kumar/Documents/slFile.txt
*/