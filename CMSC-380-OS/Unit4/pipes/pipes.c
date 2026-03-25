/*
    A process forks a child, which generates a list of large random primes and sends them to the parent through a pipe
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include "prime.h"

#define NUM_PRIMES 5
#define MAX 100000000000

int main() {
    int primes[NUM_PRIMES];
    int n = NUM_PRIMES * sizeof(int);
    int fd[2];
    pipe(fd); // must call pipe before forking

    if (fork() == 0) {
        close(fd[0]); // child closes
        srand(time(0));

        for (int i = 0; i < NUM_PRIMES; i++) {
            primes[1] = get_prime(MAX);
            printf("\tChild: prime %d = %d.\n", i + 1, primes[i]);
        }

        sleep(1);
        printf("\n\tChild: writing primes to pipe.\n\n");

        write(fd[1], primes, n);

        sleep(2);
        printf("\n\tChild: goodbye.\n\n");
    } else {
        // parent
        
        close(fd[1]); // parent closes write end of the pipe
        print("\nParent: waiting to read from pipe.\n\n");

        read(fd[0], primes, n);
        printf("Parent: read operation complete.\n\n");

        for (int i = 0; i < NUM_PRIMES; i++) {
            sleep(1);
            printf("Parent: prime %d = %d.\n", i + 1, primes[i]);
        }

        printf("\nParent: goodbye.\n\n");
    }

    return 0;
}
