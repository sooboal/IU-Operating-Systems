#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
    printf("you child is a looser!\n");
    pid_t pid = fork();
    if (pid < 0) printf("fork failed\n");
    else if (pid == 0) {
        printf("(CHILD): PID: %d, PARENT: %d, fork_pid: %d\n", getpid(), getppid(), pid); // Child process
    }
    else {
        printf("PARENT: %d, fork_pid: %d\n", getpid(), pid);
    }
    return 0;
}