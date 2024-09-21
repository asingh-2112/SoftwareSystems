/*
============================================================================
Name : 20.c
Author : Abhishek Kumar
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 21st September 2024
============================================================================
*/
// writer.c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_NAME "myfifo"

int main() {
    int fd;
    char *message = "Hello from the writer!\n";

    // Create FIFO if it doesn't exist
    if (mkfifo(FIFO_NAME, 0666) == -1) {
        perror("mkfifo failed");
        exit(1);
    }

    // Open FIFO for writing
    fd = open(FIFO_NAME, O_WRONLY);
    if (fd == -1) {
        perror("open failed");
        exit(1);
    }

    // Write message to FIFO
    write(fd, message, sizeof(message));
    printf("Writer: Sent message - %s", message);

    // Close the FIFO
    close(fd);
    return 0;
}

/*
Writer: Sent message - Hello from the writer!
*/
