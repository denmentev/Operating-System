/*
    Shows that an orphan is "adopted" by init (pid = 1)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "prime.h"

#define MAX 1000000000

int main() {
    pid_t pid = fork();
    
    if (pid == 0) {
        pid_t parent_pid = getppid(); // gets pid of parent
        printf("Child: My parent is %d.\n\n", parent_pid);

        // loop while my parent remains the same
        while (getppid() == parent_pid);

        printf("Child: My parent is %d.\n", getppid());

        return 0;
    }

    sleep(1);

    for (int i = 10; i <= MAX; i *= 10) {
        printf("Parent: %d is a prime.\n", get_prime(i));
    }

    printf("\n");

    printf("Parent: I am %d. Goodbye.\n\n", getpid());
    sleep(1);

    return 0;
}

