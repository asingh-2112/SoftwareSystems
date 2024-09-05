/*
============================================================================
File Name : 6.c
Author : Abhishek Kumar
Roll No : MT2024005
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls.
============================================================================
*/

#include <unistd.h>

int main()
{
    char buff[50];
    int n=read(0,buff,50);
    write(1,buff,n);
}
/*
$ ./ss6
Hello Abhishek
Hello Abhishek

*/
