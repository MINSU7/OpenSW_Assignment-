#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

char **environ;

int main (int argc, char *argv[]){

    if (argc < 2) {
        printf("Usage: %s <program path> [OPTION...]\n", argv[0]);
        exit(1);
    }

    char **new_argv;
    int new_argc = argc - 1;
    new_argv = (char **)malloc(sizeof(char*) * (argc + 1));

    for(int i = 0; i < new_argc; i++){
        new_argv[i] = argv[i + 1];
    }

    new_argv[argc] = NULL;

    pid_t child_pid = fork();

    if(child_pid == 0){
        if (execve(argv[1], new_argv, environ) == -1) {
            perror("execve failed");
            exit(1);
        }        
    }else {
        int wstatus;
        waitpid(child_pid, &wstatus, 0);
         if(WIFEXITED(wstatus)){
            printf("Child exited with status: %d\n", WEXITSTATUS(wstatus));
        }
    }

    free(new_argv);

    return 0;

}