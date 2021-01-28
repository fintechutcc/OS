#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed.");
        return 1;
    } else if (pid == 0) {
        fprintf(stderr, "Result of Child PID %d: \n", getpid());
        execlp("/bin/ls", "ls", NULL);
    } else {
        wait(NULL);
        printf("\nParent: Child PID %d was completed.\n", pid);
    }

    return (EXIT_SUCCESS);
}

