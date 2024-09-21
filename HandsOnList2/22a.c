/*
============================================================================
Name : 22a.c
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
#include <sys/select.h>
#include <string.h>
#include <errno.h>

#define FIFO_PATH "myfifo"
#define MESSAGE_SIZE 256
#define TIMEOUT_SEC 10

int main() {
    int fifo_file;
    char message_buffer[MESSAGE_SIZE];
    fd_set read_set;
    struct timeval timeout;
    int select_result;

    // Create the FIFO if it doesn't exist
    if (mkfifo(FIFO_PATH, 0666) == -1) {
        if (errno != EEXIST) {
            perror("Error creating FIFO");
            exit(EXIT_FAILURE);
        }
    }

    printf("FIFO '%s' created/opened for reading.\n", FIFO_PATH);
    printf("Waiting for data with a timeout of %d seconds...\n", TIMEOUT_SEC);

    // Open the FIFO in non-blocking mode for reading
    fifo_file = open(FIFO_PATH, O_RDONLY | O_NONBLOCK);
    if (fifo_file == -1) {
        perror("Error opening FIFO for reading");
        exit(EXIT_FAILURE);
    }

    // Initialize the file descriptor set and add the FIFO file descriptor
    FD_ZERO(&read_set);
    FD_SET(fifo_file, &read_set);

    // Set the timeout for select
    timeout.tv_sec = TIMEOUT_SEC;
    timeout.tv_usec = 0;

    // Wait for data to be available on the FIFO with a timeout
    select_result = select(fifo_file + 1, &read_set, NULL, NULL, &timeout);

    if (select_result == -1) {
        perror("select() error");
        close(fifo_file);
        exit(EXIT_FAILURE);
    } else if (select_result == 0) {
        printf("No data received within %d seconds. Timeout occurred.\n", TIMEOUT_SEC);
    } else {
        // Check if the FIFO file descriptor is ready for reading
        if (FD_ISSET(fifo_file, &read_set)) {
            ssize_t bytes_read = read(fifo_file, message_buffer, MESSAGE_SIZE - 1);
            if (bytes_read == -1) {
                perror("Error reading from FIFO");
                close(fifo_file);
                exit(EXIT_FAILURE);
            } else if (bytes_read == 0) {
                printf("No writers connected. Exiting.\n");
            } else {
                message_buffer[bytes_read] = '\0';
                printf("Received message: %s\n", message_buffer);
            }
        }
    }

    // Close the FIFO file descriptor
    close(fifo_file);

    printf("Reader program exiting.\n");
    return 0;
}
/*$ ./ss
FIFO 'myfifo' created/opened for reading.
Waiting for data with a timeout of 10 seconds...
Received message: ABhi
Reader program exiting.
*/
