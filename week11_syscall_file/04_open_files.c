#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
    if(argc < 2){
        printf("Usage: %s <file1> [file2 ...]\n", argv[0]);
        return 1;
    }

    int fd;
    for(int i = 1 ; i < argc; i++){
        fd = open(argv[i], O_RDONLY);

        if(fd == -1){
            perror(argv[i]);
        }
        else {
            printf("%s: Open\n",argv[i]);
            close(fd);
        }
    }
    return 0;
}