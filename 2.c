/*
============================================================================
Name : 2.c
Author : Shreyas Balasaheb Gangurde
Description : Write a simple program to execute in an infinite loop at the
    background. Go to /proc directory and identify all the process related
    information in the corresponding proc directory.

Date: 1st Sept, 2025.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Process started with PID: %d\n", getpid());

    while (1);
    return 0;
}

/*
 * === OBSERVATIONS ===
 * cmdline -> Command used to start the process.
 *
 * cwd -> Current working directory - a symlink to where the program was called
 * from. This is exactly how relative paths to other files are implemened. (say
 * a open() call in C).
 *
 * exe -> The executable binary (symlink to program).
 *
 * fd/ -> Directory containing file descriptors opened by the process.
 *      these are symlinks to /dev/pts/ - because u are running from terminal.
 *      u can literally do `echo "HELLO" > 0` and see the text appear
 *
 * status -> Human-readable info about process state,UID, memory usage.
 *
 * stat -> Detailed process stats (CPU time, etc.) in a
 * single line.
 *
 * environ -> Environment variables of the process.
 *
 * maps -> Memory mappings of the process.
 *
 * comm -> The process name.
 */
