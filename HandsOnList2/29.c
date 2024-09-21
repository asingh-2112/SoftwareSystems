/*
============================================================================
Name : 29.c
Author : Abhishek Kumar
Description : Write a program to remove the message queue.
Date: 21st September 2024
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
int main()
{
    // generate unique no
    key_t key = ftok(".", 1); // projext path is current directory and project id=1
    // create massage queue using msgget
    //  msgget creates a message queue
    //  and returns identifier
    int msgid = msgget(key, 0666 | IPC_CREAT);
    struct msqid_ds buf;
    //remove msg queue using flag IPC_RMID
    msgctl(msgid, IPC_RMID, &buf);
    return 0;
}

/*Before:
$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x01063878 0          abhishek-k 666        0            0           
0x42060701 1          abhishek-k 666        0            0           

After:
$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x42060701 1          abhishek-k 666        0            0           


*/