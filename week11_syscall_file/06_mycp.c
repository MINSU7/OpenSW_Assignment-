#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#define BUF_SIZE 32

int main (int argc, char *argv[])
{
    if(argc < 3){
        printf("Usage: %s [source file] [destination file1] [destination file2] ... \n", argv[0]);
        exit(1);
    }

    int src_fd = open(argv[1], O_RDONLY);
    if(src_fd == -1){
        perror(argv[1]);
        exit(0);
    }

    int num_file = argc - 2;
    int *dest_fd_list = (int *)malloc(sizeof(int) * num_file);
    for(int i = 0; i < num_file; i++){
        *(dest_fd_list + i) = open(argv[i + 2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if(*(dest_fd_list + i) == -1){
            perror(argv[i + 2]);
        }
    }

    char *readStr = (char*)malloc(sizeof(char) * BUF_SIZE);
    int read_result;

    while(1){
        read_result = read(src_fd, readStr, BUF_SIZE);
        if(read_result == 0){
            printf("program end..\n");
            break;
        }
        else if(read_result < 0){
            perror("read");
            break;
        }
        else if(read_result > 0){
            write(1, readStr, read_result);
            for(int i = 0; i < num_file; i++){
                write(*(dest_fd_list + i), readStr, read_result);
            }
        }   
    }

    close(src_fd);

    for(int i = 0 ; i < num_file; i++){
        close(*(dest_fd_list + i));
    }

    free(readStr);
    free(dest_fd_list);
    return 0;
}