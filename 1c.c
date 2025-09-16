/*
============================================================================
Name : 1c.c
Author : Shreyas Balasaheb Gangurde
Description : Create the following types of a files using (i) shell command (ii)
system call
    c. FIFO (mkfifo Library Function or mknod system call)
Date: 1st Sept, 2025.
============================================================================
*/
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <-s | -r>\n", argv[0]);
        return 1;
    }

    char *role = argv[1];
    int fd;
    char *myfifo = "/tmp/myfifo";

    mkfifo(myfifo, 0666);

    char buf[80];

    if (strcmp(role, "-s") == 0) {
        while (1) {
            fd = open(myfifo, O_WRONLY);
            fflush(stdout);
            fgets(buf, sizeof(buf), stdin);
            write(fd, buf, strlen(buf) + 1);
            close(fd);
        }
    } else if (strcmp(role, "-r") == 0) {
        while (1) {
            fd = open(myfifo, O_RDONLY);
            read(fd, buf, sizeof(buf));
            printf("[SENDER] :: %s", buf);
            close(fd);
        }
    } else {
        printf("Invalid role. Use -s for sender or -r for receiver\n");
        return 1;
    }

    return 0;
}

/*
 * === terminal 1 ===

 * (main)$ ./_ -s
 * Enter to send >> message 1
 * Enter to send >> message 2
 * Enter to send >> message 3

 * === terminal 2 ===

 * (main)$ ./_ -r
 * [SENDER] :: message 1
 * [SENDER] :: message 2
 * [SENDER] :: message 3
*/
