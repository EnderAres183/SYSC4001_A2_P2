#include <stdio.h>
#include <unistd.h>

int main() {
    int counter = 0;
    while (1) {
        if (counter % 3 == 0) {
            printf("Child PID %d: Cycle number: %d - %d is a multiple of 3\n", getpid(), counter, counter);
            fflush(stdout);
        } else {
            printf("Child PID %d: Cycle number: %d\n", getpid(), counter);
            fflush(stdout);
        }
        counter--;
        usleep(200000); // 200 ms
        if (counter < -500) {
            printf("Child PID %d: reached %d, exiting\n", getpid(), counter);
            break;
        }
    }
    return 0;
}