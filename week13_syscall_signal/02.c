#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <error.h>
#include <stdio.h>
#include <stdlib.h>

struct two_double{
    double a;
    double b;
};
struct two_double data;

void sigalrm_handler(int signum){
    
    printf("%f, %f\n", data.a, data.b);
    alarm(1);
}




int main(){

    struct sigaction sa_alrm;

    struct two_double zeros = {0.0, 0.0};
    struct two_double ones = {1.0, 1.0};

    sa_alrm.sa_handler = sigalrm_handler;
    sigemptyset(&sa_alrm.sa_mask);
    sa_alrm.sa_flags = 0;
    
    if(sigaction(SIGALRM, &sa_alrm, NULL) == -1){
        perror("sigaction error: ");
        exit(0);
    }

    sigset_t block;

    sigemptyset(&block);
    sigaddset(&block, SIGALRM);

    alarm(1);

    while(1){
        
        sigprocmask(SIG_BLOCK, &block, NULL);
        data = zeros;
        sigprocmask(SIG_UNBLOCK, &block, NULL);

        sigprocmask(SIG_BLOCK, &block, NULL);
        data = ones;
        sigprocmask(SIG_UNBLOCK, &block, NULL);
    }

}