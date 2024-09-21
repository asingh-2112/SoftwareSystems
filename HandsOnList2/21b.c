/*
============================================================================
Name : 21b.c
Author : Abhishek Kumar
Description : Write two programs so that both can communicate by FIFO -Use two way communications.
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

#define FIFO_A_TO_B "fifo_a_to_b"
#define FIFO_B_TO_A "fifo_b_to_a"
#define BUFFER_SIZE 256

int main() {
    int read_fd, write_fd;
    char message_buffer[BUFFER_SIZE];

    // Create FIFO_A_TO_B
    if (mkfifo(FIFO_A_TO_B, 0666) == -1 && errno != EEXIST) {
        perror("Error creating FIFO_A_TO_B");
        exit(EXIT_FAILURE);
    }

    // Create FIFO_B_TO_A
    if (mkfifo(FIFO_B_TO_A, 0666) == -1 && errno != EEXIST) {
        perror("Error creating FIFO_B_TO_A");
        exit(EXIT_FAILURE);
    }

    printf("Program B started.\n");

    // Open FIFO_A_TO_B for reading
    read_fd = open(FIFO_A_TO_B, O_RDONLY);
    if (read_fd == -1) {
        perror("Program B: Error opening FIFO_A_TO_B for reading");
        exit(EXIT_FAILURE);
    }

    // Open FIFO_B_TO_A for writing
    write_fd = open(FIFO_B_TO_A, O_WRONLY);
    if (write_fd == -1) {
        perror("Program B: Error opening FIFO_B_TO_A for writing");
        exit(EXIT_FAILURE);
    }

    printf("Connected to Program A.\n");
    printf("Type 'exit' to quit.\n");

    while (1) {
        // Read the message from Program A
        if (read(read_fd, message_buffer, BUFFER_SIZE) == -1) {
            perror("Program B: Error reading from FIFO_A_TO_B");
            break;
        }

        // Exit condition when Program A sends "exit"
        if (strcmp(message_buffer, "exit") == 0) {
            printf("Program A has exited.\n");
            break;
        }

        printf("Program A says: %s\n", message_buffer);

        // Get input from Program B
        printf("Program B: Enter message: ");
        fgets(message_buffer, BUFFER_SIZE, stdin);
        message_buffer[strcspn(message_buffer, "\n")] = '\0'; // Remove newline character

        // Send message to Program A
        if (write(write_fd, message_buffer, strlen(message_buffer) + 1) == -1) {
            perror("Program B: Error writing to FIFO_B_TO_A");
            break;
        }

        // Exit condition when Program B types "exit"
        if (strcmp(message_buffer, "exit") == 0) {
            break;
        }
    }

    // Close file descriptors
    close(write_fd);
    close(read_fd);

    printf("Program B exiting.\n");
    return 0;
}
/*$ ./ss
Program B started.
Connected to Program A.
Type 'exit' to quit.
Program A says: Hello
Program B: Enter message: Hello
*/