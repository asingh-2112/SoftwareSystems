/*
============================================================================
Name : 21a.c
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
    int write_fd, read_fd;
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

    printf("Program A started.\n");

    // Open FIFO_A_TO_B for writing
    write_fd = open(FIFO_A_TO_B, O_WRONLY);
    if (write_fd == -1) {
        perror("Program A: Error opening FIFO_A_TO_B for writing");
        exit(EXIT_FAILURE);
    }

    // Open FIFO_B_TO_A for reading
    read_fd = open(FIFO_B_TO_A, O_RDONLY);
    if (read_fd == -1) {
        perror("Program A: Error opening FIFO_B_TO_A for reading");
        exit(EXIT_FAILURE);
    }

    printf("Connected to Program B.\n");
    printf("Type 'exit' to quit.\n");

    while (1) {
        // Get user input
        printf("Program A: Enter message: ");
        fgets(message_buffer, BUFFER_SIZE, stdin);
        message_buffer[strcspn(message_buffer, "\n")] = '\0'; // Remove newline character

        // Write the message to FIFO_A_TO_B
        if (write(write_fd, message_buffer, strlen(message_buffer) + 1) == -1) {
            perror("Program A: Error writing to FIFO_A_TO_B");
            break;
        }

        // Exit condition for Program A
        if (strcmp(message_buffer, "exit") == 0) {
            break;
        }

        // Read the message from FIFO_B_TO_A
        if (read(read_fd, message_buffer, BUFFER_SIZE) == -1) {
            perror("Program A: Error reading from FIFO_B_TO_A");
            break;
        }

        // Exit condition for Program B
        if (strcmp(message_buffer, "exit") == 0) {
            printf("Program B has exited.\n");
            break;
        }

        // Display Program B's response
        printf("Program B says: %s\n", message_buffer);
    }

    // Close file descriptors
    close(write_fd);
    close(read_fd);

    printf("Program A exiting.\n");
    return 0;
}
/*
Program A started.
Connected to Program B.
Type 'exit' to quit.
Program A: Enter message: Hello
Program B says: Hello
Program A: Enter message: 
*/