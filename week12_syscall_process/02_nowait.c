#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main (int argc, char* argv[]){

    
    pid_t child_pid = fork();

    if(child_pid == 0){
        sleep(1);
        printf("Child process PID: %lu\nChild process PPID: %lu\n"
        , (unsigned long)getpid(), (unsigned long)getppid());
    }else {
        printf("Parent process PID: %lu\nParent process PPID: %lu\n"
        , (unsigned long)getpid(), (unsigned long)getppid());
    }

    return 0;
}