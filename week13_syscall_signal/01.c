#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void sigint_handler(int signum){
    printf("[SIGINT handler] --------\n");
    pid_t pid = fork();

    if(pid == 0){
        char *argv[] = {"/usr/bin/ls", NULL};
        execve("/usr/bin/ls", argv, NULL);
        _exit(1);
    }
    else {
        waitpid(pid, NULL, 0);
    }
}

void sigquit_handler(int signum){
    printf("[SIGQUIT handler] --------\n");
    pid_t pid = fork();

    if(pid == 0){
        char *argv[] = {"/usr/bin/date", NULL};
        execve("/usr/bin/date", argv, NULL);
        _exit(1);
    }
    else {
        waitpid(pid, NULL, 0);
    }

}

void sigalrm_handler(int signum){
    printf("[SIGALRM handler] --------\n");
    pid_t pid = fork();

    if(pid == 0){
        char *argv[] = {"/usr/bin/whoami", NULL};
        execve("/usr/bin/whoami", argv, NULL);
        _exit(1);
    }
    else {
        waitpid(pid, NULL, 0);
    }
    alarm(3);

}




int main(){

    struct sigaction sa_int;
    struct sigaction sa_quit;
    struct sigaction sa_alrm;

    sa_int.sa_handler = sigint_handler;
    sigemptyset(&sa_int.sa_mask);
    sa_int.sa_flags = 0;

    sa_quit.sa_handler = sigquit_handler;
    sigemptyset(&sa_quit.sa_mask);
    sa_quit.sa_flags = 0;

    sa_alrm.sa_handler = sigalrm_handler;
    sigemptyset(&sa_alrm.sa_mask);
    sa_alrm.sa_flags = 0;
    
    sigaction(SIGINT, &sa_int, NULL);
    sigaction(SIGQUIT, &sa_quit, NULL);
    sigaction(SIGALRM, &sa_alrm, NULL);

    alarm(3);

    while(1){
        sleep(1);
    }

}