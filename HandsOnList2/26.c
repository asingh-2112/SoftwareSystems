/*
============================================================================
Name : 26.c
Author : Abhishek Kumar
Description : Write a program to send messages to the message queue. Check $ipcs -q
Date: 21st September 2024
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <errno.h>

struct message_buffer {
    long message_type;
    char message_text[100];
};

int main() {
    key_t queue_key;
    int message_queue_id;
    struct message_buffer message_data;

    // Generate a unique key using ftok
    queue_key = ftok("/tmp", 'B');
    if (queue_key == -1) {
        perror("Error generating key using ftok");
        exit(EXIT_FAILURE);
    }

    // Create a message queue
    message_queue_id = msgget(queue_key, IPC_CREAT | 0666);
    if (message_queue_id == -1) {
        perror("Error creating message queue using msgget");
        exit(EXIT_FAILURE);
    }
    
    // Set message type and input message text
    message_data.message_type = 1;  
    printf("Enter message: ");
    fgets(message_data.message_text, sizeof(message_data.message_text), stdin);
    message_data.message_text[strcspn(message_data.message_text, "\n")] = '\0';  

    // Send the message to the queue
    if (msgsnd(message_queue_id, &message_data, sizeof(message_data.message_text), 0) == -1) {
        perror("Error sending message");
        exit(EXIT_FAILURE);
    }

    // Print confirmation
    printf("Message sent: %s\n", message_data.message_text);

    return 0;
}

/*$ ./ss
Enter message: hello
Message sent: hello
*/