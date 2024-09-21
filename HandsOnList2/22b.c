/*
============================================================================
Name : 22b.c
Author : Abhishek Kumar
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date: 21st September 2024
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

#define FIFO_PATH "myfifo"
#define MESSAGE_SIZE 256

int main() {
    int fifo_file;
    char message_buffer[MESSAGE_SIZE];

    // Create FIFO if it doesn't exist
    if (mkfifo(FIFO_PATH, 0666) == -1) {
        if (errno != EEXIST) {
            perror("Error creating FIFO");
            exit(EXIT_FAILURE);
        }
    }

    printf("FIFO '%s' created/opened for writing.\n", FIFO_PATH);

    // Open the FIFO for writing
    fifo_file = open(FIFO_PATH, O_WRONLY);
    if (fifo_file == -1) {
        perror("Error opening FIFO for writing");
        exit(EXIT_FAILURE);
    }

    printf("Connected to Reader. You can start sending messages.\n");
    printf("Type 'exit' to quit.\n");

    // Get input from the user
    printf("Enter message: ");
    if (fgets(message_buffer, MESSAGE_SIZE, stdin) == NULL) {
        perror("Error reading input");
    }

    // Remove newline character
    message_buffer[strcspn(message_buffer, "\n")] = '\0';

    // Write the message to the FIFO
    if (write(fifo_file, message_buffer, strlen(message_buffer) + 1) == -1) {
        perror("Error writing to FIFO");
    }

    // Exit if the user typed "exit"
    if (strcmp(message_buffer, "exit") == 0) {
        printf("Exiting Writer.\n");
    }

    // Close the FIFO file descriptor
    close(fifo_file);

    return 0;
}

/* ./ss
FIFO 'myfifo' created/opened for writing.
Connected to Reader. You can start sending messages.
Type 'exit' to quit.
Enter message: ABhi
*/
