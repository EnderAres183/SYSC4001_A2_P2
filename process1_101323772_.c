#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) { //if child, replace with process2

        execl("./process2", "process2", (char *)NULL);
        perror("execl");
        _exit(1);
    } else { //if parent
        int counter = 0;
        while (1) {
            if (counter % 3 == 0) {
                printf("Parent PID %d: Cycle number: %d - %d is a multiple of 3\n", getpid(), counter, counter);
                fflush(stdout);
            } else {
                printf("Parent PID %d: Cycle number: %d\n", getpid(), counter);
                fflush(stdout);
            }
            counter++;
            usleep(200000); // 200 ms for readability

        }
        wait(NULL);
    }

    return 0;
}