/*
============================================================================
Name : 27b.c
Author : Abhishek Kumar
Description : Write a program to receive messages from the message queue.
    a. with 0 as a flag
    b. with IPC_NOWAIT as a flag
Date: 21st September 2024
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

struct message_buffer {
    long message_type;
    char message_text[100];
};

int main() {
    key_t queue_key;
    int message_queue_id;
    struct message_buffer received_message;

    // Generate a unique key using ftok
    queue_key = ftok("/tmp", 'B');
    if (queue_key == -1) {
        perror("Error generating key using ftok");
        exit(EXIT_FAILURE);
    }

    // Get the message queue ID
    message_queue_id = msgget(queue_key, 0666 | IPC_CREAT);
    if (message_queue_id == -1) {
        perror("Error getting message queue ID");
        exit(EXIT_FAILURE);
    }

    // Attempt to receive a message (non-blocking)
    printf("Attempting to receive a message (non-blocking)...\n");
    if (msgrcv(message_queue_id, &received_message, sizeof(received_message.message_text), 1, IPC_NOWAIT) == -1) {
        if (errno == ENOMSG) {
            printf("No message available at the moment.\n");
        } else {
            perror("Error receiving message");
        }
        exit(EXIT_FAILURE);
    }

    // Print the received message
    printf("Received message: %s\n", received_message.message_text);

    return 0;
}

/*$ ./ss
Attempting to receive a message (non-blocking)...
Received message: hii
*/