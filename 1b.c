/*
============================================================================
File Name : 1b.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : 1.Create the following types of a files using (i) shell command (ii) system call
				b. hard link (link system call)
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main(){
	char *file1="/home/abhishek-kumar/Documents/hLink.txt";
	char *file2="/home/abhishek-kumar/Downloads/hard";

	int r=link(file1,file2);
	if(r==-1)
		printf("Not created");
	else
		printf("created");

	return 0;
}
/*
	~/Documents/SOftwareSystemsHandsheet1$ gcc -o ss1b 1b.c
	~/Documents/SOftwareSystemsHandsheet1$ ./ss1b
	created
	5534037 -rw-rw-r-- 2 abhishek-kumar abhishek-kumar     0 Aug 31 23:02  hard
	5534037 -rw-rw-r-- 2 abhishek-kumar abhishek-kumar     0 Aug 31 23:02  hLink.txt
*/
