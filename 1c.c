/*
============================================================================
File Name : 1c.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : 1.Create the following types of a files using (i) shell command (ii) system call
				c. FIFO (mkfifo Library Function or mknod system call)
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(){
	char *fifofile="/home/abhishek-kumar/Documents/fifo.txt";
	if(mkfifo(fifofile,0666)==-1)
		printf("Not created");
	else
		printf("Created");
	return 0;
	}
/*
	~/Documents/SOftwareSystemsHandsheet1$ gcc -o ss1c 1c.c
	~/Documents/SOftwareSystemsHandsheet1$ ./ss1c
	Created
*/