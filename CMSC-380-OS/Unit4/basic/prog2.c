/*
    Demonstrates the use of fork, exec, and wait.
    The output of this program is mysterious. Once the problem is understood, it's easy to fix.
*/

#include <sys/types.h> // pid_t
#include <unistd.h> // fork, exexclp
#include <sys/wait.h> // wait
#include <stdlib.h> // exit
#include <stdio.h>

int main() {
    printf("Parent: I am %d.", getpid());
    fflush(stdout);

    // The parent waits for the child as it counts down from 3. When the program reaches 1 and terminates,
    // the parent then says goodbye.

    if (fork() == 0) {
        printf("\n\n\tChild: I am %d.\n", getpid());

        for (int i = 3; i > 0; i--) {
            printf("\t%d\n", i);
            sleep(1);
        }

        printf("\n\n\tChild: I am done.\n\n");
    } else {
        printf("\nParent: I am waiting for my child.\n");
        wait(NULL);
        printf("Parent: Goodbye. \n");
    }

    return 0;
}
