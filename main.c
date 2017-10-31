#include "main.h"

int main() {
    struct stat sb;
    stat("main.c", &sb);
    printf("The size of main.c is: %d bytes\n", sb.st_size);
    printf("The permissions of main.c are: %o\n", sb.st_mode);
    char *timeaccess = ctime(&sb.st_atime);
    printf("The time of last access of main.c is: %s", timeaccess);
}