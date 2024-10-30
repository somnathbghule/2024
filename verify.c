#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

    if (argc != 2){
        printf("dir name is missing: usage %s <dirname>\n", argv[0]);
    }
    const char *parentDir = argv[1];
    char dotDir[128];
    strcat(dotDir, parentDir);
    strcat(dotDir, "/.");
    printf("dot dir : %s \n", dotDir);

    return 0;
}