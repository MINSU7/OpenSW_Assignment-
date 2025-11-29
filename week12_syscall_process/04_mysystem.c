#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int mysystem(const char *command){

    pid_t child_pid = fork();

    if(child_pid == 0){
      execl("/bin/sh", "sh", "-c", command, NULL);
    }
    int wstatus;
    waitpid(child_pid, &wstatus, 0);

    return wstatus;
}

int main (int argc, char *argv[]){

    //system("ls -l | wc -l");
    //system("find . -name '*.c'");

    mysystem("ls -l | wc -l");
    mysystem("find . -name '*.c'");

    printf("Good bye~~~\n");

    return 0;
}