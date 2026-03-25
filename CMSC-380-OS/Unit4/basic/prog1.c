/*
    Demonstrates the use of fork, exec, and wait.
*/

#include <sys/types.h> // pid_t
#include <unistd.h> // fork, exexclp
#include <sys/wait.h> // wait
#include <stdlib.h> // exit
#include <stdio.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Could not fork.\n");
        exit(1);
    }

    printf("Hello from %d.\n", getpid());

    if (pid == 0) { // true for child, not for parent
        printf("\n%d is about to call exec. Farewell\n\n", getpid());
        execlp("/bin/cat", "cat", "prog1.c", NULL);
        exit(1);
    }

    wait(NULL);
    printf("\nGoodbye from %d.\n", getpid());

    return 0;
}
