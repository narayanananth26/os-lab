#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        printf("I am the child process. My PID is %d.\n", getpid());
        return 0;
    } else {
        printf("I am the parent process. My PID is %d, and my child's PID is %d.\n", getpid(), pid);
        return 0;
    }
}
