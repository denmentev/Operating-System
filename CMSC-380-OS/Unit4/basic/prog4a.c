/*
    This demonstrates interweaved execution of parent and child. Both processes output a random prime less than 10^k for k = 5, 6, 7, 8, 9
*/

// The write function is used for unbuffered output

#include <math.h> // link with -lm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "prime.h"

int main() {
    int count = 0;
    pid_t pid = fork();
    int seed = getpid();
    char buf[50];

    if (pid < 0) {
        printf("Fork failed.");
        return 1;
    }

    srand(seed); // Only done once

    // generate a random prime up to 10^k for k = 5, 6, 7, 8, 9
    for (int k = 5; k <= 9; k++) {
        int n = pow(10, k);
        int prime = get_prime(n);

        if (pid == 0) {
            sprintf(buf, "\t%d. Child: %d\n", ++count, prime);
        } else {
            sprintf(buf, "%d. Parent: %d\n", ++count, prime);
        }

        // 1 is the file descriptor for stdout
        write(1, buf, strlen(buf));
    }

    if (pid > 0) {
        pid_t pid2 = wait(0);
    }

    return 0;
}
