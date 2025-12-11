#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <error.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

    sigset_t block, pending;

    sigemptyset(&block);
    sigaddset(&block, SIGINT);
    
    if(sigprocmask(SIG_BLOCK, &block, NULL) < 0){
        perror("sigprocmask");
        return 1;
    }

    printf("SIGINT blocked. Sleeping for 5 seconds...\nTry Ctrl + C during sleep.\n");

    sleep(5);

    printf("\n");
    
    if(sigpending(&pending) < 0){
        perror("sigpending");
        return 1;
    }

    if(sigismember(&pending, SIGINT))printf("SIGINT is pending\n");
    else printf("SIGINT is not pending\n");
}