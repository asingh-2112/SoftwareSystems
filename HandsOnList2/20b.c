/*
============================================================================
Name : 20b.c
Author : Abhishek Kumar
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 21st September 2024
============================================================================
*/

// reader.c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_NAME "myfifo"

int main() {
    int fd;
    char buffer[1000];

    // Open FIFO for reading
    fd = open(FIFO_NAME, O_RDONLY);
    if (fd == -1) {
        perror("open failed");
        exit(1);
    }

    // Read the message from FIFO
    read(fd, buffer, sizeof(buffer));
    printf("Reader: Received message - %s", buffer);

    // Close the FIFO
    close(fd);
    return 0;
}

/*Reader: Received message - Hello from the writer*/
