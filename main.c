#include "main.h"

void printlikedashl(int perms) {
    printf("Perms in octal: %o\n", perms);
    printf("Permissions of file: \t");
    printf(perms >> 6 & 0b100 ? "r" : "-");
    printf(perms >> 6 & 0b10 ? "w" : "-");
    printf(perms >> 6 & 0b1 ? "x" : "-");
    printf(perms >> 3 & 0b100 ? "r" : "-");
    printf(perms >> 3 & 0b10 ? "w" : "-");
    printf(perms >> 3 & 0b1 ? "x" : "-");
    printf(perms & 0b100 ? "r" : "-");
    printf(perms & 0b10 ? "w" : "-");
    printf(perms & 0b1 ? "x" : "-");
    printf("\n");
}

int main() {
    struct stat sb;
    stat("main.c", &sb);
    printf("The size of main.c is: %lu bytes\n", sb.st_size);
    int perms = sb.st_mode - 0100000;
    printf("The permissions of main.c are: %o\n", perms);
    char *timeaccess = ctime(&sb.st_atime);
    printf("The time of last access of main.c is: %s", timeaccess);

    float size = (float)sb.st_size;
    char *units[] = {"B", "kb", "mb", "gb"};
    int counter = 0;
    while (size > 1024) {
        size /= 1024;
        counter++;
    }

    printf("Size of make.c: %0.2f %s\n", size, units[counter]); 
    printlikedashl(perms);
}
