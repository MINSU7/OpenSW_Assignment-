#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 128

int main (int argc, char *argv[])
{
    if(argc != 1){
        printf("Usage: %s\n", argv[0]);
        exit(0);
    }

    char *readStr = (char *)malloc(sizeof(char) * BUF_SIZE);
    int read_result;

    while(1){
        read_result = read(0, readStr, BUF_SIZE);
        if(read_result == 0){
            printf("Detected EOF (Ctrl + D)\n");
            printf("Terminating read loop..\n");
            break;
        }
        write(1, readStr, BUF_SIZE);
    }

    return 0;

}