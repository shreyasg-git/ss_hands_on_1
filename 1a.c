/*
============================================================================
Name : 1b.c
Author : Shreyas Balasaheb Gangurde
Description : Create the following types of a files using (i) shell command (ii)
system call
    a. soft link (symlink system call)
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

int create_symlink(const char *filepath) {
    if (filepath == NULL) {
        fprintf(stderr, "Error: File path cannot be NULL.\n");
        return -1;
    }

    if (access(filepath, F_OK) != 0) {
        perror("Error [ORIGINAL FILE DOES NOT EXIST]");
        return -1;
    }

    size_t len = strlen(filepath) + strlen("_softlink") + 1;
    char *linkpath = malloc(len);
    if (linkpath == NULL) {
        perror("Error [MEMORY ALLOCATION]");
        return -1;
    }
    snprintf(linkpath, len, "%s_softlink", filepath);

    int ret = symlink(filepath, linkpath);
    if (ret != 0) {
        perror("Error [CREATING SYMLINK]");
        free(linkpath);
        return -1;
    }

    printf("Symlink created successfully: %s -> %s\n", linkpath, filepath);
    free(linkpath);
    return 0;
}

void main() {
    /** we first create a sample file, read it, create a symlink to it, delete
     * the original file, and then try to access the file using the symlink.
     * This gives error by-design. */

    const char *filename = "temp.md";
    create_file(filename);
    read_file(filename);

    create_symlink(filename);

    delete_file(filename);
    read_file("temp.md_softlink");
}

/*
 * === PROGRAM OUTPUT ===
 * (base) $ gcc -o _ 1a.c && ./_
 * Hello There
 * Symlink created successfully: temp.md_softlink -> temp.md
 * File 'temp.md' deleted successfully.
 * Error [OPENING FILE]: No such file or directory
 */

/*
 * === COMMAND LINE EQUIVALENT ===
 * (base) $ touch temp.md
 * (base) $ echo "Hello There" > temp.md
 * (base) $ more temp.md
 * Hello There
 * (base) $ ln -s temp.md temp_softlink.md
 * (base) $ more temp_softlink.md
 * Hello There
 * (base) $ rm temp.md
 * (base) $ more temp_softlink.md
 * more: cannot open temp_softlink.md: No such file or directory
 */

/** ======== UTILITY CODE - IRRELEVANT TO THE SCOPE OF ASSIGNMENT ============*/

// create a file and write to it.
void create_file(const char *filename) {
    FILE *fptr = fopen(filename, "w");

    if (fptr == NULL) {
        perror("Error [CREATING FILE]");
        return;
    }

    if (fprintf(fptr, "Hello There \n") < 0) {
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
