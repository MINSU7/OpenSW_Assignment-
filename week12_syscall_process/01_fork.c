#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main (int argc, char* argv[]){

    
    pid_t child_pid = fork();

    if(child_pid == 0){
        printf("Child process PID: %lu\nChild process PPID: %lu\n"
        , (unsigned long)getpid(), (unsigned long)getppid());
        return 7;
    }else {
        int wstatus;
        waitpid(child_pid, &wstatus, 0);
        if(WIFEXITED(wstatus)){
            printf("Child exited with status: %d\n", WEXITSTATUS(wstatus));
        }
        printf("Parent process PID: %lu\nParent process PPID: %lu\n"
        , (unsigned long)getpid(), (unsigned long)getppid());
    }

    return 0;
}