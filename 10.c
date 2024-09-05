/*
============================================================================
File Name : 10.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 
            bytes (use lseek) and write again 10 bytes. 
                a. check the return value of lseek
                b. open the file with od and check the empty spaces in between the data.
============================================================================
*/

#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<time.h>


int main(int argc, char *argv[])
{
    int fd1=open(argv[1],O_CREAT | O_RDWR, S_IRWXU);

    if(fd1==-1){
        printf("Error in opening the file\n");
    }
    char c[10]="HELLOWORLD";
    write(fd1,c,10);
    int offset=lseek(fd1,10,SEEK_CUR);
    printf("return value-> %d\n",offset);
    write(fd1,c,10);
    offset = lseek(fd1, 0, SEEK_CUR);
	printf("%d\n", offset);
    return 0;
}
/*
$ ./ss myfile10.txt
return value-> 20
30

$ od -c myfile10.txt 
0000000   H   E   L   L   O   W   O   R   L   D  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   H   E   L   L   O   W   O   R   L   D
0000036

*/
