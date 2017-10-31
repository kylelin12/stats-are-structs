#include "main.h"

int main() {
    struct stat sb;
    stat("main.c", &sb);
    printf("The size of main.c is: %d bytes\n", sb.st_size);
    printf("The permissions of main.c are: %o\n", sb.st_mode);
    char *timeaccess = ctime(&sb.st_atime);
    printf("The time of last access of main.c is: %s", timeaccess);

    float size = (float)sb.st_size;
    char *units[] = {"B", "kb", "mb", "gb"};
    int counter = 0;
    while (size > 1024) {
        size /= 1024;
        counter++;
    }

    printf("Size of make.c: %f %s\n", size, units[counter]); 
}
