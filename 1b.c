/*
============================================================================
Name : 1b.c
Author : Shreyas Balasaheb Gangurde
Description : Create the following types of a files using (i) shell command (ii)
system call
    b. hard link (link system call)
Date: 1st Sept, 2025.
============================================================================
*/

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void create_file(const char *filename);
int delete_file(const char *filename);
void read_file(const char *filename);

int create_hardlink(const char *filename) {
    if (filename == NULL) {
        fprintf(stderr, "Error: File path cannot be NULL.\n");
        return -1;
    }

    if (access(filename, F_OK) != 0) {
        perror("Error [ORIGINAL FILE DOES NOT EXIST]");
        return -1;
    }

    size_t len = strlen(filename) + strlen("_hardlink") + 1;
    char *linkpath = malloc(len);
    if (linkpath == NULL) {
        perror("Error [MEMORY ALLOCATION]");
        return -1;
    }
    snprintf(linkpath, len, "%s_hardlink", filename);

    if (access(linkpath, F_OK) == 0) {
        fprintf(stderr, "Error: Hardlink '%s' already exists.\n", linkpath);
        free(linkpath);
        return -1;
    }

    int ret = link(filename, linkpath);
    if (ret != 0) {
        perror("Error [CREATING HARDLINK]");
        free(linkpath);
        return -1;
    }

    printf("Hardlink created successfully: %s -> %s\n", linkpath, filename);
    free(linkpath);
    return 0;
}

void main() {
    /** we first create a sample file, read it, create a hard to it, delete
     * the original file, and then try to access the file using the hardlink.
     * This does not give error */

    const char *filename = "temp.md";
    create_file(filename);
    read_file(filename);

    create_hardlink(filename);

    delete_file(filename);
    read_file("temp.md_hardlink");
}

/*
 * === PROGRAM OUTPUT ===
 * (base) $ gcc -o _ 1b.c && ./_
 * Hello There
 * Hardlink created successfully: temp.md_hardlink -> temp.md
 * File 'temp.md' deleted successfully.
 * Hello There
 */

/*
 * === COMMAND LINE EQUIVALENT ===
 * (base) $ touch temp.md
 * (base) $ echo "Hello There" > temp.md
 * (base) $ more temp.md
 * Hello There
 * (base) $ ln temp.md temp_hardlink.md
 * (base) $ more temp_hardlink.md
 * Hello There
 * (base) $ rm temp.md
 * (base) $ more temp_hardlink.md
 * Hello There
 */
/** UTILITY CODE - IRRELEVANT TO THE SCOPE OF ASSIGNMENT */

// create a file and write to it.
void create_file(const char *filename) {
    FILE *fptr = fopen(filename, "w");

    if (fptr == NULL) {
        perror("Error [CREATING FILE]");
        return;
    }

    if (fprintf(fptr, "Hello There") < 0) {
        perror("Error [WRITING TO FILE]");
        fclose(fptr);
        return;
    }

    if (fclose(fptr) == EOF) {
        perror("Error [CLOSING FILE]");
    }
}

int delete_file(const char *filename) {
    if (filename == NULL) {
        fprintf(stderr, "Error: Filename cannot be NULL.\n");
        return -1;
    }

    if (remove(filename) == 0) {
        printf("File '%s' deleted successfully.\n", filename);
        return 0;
    } else {
        perror("Error [DELETING FILE]");
        return -1;
    }
}

void read_file(const char *filename) {
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) {
        perror("Error [OPENING FILE]");
        return;
    }

    char myString[100];

    if (fgets(myString, sizeof(myString), fptr) == NULL) {
        if (ferror(fptr)) {
            perror("Error [READING FILE]");
        } else {
            fprintf(stderr, "Warning: File is empty or no data .\n");
        }
        fclose(fptr);
        return;
    }

    printf("%s", myString);

    if (fclose(fptr) == EOF) {
        perror("Error [CLOSING FILE]");
    }
}
