/*
============================================================================
File Name : 8.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read. 
Close the file when end of file is reached.
============================================================================
*/

#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>


int main(int argc, char *argv[])
{
    /* code */
    int fd1=open(argv[1],O_RDONLY);
    if(fd1==-1){
        printf("Error in opening file");
    }
    char c[1024];
    int i=0;
    while(read(fd1,&c[i],1)){
        if(c[i]=='\n'){
            printf("%s",c);
            memset(c,0,i);
            i=0;
        }
        else{
            i++;
        }
    }
    close(fd1);
    return 0;
}
/*
$ ./ss8 myfile7.txt 
Hello, Display for question 8.
Hello, Display for question 8.
Hello, Display for question 8.
Hello, Display for question 8.

*/
